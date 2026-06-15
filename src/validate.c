#include "map.h"

int validate_lines_length(t_map *map)
{
    int i;
    size_t len;

    len = strlen(map->grid[0]);
    i = 1;
    while (i < map->num_lines)
    {
        if (strlen(map->grid[i]) != len)
            return 1;
        i++;
    }
    return 0;
}

int validate_characters(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->num_lines)
    {
        j = 0;
        while (j < map->num_cols)
        {
            char c = map->grid[i][j];
            if (c != map->empty_char && c != map->obstacle_char && c != map->full_char)
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

int validate_map(t_map *map)
{
    if (validate_lines_length(map))
        return 1;
    if (validate_characters(map))
        return 1;
    return 0;
}
