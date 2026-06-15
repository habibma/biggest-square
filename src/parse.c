#include "../include/map.h"

static int trim_newline(char *line, int *len)
{
    if (*len <= 0 || line[*len - 1] != '\n')
        return 1;
    line[*len - 1] = '\0';
    (*len)--;
    return 0;
}

static int store_line(t_map *map, int row, char *line)
{
    int i;
    int len;

    len = strlen(line);
    if (trim_newline(line, &len))
        return 1;
    if (len != map->num_cols)
        return 1;
    i = 0;
    while (i < map->num_cols)
    {
        map->grid[row][i] = line[i];
        i++;
    }
    map->grid[row][i] = '\0';
    return 0;
}

int parse_first_line(t_map *map, FILE *file)
{
    char *line;
    int len;
    int i;

    line = read_line(file);
    if (line == NULL)
        return 1;

    len = strlen(line);
    if (trim_newline(line, &len) || len < 4)
    {
        free(line);
        return 1;
    }

    map->full_char = line[len - 1];
    map->obstacle_char = line[len - 2];
    map->empty_char = line[len - 3];
    if (map->empty_char == map->obstacle_char || map->empty_char == map->full_char
        || map->obstacle_char == map->full_char)
    {
        free(line);
        return 1;
    }

    map->num_lines = 0;
    i = 0;
    while (i < len - 3)
    {
        if (line[i] < '0' || line[i] > '9')
        {
            free(line);
            return 1;
        }
        map->num_lines = map->num_lines * 10 + (line[i] - '0');
        i++;
    }
    if (map->num_lines <= 0)
    {
        free(line);
        return 1;
    }

    free(line);
    return 0;
}

int allocate_map(t_map *map)
{
	return allocate_grid(&map->grid, map->num_lines, map->num_cols);
}

int parse_grid_data(t_map *map, FILE *file, char *first_line)
{
    char *line;
    int i;

    if (store_line(map, 0, first_line))
    {
        free(first_line);
        return 1;
    }
    free(first_line);

    i = 1;
    while (i < map->num_lines)
    {
        line = read_line(file);
        if (line == NULL)
            return 1;
        if (store_line(map, i, line))
        {
            free(line);
            return 1;
        }
        free(line);
        i++;
    }
    return 0;
}

// parse file
int parser(t_map *map, FILE *file)
{
    char *first_line;

    if (parse_first_line(map, file))
        return 1;
    first_line = read_line(file);
    if (first_line == NULL)
        return 1;
    map->num_cols = strlen(first_line) - 1;
    if (map->num_cols <= 0)
    {
        free(first_line);
        return 1;
    }
    if (allocate_map(map))
    {
        free(first_line);
        return 1;
    }
    if (parse_grid_data(map, file, first_line))
        return 1;
    return 0;
}
