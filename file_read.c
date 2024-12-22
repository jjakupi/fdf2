#include "includes/fdf.h"

void generate_grid_points_from_file(const char *filename, Point3D ***grid, int *rows, int *cols, int *z_min, int *z_max) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        handle_error("Unable to open file");
    }

    char *line;
    int current_row = 0;
    *rows = 0;
    *cols = 0;
    *z_min = INT_MAX;
    *z_max = INT_MIN;

    // Determine the dimensions in a single pass
    while ((line = get_next_line(fd)) != NULL) {
        if (*rows == 0) {
            char **tokens = ft_split(line, ' ');
            int i = 0;
            while (tokens[i]) {
                (*cols)++;
                free(tokens[i]);
                i++;
            }
            free(tokens);
            // Heqim alokimin e panevojshëm këtu
        }
        (*rows)++;
        free(line);
    }
    close(fd);

    // Allocate memory for the grid pasi kemi tashmë *rows dhe *cols
    *grid = malloc((*rows) * sizeof(Point3D *));
    if (!*grid)
        handle_error("Memory allocation failed for grid rows");

    int i = 0;
    while (i < *rows) {
        (*grid)[i] = malloc((*cols) * sizeof(Point3D));
        if (!(*grid)[i])
            handle_error("Memory allocation failed for grid columns");
        i++;
    }

    // Populate the grid and calculate z_min/z_max
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        handle_error("Unable to reopen file");

    while ((line = get_next_line(fd)) != NULL) {
        char **tokens = ft_split(line, ' ');
        int x = 0;
        while (x < *cols && tokens[x]) {
            (*grid)[current_row][x].x = x;
            (*grid)[current_row][x].y = current_row;
            (*grid)[current_row][x].z = ft_atoi(tokens[x]);

            if ((*grid)[current_row][x].z < *z_min) *z_min = (*grid)[current_row][x].z;
            if ((*grid)[current_row][x].z > *z_max) *z_max = (*grid)[current_row][x].z;

            free(tokens[x]);
            x++;
        }
        free(tokens);
        free(line);
        current_row++;
    }
    close(fd);
}
