#include "map.h"

void	solver(t_map *map)
{
	int rows = map->num_lines;
	int cols = map->num_cols;

	if (rows <= 0 || cols <= 0 || !map->grid)
		return ;

	int **dp = malloc(rows * sizeof(int *));
	if (!dp)
		return ;
	for (int i = 0; i < rows; i++)
	{
		dp[i] = malloc(cols * sizeof(int));
		if (!dp[i])
		{
			while (--i >= 0)
				free(dp[i]);
			free(dp);
			return ;
		}
	}

	int max_size = 0;
	int max_i = 0;
	int max_j = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (map->grid[i][j] == map->empty_char)
			{
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
				{
					int a = dp[i - 1][j];
					int b = dp[i][j - 1];
					int c = dp[i - 1][j - 1];
					int m = a < b ? a : b;
					m = m < c ? m : c;
					dp[i][j] = m + 1;
				}
				if (dp[i][j] > max_size)
				{
					max_size = dp[i][j];
					max_i = i;
					max_j = j;
				}
			}
			else
				dp[i][j] = 0;
		}
	}

	// Mark the largest square in the grid
	if (max_size > 0)
	{
		for (int i = max_i; i > max_i - max_size; i--)
		{
			for (int j = max_j; j > max_j - max_size; j--)
				map->grid[i][j] = map->full_char;
		}
	}

	for (int i = 0; i < rows; i++)
		free(dp[i]);
	free(dp);
}
