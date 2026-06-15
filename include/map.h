#ifndef MAP_H
# define MAP_H

# define _GNU_SOURCE
#include <stdio.h> // for FILE type
#include <stdlib.h> // for malloc and free
#include <string.h> // for strlen and strcpy

typedef struct s_map
{
    int		num_lines; 
    int		num_cols;

    char	empty_char;
    char	obstacle_char;
    char	full_char;

	char	**grid;
}   t_map;

// prototypes
int		bsq(FILE *file);
void	init_map(t_map *map);
int		parser(t_map *map, FILE *file);
int		validate_map(t_map *map);
void	solver(t_map *map);
void	print_map(t_map *map);
void	clean_up(t_map *map);

// utils prototypes
char	*read_line(FILE *file);
int		allocate_grid(char ***grid, int rows, int cols);
int		min3(int a, int b, int c);
void	free_grid(t_map *map);

#endif // MAP_H