#include "includes/fdf.h"

void handle_error(const char *message) {
    ft_printf("Error: %s\n", message);
    exit(EXIT_FAILURE);
}
// Close the window and free resources
int close_window(t_fdf *fdf) {
    mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
    exit(0);
    return 0;
}

int handle_keypress(int keycode, t_fdf *fdf) {
    ft_printf("Key pressed: %d\n", keycode);
    if (keycode == 65307) // ESC
        close_window(fdf);
    return 0;
}

// Function to refresh and redraw the window
void refresh_window(t_fdf *fdf) {
    // Clear the window and the image
    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    memset(fdf->img_data, 0, WIN_HEIGHT * fdf->line_length);

    // Apply isometric projection and redraw
    apply_isometric_projection(fdf->points, fdf->projected, fdf->rows, fdf->cols, fdf);
    draw_grid_lines_to_image(fdf->projected, fdf->img_data, fdf->line_length, fdf->bpp, fdf->rows, fdf->cols, fdf->z_min, fdf->z_max);

    // Display the updated image
    mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}
