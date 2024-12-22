#include "includes/fdf.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        ft_printf("Usage: %s <map_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    t_fdf fdf = {0};
    // Inicializimi i strukturës me 0
    ft_memset(&fdf, 0, sizeof(t_fdf));
    // Initialize MiniLibX and image
    fdf.mlx_ptr = mlx_init();
    if (!fdf.mlx_ptr)
        handle_error("Failed to initialize MiniLibX");

    fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
    if (!fdf.win_ptr)
        handle_error("Failed to create window");

    fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    if (!fdf.img_ptr)
        handle_error("Failed to create image");

    fdf.img_data = mlx_get_data_addr(fdf.img_ptr, &fdf.bpp, &fdf.line_length, &fdf.endian);

    // Load the map and calculate z_min and z_max
    generate_grid_points_from_file(argv[1], &fdf.points, &fdf.rows, &fdf.cols, &fdf.z_min, &fdf.z_max);

    // Llogarit scale-in dinamikisht që harta të përshtatet në dritare
    double scale_x = (WIN_WIDTH * 0.5) / fdf.cols;
    double scale_y = (WIN_HEIGHT * 0.5) / fdf.rows;
    fdf.scale = ((scale_x < scale_y) ? scale_x : scale_y) * 0.5;

    // Vendos harten në qendër të dritares
    fdf.x_offset = (WIN_WIDTH / 2) - ((fdf.cols / 2.0) * fdf.scale);
    fdf.y_offset = (WIN_HEIGHT / 2) - ((fdf.rows / 2.0) * fdf.scale);

    // Allocate memory for the projected points (me while në vend të for)
    fdf.projected = malloc(fdf.rows * sizeof(Point2D *));
    if (!fdf.projected)
        handle_error("Failed to allocate memory for projected points");
    int i = 0;
    while (i < fdf.rows) {
        fdf.projected[i] = malloc(fdf.cols * sizeof(Point2D));
        i++;
    }

    // Draw the initial frame
    refresh_window(&fdf);

    // Register event hooks
    mlx_hook(fdf.win_ptr, 17, 0, close_window, &fdf); // Handle window close event
    mlx_hook(fdf.win_ptr, 2, 1L<<0, handle_keypress, &fdf);

    mlx_loop(fdf.mlx_ptr);

    return 0;
}
