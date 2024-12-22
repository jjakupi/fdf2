#include "includes/fdf.h"

void apply_isometric_projection(Point3D **points, Point2D **projected, int rows, int cols, t_fdf *fdf) {
    double center_x = (cols - 1) / 2.0; // Map center on X-axis
    double center_y = (rows - 1) / 2.0; // Map center on Y-axis

    int y = 0;
    while (y < rows) {
        int x = 0;
        while (x < cols) {
            // Center the points around (0, 0) before transformation
            double px = points[y][x].x - center_x;
            double py = points[y][x].y - center_y;
            double pz = points[y][x].z;

            // Apply isometric projection (without rotation)
            projected[y][x].x = (px - py) * cos(0.523599) * fdf->scale + fdf->x_offset;
            projected[y][x].y = (px + py) * sin(0.523599) * fdf->scale - pz * fdf->scale + fdf->y_offset;

            x++;
        }
        y++;
    }
}

void apply_wave_effect(Point3D **grid, int rows, int cols, double amplitude, double frequency) {
    int y = 0;
    while (y < rows) {
        int x = 0;
        while (x < cols) {
            grid[y][x].z += (int)(amplitude * sin(frequency * (x + y)));
            x++;
        }
        y++;
    }
}
