#include "map.h"

int main(int argc, char **argv)
{
    FILE *file;
    int i;
    int error;

    if (argc > 1)
    {
        i = 1;
        while (i < argc)
        {
            file = fopen(argv[i], "r");
            if (file == NULL) // if there is an error opening the file
            {
                fprintf(stderr, "map error\n");
                i++;
                continue; // jump to the next iteration of the loop
            }

            error = bsq(file);
            if (error) // it means if the value of error is not 0
            {
                // print map error and continue
                fprintf(stderr, "map error\n");
            }
            fclose(file);

			if (i < argc - 1) // if there are more files to process, print a new line
				fprintf(stdout, "\n");

            i++;
        }
    }
    else
    {
        bsq(stdin);
    }
    return 0;
}
