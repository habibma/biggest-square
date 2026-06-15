#include "../include/map.h"

int bsq(FILE *file)
{
    t_map map;

    init_map(&map);

    if (parser(&map, file))
    {
        clean_up(&map);
        return 1;
    }

    if (validate_map(&map))
    {
        clean_up(&map);
        return 1;
    }

    solver(&map);

    print_map(&map);

    clean_up(&map);

    return 0;
}
