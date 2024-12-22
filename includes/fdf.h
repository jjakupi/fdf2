#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
#include <limits.h>

// Window dimensions
# define WIN_WIDTH 1720
# define WIN_HEIGHT 1000

// Struct for 3D points
typedef struct {
    int x;
    int y;
    int z;
    int color; // For storing the color
} Point3D;

// Struct for 2D projected points
typedef struct {
    int x;
    int y;
    int color;
} Point2D;

typedef struct {
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *img_data;
    int bpp;
    int line_length;
    int endian;

    // Grid information
    Point3D **points;
    Point2D **projected;
    int rows;
    int cols;
    int z_min;
    int z_max;

    // Transformations
    double scale;
    int x_offset;
    int y_offset;
} t_fdf;

// Function Prototypes
void put_pixel(int x, int y, int color, char *img_data, int line_length, int bpp);
void bresenham_to_image(Point3D *a, Point3D *b, char *img_data, int line_length, int bpp);
void generate_grid_points_from_file(const char *filename, Point3D ***grid, int *rows, int *cols, int *z_min, int *z_max);
void apply_isometric_projection(Point3D **points, Point2D **projected, int rows, int cols, t_fdf *fdf);
void draw_grid_lines_to_image(Point2D **projected_points, char *img_data, int line_length, int bpp, int rows, int cols, int z_min, int z_max);
int get_color(int z, int z_min, int z_max);
void apply_wave_effect(Point3D **grid, int rows, int cols, double amplitude, double frequency);
int handle_keypress(int keycode, t_fdf *fdf);
int close_window(t_fdf *fdf);
void refresh_window(t_fdf *fdf);
void handle_error(const char *message);

#endif


