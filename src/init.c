#include "../include/map.h"

void init_map(t_map *map)
{
    map->num_lines = 0;
    map->num_cols = 0;
    map->empty_char = '.';
    map->obstacle_char = 'o';
    map->full_char = 'x';
    map->grid = NULL;
}
