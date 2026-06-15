#include "map.h"

char *read_line(FILE *file)
{
    char *line = NULL;
    size_t size = 0;
    ssize_t read;

    read = getline(&line, &size, file);
    if (read == -1)
    {
        free(line);
        return NULL; // error in reading the line
    }
    return line; // return the line read from the file
}

int allocate_grid(char ***grid, int rows, int cols)
{
    int i;

    *grid = (char **)malloc((rows + 1) * sizeof(char *));
    if (*grid == NULL)
        return 1;
    
    i = 0;
    while (i < rows)
    {
        (*grid)[i] = (char *)malloc((cols + 1) * sizeof(char));
        if ((*grid)[i] == NULL)
        {
            while (i > 0)
            {
                free((*grid)[i - 1]);
                i--;
            }
            free(*grid);
            *grid = NULL;
            return 1;
        }
        i++;
    }
    (*grid)[rows] = NULL;

    return 0;
}

int min3(int a, int b, int c)
{
    if (a < b)
    {
        if (a < c)
            return a;
        else
            return c;
    }
    else
    {
        if (b < c)
            return b;
        else
            return c;
    }
}

void free_grid(t_map *map)
{
    int i;

    if (map->grid != NULL)
    {
        i = 0;
        while (i < map->num_lines)
        {
            free(map->grid[i]);
            i++;
        }
        free(map->grid);
        map->grid = NULL;
    }
}
