#include "map.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->num_lines)
	{
		fprintf(stdout, "%s\n",  map->grid[i]);
		i++;
	}
}
