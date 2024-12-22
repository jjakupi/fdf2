#include "includes/fdf.h"

int get_color(int z, int z_min, int z_max) {
    double ratio = (z - z_min) / (double)(z_max - z_min);
    int red = (int)(255 * ratio);
    int green = (int)(255 * (1 - ratio));
    int blue = 128; // Keep blue constant for a cool tone

    return (red << 16) | (green << 8) | blue; // Combine RGB into a single hex color
}

void put_pixel(int x, int y, int color, char *img_data, int line_length, int bpp) {
    if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT) {
        char *pixel = img_data + (y * line_length + x * (bpp / 8));
        *(unsigned int *)pixel = color;
    }
}


void bresenham_to_image(Point3D *a, Point3D *b, char *img_data, int line_length, int bpp) {
    int dx = abs(b->x - a->x);
    int dy = abs(b->y - a->y);
    int sx = a->x < b->x ? 1 : -1;
    int sy = a->y < b->y ? 1 : -1;
    int err = dx - dy;

    while (1) {
        put_pixel(a->x, a->y, a->color, img_data, line_length, bpp);
        if (a->x == b->x && a->y == b->y)
            break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            a->x += sx;
        }
        if (e2 < dx) {
            err += dx;
            a->y += sy;
        }
    }
}

void draw_grid_lines_to_image(Point2D **projected_points, char *img_data, int line_length, int bpp, int rows, int cols, int z_min, int z_max) {
    Point3D a, b;

    int y = 0;
    while (y < rows) {
        int x = 0;
        while (x < cols) {
            // Horizontal lines
            if (x < cols - 1) {
                a.x = projected_points[y][x].x;
                a.y = projected_points[y][x].y;
                a.color = get_color(y, z_min, z_max);
                b.x = projected_points[y][x + 1].x;
                b.y = projected_points[y][x + 1].y;
                b.color = get_color(y, z_min, z_max);
                bresenham_to_image(&a, &b, img_data, line_length, bpp);
            }

            // Vertical lines
            if (y < rows - 1) {
                a.x = projected_points[y][x].x;
                a.y = projected_points[y][x].y;
                a.color = get_color(y, z_min, z_max);
                b.x = projected_points[y + 1][x].x;
                b.y = projected_points[y + 1][x].y;
                b.color = get_color(y, z_min, z_max);
                bresenham_to_image(&a, &b, img_data, line_length, bpp);
            }

            x++;
        }
        y++;
    }
}
