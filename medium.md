# How I built BSQ in C step by step
This article is written after my trying for Exam Rank 05 at 42 Berlin. I'll explain how I approached the problem, how I designed the program, and how I implemented the solution. I will also share some tips and insights that I learned along the way.

first of all...
## What is BSQ?
BSQ stands for "**B**iggest **Sq**uare". The problem is to find the largest square that can be formed in a given 2D map, where some cells are empty and some are occupied. somthing lik this:
```
............
....o.......
....o.......
....o.......
.........o..
```

The input is a text file that describes the map, and the output is the same map with the largest square marked. still not clear? Don't worry, we will go through the subject step by step and we will understand it together.

Foremost, we will read the subject well and understand the requirements and constraints. We will also analyze the input and output formats, and then we will have a clear idea of what we need to do.
Having a clear understanding of the problem is crucial before we start coding, isn't it? John Dewey put it:
> "A problem well stated is a problem half solved."

## Why Learning BSQ is Important?
As a student at 42, we are expected to solve the BSQ problem as part of our curriculum. It is a common problem that tests our ability to read and understand a subject, design a program, implement an algorithm, and manage memory. It also helps us to practice our coding skills and to learn how to approach complex problems in a systematic way.
Since you are here to learn this problem, you will see that How I read the subject, how I designed the program, and how I implemented the solution. You can get inspiration from my approach and apply it to other problems as well.

## What is the Subject
Here I will paste the subject of the BSQ problem, and then I will explain how I read it and how I understood the requirements. I will also highlight the important parts (by referring to them) and the constraints that I need to consider when designing my solution.

you can see the subject from here: ---> link to the subject on my GitHub <-----

## "I have No Idea Where to Start."
As am alwayys learning programmer, when I first read a subject, I often feel overwhelmed and confused. In such a case, I read the subject multiple times and I try to break it down into smaller parts. Sometimes sentences after multiple reading are like puzzle pieces. by each reading, I also try to identify the main components and the flow of the program. These questions are the ones I try to answer when I read the subject:

- What is the input and output?
- What information do I need to extract from the input?
- What I have to check for in the input to validate it?
- What algorithm can I use to solve the problem?
- What are the edge cases and special cases?
- What are the main functions and data structures I need to use?
- How can I test my solution?

Absulutly, sometimes I'm not in a deep thought and I just start coding without a clear plan. Afer first try, I realize that I have to now more about the problem and need to refactor my code. This is not the best approach, but it is a common one for beginners.

Theory is enough for now. Let's jump into the practical part and see how I built BSQ step by step.

---

### Step 1: Reading the subject
If you already have read the subject and you wnat to make your hands dirty, do it now, otherwise, walkthrough with me as I read the subject and I explain well how I understand it.

✒️
> bsq

This first line of the subject is the name the program. I can use it as the name of my pillar function and also as the name of my executable file_that I will compile later.

✒️
> expected files: *.c *.h

This line tells me that I need to create some `.c` files and some `.h` files. This means that I need to organize my code into multiple files, and I also need to create header files for my *function prototypes* and *data structures*. This is a good practice to keep my code modular and maintainable.
I like to write code clean and readable using componential or modular programming. You will catch it later.

✒️
> allowed functions: malloc, calloc, realloc, free, fopen, fclose, getline, fscanf, fputs, fprintf, stderr, stdout, stdin, errno.

This line has a lot of information and you can think of it as a hint for how to implement your solution. If you know them awesome! if not, use `man` command  in terminal to learn about them.
``` cmd
man malloc
```
#### A quick introduction to these functions:
- **malloc, calloc, realloc, free:** these are the functions that I can use to manage memory in my program. I will need to allocate memory for my data structures and also to free it when I am done. This is important to avoid memory leaks and to ensure that my program runs efficiently.
- **fopen, fclose, getline, fscanf, fputs, fprintf:** these are the functions that I can use to read and write files.
- **stderr, stdout, stdin:** these are the standard input and output streams that I can use to read from the console and to write to the console. I can also use them to handle errors and to print messages.
- **errno:** this is a global variable that I can use to check for errors when I call some functions. It will help me to debug my program and to handle errors gracefully.

✒️
> The aim of this program is to...

This paragraph describes the main goal of the program, which is not very informative. It is good time to browse the internet and to look for some explanations and examples of the BSQ problem. This helped me to understand the problem better and to get some ideas on how to solve it.

✒️
> The first line of the map contains information on how to read the map:
> - the number of the lines on the map;
> - the "empty" characters;
> - the "obstacle" characters;
> - the "full" characters;

On the contrary, This part is very imformative and says the how is the form of input file, which is a file we have to open and read; Parsing.
Parsing the input is the process of reading the input file and extracting the relevant information from it.
In this moment, an idea cames up:
After opening the file, I will get the first line and I will save the number of lines, the empty character, the obstacle character, and the full character.
Where do I need them? Probably when I want to read the rest of the map, I will need to know how many lines I have to read, and also I will need to know what characters represent empty cells, obstacle cells, and full cells. This information will be crucial for me to parse the map correctly and to solve the problem.

✒️
> The map is made up of '"empty" characters', lines and '"obstacle" characters'.

This part describes the structure of the map. It is a 2D grid of characters, where some characters represent empty cells and some characters represent obstacle cells.
When I see the `map` word, I think of a 2D array or a matrix. I will need to read the map from the file and store it in a 2D array that I like to call it a `grid`.

✒️
> The aim of the program is to replace '"empty" characters' by '"full" characters' in order to represent the biggest square possible.

This part tells me what I need to do with the map. I need to find the largest square of empty cells and replace them with full characters. if you have a look the the example at the end of the subjext, you will see that the output is the same map but with the largest square of empty cells replaced by full characters.
But how?
Here I need to use an algorithm. Usually, in such a case, We need to search for a suitable algorithm that can solve the problem efficiently. Resources like GeeksforGeeks, StackOverflow, and YouTube can be very helpful to find such algorithms. We don't need to reinvent the wheel.
For the BSQ problem, a common algorithm is to use `dynamic programming` to find the largest square of empty cells in the grid.

✒️
> In the case that more than one solution exists, we'll choose to represent the square that's the closest to the top of the map, then the one that's most to the left.

Great! It means that when I'm iterating through the grid to find the largest square, if I find a square of the same size as the largest one I have found so far, I will compare their positions and choose the one that is closer to the top and then to the left.

✒️
> When your program receives more than one map in argument, each solution or "map error" must be followed by a line break.

This part has 3 important points for me to consider:
- I need to handle multiple maps in the same program. This means that I need to be able to read and process multiple input files, and to print the results for each of them. I will need to use a loop to iterate through the input files and to call my key function for each of them.
- I need to print a line break after each solution or error message.
- I need to handle errors gracefully. If there is an error in the input file, I need to print "map error" and then a line break.    

✒️
> Should there be no passed arguments, your program must be able to read on the standard input.
This part tells me that I need to handle the case when there are no input files provided. In this case, I need to read the map from the standard input (the console). 

✒️
> Definition of a valid map:
>    - all lines must have the same length.
>    - there's at least one line of at least one box.
>    - at each end of line, there's a line break.
>    - the chars on the map can only be those introduced in the first line.
>    - the map is invalid if a character is missing from the first line, or if two chars (of empty, full and obstacle) are identical.
>    - the chars can be any printable character, even numbers.
>    - the case of an invalid map, your program should display "map error" on the error output followed by a line break. Your program will then move on to the next map.

These lines are about the validation of the input map. I need to check if the map is valid according to these rules before I try to solve it. If the map is invalid, I need to print "map error" and then a line break, and then move on to the next map.

This deep reading was very helpful. wasn't it? I think you have some good ideas about the structure of the program. Now, take look to my approach to design the program and to implement the solution.


let's hit the buttuns.

### Step 1: Designing the Main File
I always start with the main file, because it is the entry point of the program. It is where I will read the input files and call the key function that will solve the problem. It is also where I will handle errors and print the results.
``` c
int main(int argc, char **argv)
{
    // As I read the subject if there are inputs files, they can ba more than one. so I have to loop through them and call my key function for each of them. If there are no input files, I need to read from the standard input.

    // In C standard input is a file stream and to open it, we can use the `fopen` function similar to how we open a regular file. The difference is that instead of passing a file name, we pass the constant `stdin` which represents the standard input stream.
}
```

So I could write something like this:

``` c
int main(int argc, char **argv)
{
    if (argc > 1)
     // there are input files

    else
     // read from standard input

    // If eveything is ok and we get the last line of the main function, we can return 0 to indicate that the program finished successfully.
    return 0;
}
```

If there are input files, I can loop through them and call my key function for each of them. if there are no input files, I can call my key function with the standard input stream.

``` c
int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            // call my key function with argv[i] as the input file
        }
    }
    else
    {
        // call my key function with stdin as the input stream
    }
    return 0;
}
```

If I have a key function that takes a file stream as input, I can call it like this:

``` c
int main(int argc, char **argv)
{    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            FILE *file = fopen(argv[i], "r"); // 1- open the input file for reading
            if (file == NULL)
            {
                // handle error
                continue;
            }
            // 2- call my key function with file as the input stream
            bsq(file);

            fclose(file); // 3- close the file after processing
        }
    }
    else
    {
        // call my key function with stdin as the input stream
        bsq(stdin);
    }
    return 0;
}
```

But I prefer to declare variables at the beginning of the function, in the uppest scope, and assign them in the scope it belongs to, and using `while` loop over than `for` loop. so I can write it like this:

``` c
int main(int argc, char **argv)
{
    FILE *file;
    int i;

    if (argc > 1)
    {
        i = 1;
        while (i < argc)
        {
            file = fopen(argv[i], "r");
            if (file == NULL)
            {
                // handle error
                i++;
                continue;
            }
            bsq(file);
            fclose(file);
            i++;
        }
    }
    else
    {
        bsq(stdin);
    }
    return 0;
}
```

As we know, it happens that we have an error in the input file, and we need to print "map error" and then a line break, and then move on to the next map. In this case, we can handle the error in the `bsq` function and return 1 if there is an error, and then if there is an error, we can print "map error" and then a line break, and then move on to the next map. So we can modify our main function like this:

``` c
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
                continue;
            }
            error = bsq(file);
            if (error) // it means if the value of error is not 0
            {
                // print map error and continue
                fprintf(stderr, "map error\n");
            }
            fclose(file);
            i++;
        }
    }
    else
    {
        bsq(stdin);
    }
    return 0;
}
```

Did you notice that I used `fprintf` function to print the error message to the standard error stream (`stderr`)? This is a good practice to separate the normal output from the error messages.

Did you like it? This was our main function. let's move for the next step which is the `int bsq(FILE *file)`

### Step 2: Structuring the Flow of the Program
Now that we have our main function, we can start thinking about the structure of our program. We can break down the problem into smaller parts and then we can implement each part separately.

``` c
int bsq(FILE *file)
{
    // 1- parsing
    // 2- validating the map
    // 3- solving the problem
    // 4- printing the result
    // 5- cleaning up memory
}
```

### What is Happening in Each Level

If we knowwhat is happening in each level. we can design our functions and our data structures accordingly. For example:

- in parsing, I will read the **input file** and extract the **relevant information** from it, such as the *number of lines*, the *empty character*, the *obstacle character*, and the *full character*. I will also read the *map* and store it in a 2D array.
If there is an error in parsing, I will *return 1* to indicate that there is an error.

- in validating the map, I will check if the *map* is valid according to the rules mentioned in the subject. If the map is invalid, I will *return 1* to indicate that there is an error.

- in solving the problem, I will use an algorithm to find the largest square of *empty cells* in the *grid* and to replace them with *full characters*.
- in printing the result, I will print the *modified map* to the standard output.
- in cleaning up memory, I will free any dynamically allocated memory (e.g., *the 2D array*) to avoid memory leaks.


Here, We almost know how is the functions prototype gonna be. Now we hava a clearer image about the functions arguments and return values.
It would be a good idea to think about storing data we get from file. I prefer to  create a *data structure* to hold all this information as a package and pass it in the functions that need it. somthing like this:

``` c
typedef struct s_map
{
    int num_lines; // or `int rows`;
    int num_cols; // or `int cols`;
    char empty_char;
    char obstacle_char;
    char full_char;
    char **grid; // 2D array to store the map
}   t_map;
```

Then I can pass this `t_map` struct to the functions that need it, such as:
- initializer to initialize the struct with default values
- parser to parse the input file and fill the struct with the relevant information
- validator to validate the map using the information in the struct
- solver to solve the problem using the information in the struct
- cleaner to free any dynamically allocated memory in the struct

It's so clean, isn' it?

so the flow of the program will be something like this:

``` c
int bsq(FILE *file)
{
    t_map map;

    init_map(&map); // initialize the map struct with default values

    if (parser(&map, file)) // parse the input file and fill the map struct
    {
        // if there is an error in parsing, return 1
        return 1;
    }

    if (validate_map(&map)) // validate the map using the information in the map struct
    {
        // if there is an error in validation, return 1
        return 1;
    }

    solver(&map); // solve the problem using the information in the map struct

    print_map(&map); // print the modified map to the standard output

    clean_up(&map); // free any dynamically allocated memory in the map struct

    return 0; // return 0 to indicate that the program finished successfully
}
```

As you see I pass the map struct by reference to the functions, so that they can modify it directly. This way, I can keep my code clean and organized, and I can also avoid passing multiple parameters to the functions.


#### Why is Better to Split Responsibilities into Functions
Splitting responsibilities into functions is a good practice for several reasons:
- It makes the code more modular and easier to read. Each function has a specific task, and it is easier to understand what it does without having to read the entire code.
- It makes the code more reusable. If I need to use the same functionality in another part of the program, I can simply call the function instead of having to copy and paste the code.
- It makes the code easier to maintain and debug. If there is an issue with a specific part of the code, I can isolate it to a single function and fix it without affecting the rest of the program.

Here on we go deee p into functions. we will save them in separate files, and we will include the header files that contain their prototypes and the definition of the `t_map` struct.
These are the files that I will create:
- `main.c` for the main function
- `bsq.c` for the `bsq` function
- `map.h` for the definition of the `t_map` struct and the prototypes of the functions that operate on it
- `init.c` for the `init_map` function
- `parse.c` for the `parser` function and its helper functions
- `validate.c` for the `validate_map` function
- `solve.c` for the `solver` function
- `print.c` for the `print_map` function
- `clean.c` for the `clean_up` function

### Step 3:  Implement `void init_map(t_map *map)`
Initialization is the process of setting up the initial state of the program. In this case, I will initialize the `t_map` struct with default values. This will help me to avoid any undefined behavior when I try to access the members of the struct before they are filled with the relevant information from the input file.

``` c
#include "map.h"

void init_map(t_map *map)
{
    map->rows = 0;
    map->cols = 0;
    map->empty_char = '.';
    map->obstacle_char = 'o';
    map->full_char = 'x';
    map->grid = NULL;
}
```

### Step 5: Implement `int parse_map(t_map *map, FILE *file)`
Parsing is the process of reading the input file and extracting the relevant information from it.
In this case, We have two sections in the input file:
- the first line contains the map dimensions and characters,
- and the subsequent lines contain the map data.
We will read the first line of the input file to get the number of lines, the empty character, the obstacle character, and the full character. Then we will read the rest of the lines to fill the grid with the map data.
The structure gonna be something like this:

``` c
int parser(t_map *map, FILE *file)
{
    // 1- read the first line of the input file to get the map dimensions and characters
    // 2- allocate memory for the grid based on the number of lines and columns
    // 3- read the rest of the lines to fill the grid with the map data
    // 4- return 0 if everything is ok, or return 1 if there is an error in parsing
}
```
We can have this helper functions:
- `parse_first_line` to parse the first line of the input file and fill the map struct with the relevant information.
- `allocate_map` to allocate memory for the grid based on the number of lines and columns.
- `parse_grid_data` to read the rest of the lines and fill the grid with the map data.

based on the responsibilities of each function, we can have the following prototypes:

``` c
int parse_first_line(t_map *map, FILE *file);
int allocate_map(t_map *map);
int parse_grid_data(t_map *map, FILE *file);
```

Let's implement the `parser` function using these helper functions:

``` c
#include "map.h"

int parser(t_map *map, FILE *file)
{
    if (parse_first_line(map, file))
    {
        return 1; // error in parsing the first line
    }
    if (allocate_map(map))
    {
        return 1; // error in allocating memory for the grid
    }
    if (parse_grid_data(map, file))
    {
        return 1; // error in parsing the grid data
    }
    return 0; // everything is ok
}
```
Now we have a clear structure for our parser function, and we can implement each helper function separately.
Let's think about funciinality of each helper function and how to implement it.
For `parse_first_line`, we need to read the first line of the input file and extract the number of lines, the empty character, the obstacle character, and the full character. We can use the `getline` function to read the first line, and then we can parse it using string manipulation functions to fill the `t_map` struct with the relevant information.
Ler's notice the pattern of the first line. It is something like this:
``` html
<number_of_lines><empty_char><obstacle_char><full_char>
// for example: 9.ox
```

``` c
int parse_first_line(t_map *map, FILE *file)
{
    // read the first line of the input file and fill the map struct with the relevant information
    // return 0 if everything is ok, or return 1 if there is an error in parsing the first line
}
```

Let's implement the `parse_first_line` function:

``` c
#include "map.h"

int parse_first_line(t_map *map, FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, file);
    if (read == -1)
    {
        free(line);
        return 1; // error in reading the first line
    }

    // parse the first line to extract the number of lines and the characters
    // for example, if the line is "9.ox", we can extract:
    // num_lines = 9
    // empty_char = '.'
    // obstacle_char = 'o'
    // full_char = 'x'

    free(line);
    return 0; // everything is ok
}
```
 This code snippet I added for reading the first line using getline function is a pattern that we use often.
 If it is a pattern, and we need to use it multiple times in our program, it is a good idea to create a helper function for it, so that we can reuse it whenever we need to read a line from a file. This will help us to avoid code duplication and to keep our code clean and organized.
We can create a helper function like this and put it in a separate file called `utils.c`:

``` c
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
```

Then we can use this `read_line` function in our `parse_first_line` function.
When we get the first line, we parse it and fill the `t_map` struct manually. We could use `sscanf` function to parse the line, which is a convenient way to extract formatted data from a string. but the subject didin't allow us to use it.

``` c
#include "map.h"

int parse_first_line(t_map *map, FILE *file)
{
    char *line;

    line = read_line(file);
    if (line == NULL)
        return 1; // error in reading the first line

    // parse the first line to extract the number of lines and the characters
    // I'd rather to iterate backward to get the characters, and then the number of lines will be the rest of the line, how?
    
    int len =  strlen(line);
    if (line[len - 1] == '\n')
    {
        line[len - 1] = '\0'; // remove the newline character if it exists
        len--;
    }
    map->full_char = line[len - 1];
    map->obstacle_char = line[len - 2];
    map->empty_char = line[len - 3];

    // to take the remaining digits:
    int i = len - 4;
    while (i >= 0)
    {
        map->num_lines = map->num_lines * 10 + (line[i] - '0');
        i--;
    }

    free(line);
    return 0; // everything is ok
}
```

Now, It is time to implement the `allocate_map` function, which is responsible for allocating memory for the grid inside the `t_map` struct based on the number of lines and columns. We can use the `malloc` function to allocate memory for a 2D array of characters. and let's make a general function named `allocate_grid` and put it in `utils.c` file as well, since it is a helper function that we can reuse in other parts of the program if needed.

``` c
#include "map.h"

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
            // free previously allocated memory in case of an error
            while (i > 0)
            {
                free((*grid)[i - 1]);
                i--;
            }
            free(*grid);
            return 1;
        }
        i++;
    }
    (*grid)[rows] = NULL; // null-terminate the array of pointers
    return 0; // everything is ok
}
```

Our `allocate_map` will be a simple wrapper around this `allocate_grid` function, which will call it with the appropriate arguments from the `t_map` struct.

``` c
int allocate_map(t_map *map)
{
    return allocate_grid(map->grid, map->num_lines, map->num_cols);
}
```

And now we can implement the `parse_grid_data` function, which is responsible for reading the rest of the lines and filling the grid with the map data. We can use the `read_line` function to read each line of the grid, and then we can copy the characters from the line to the corresponding row in the grid.

``` c
#include "map.h"

int parse_grid_data(t_map *map, FILE *file)
{
    char *line;
    int i = 0;
    int j;

    while (i < map->num_lines)
    {
        line = read_line(file);
        if (line == NULL)
            return 1;
        // copy the characters from the line to the corresponding row in the grid
        j = 0;
        while (j < map->num_cols)
        {
            map->grid[i][j] = line[j];
            j++;
        }
        map->grid[i][j] = '\0'; // null-terminate the string
        free(line);
        i++;
    }
    return 0; // everything is ok
}
```

Now we have implemented the `parser` function and its helper functions. We can move on to the next step, which is validating the map. Let's save the final version of the `parser` function and its helper functions in the `parse.c` file.

``` c
#include "map.h"

int parser(t_map *map, FILE *file)
{
    if (parse_first_line(map, file))
    {
        return 1; // error in parsing the first line
    }
    if (allocate_map(map))
    {
        return 1; // error in allocating memory for the grid
    }
    if (parse_grid_data(map, file))
    {
        return 1; // error in parsing the grid data
    }
    return 0; // everything is ok
}
```
very very clean, isn't it?

---
It time to move to the next step, which is validating the map. We will implement the `validate_map` function in a separate file called `validate.c`.

### Step 4: `int validate_map(t_map *map)`
Based on the rules mentioned in the subject, we need to check if the map is valid according to these rules:
- all lines must have the same length.
- there's at least one line of at least one box.
- at each end of line, there's a line break.
- the chars on the map can only be those introduced in the first line.
- the map is invalid if a character is missing from the first line, or if two chars (of empty, full and obstacle) are identical.
- the chars can be any printable character, even numbers..

We can implement the `validate_map` function to check these rules and return 1 if the map is invalid, or return 0 if the map is valid.

``` c
#include "map.h"
int validate_map(t_map *map)
{
    // check if all lines have the same length
    // check if there's at least one line of at least one box
    // check if at each end of line, there's a line break
    // check if the chars on the map can only be those introduced in the first line
    // check if the map is invalid if a character is missing from the first line, or if two chars (of empty, full and obstacle) are identical
    // return 1 if the map is invalid, or return 0 if the map is valid
}
```
Now we have a clear structure for our `validate_map` function, and we can implement each check separately. We can also create helper functions for each check if needed, to keep our code clean and organized.
This i sthe final version.

``` c
#include "map.h"

int validate_lines_length(t_map *map)
{
    int i;
    int len;

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
```
--- 
Now let.s jump into the next step, which is solving the problem. We will implement the `solver` function in a separate file called `solve.c`.

### Step 6: `void solver(t_map *map)`

The `solver` function is responsible for finding the largest square of empty cells in the grid and replacing them with full characters. We can use a dynamic programming algorithm to solve this problem efficiently. The idea is to create a 2D array `dp` where `dp[i][j]` represents the size of the largest square that can be formed with the cell `(i, j)` as the bottom-right corner. We can fill this `dp` array based on the values of the neighboring cells and then find the maximum value in the `dp` array to determine the size of the largest square. We can also keep track of the position of the largest square to replace the corresponding cells in the grid with the full character.

for the implementation of the `solver` function, we can follow these steps:
1. Create a 2D array `dp` of the same size as the grid
2. Initialize the first row and the first column of the `dp` array based on the values in the grid
3. Fill the `dp` array using the following relation:
   - If the cell `(i, j)` in the grid is an empty cell, then
     `dp[i][j] = min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1`
   - Otherwise, `dp[i][j] = 0`
4. Keep track of the maximum value in the `dp` array and its position
5. After filling the `dp` array, replace the corresponding cells in the grid with the full character based on the position and size of the largest square

I make the `min3` function and `free_grid` the allocated memory, and I add it to the `utils.c` file as well, since it is a helper function that we can reuse in other parts of the program if needed.

``` c
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
```

Now in the `solve.c` file, we can implement the `solver` function using the `min3` function and the dynamic programming approach described above.

``` c
#include "map.h"

int solver(t_map *map)
{
    int **dp;
    int max_size = 0;
    int max_i = 0;
    int max_j = 0;
    int i, j;

    // allocate memory for the dp array
    dp = allocate_grid(map->num_lines, map->num_cols);
    if (dp == NULL)
        return 1;

    // initialize the first row and the first column of the dp array
    for (i = 0; i < map->num_lines; i++)
    {
        dp[i][0] = (map->grid[i][0] == map->empty_char) ? 1 : 0;
        if (dp[i][0] > max_size)
        {
            max_size = dp[i][0];
            max_i = i;
            max_j = 0;
        }
    }
    for (j = 0; j < map->num_cols; j++)
    {
        dp[0][j] = (map->grid[0][j] == map->empty_char) ? 1 : 0;
        if (dp[0][j] > max_size)
        {
            max_size = dp[0][j];
            max_i = 0;
            max_j = j;
        }
    }

    // fill the dp array
    for (i = 1; i < map->num_lines; i++)
    {
        for (j = 1; j < map->num_cols; j++)
        {
            if (map->grid[i][j] == map->empty_char)
            {
                dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                if (dp[i][j] > max_size)
                {
                    max_size = dp[i][j];
                    max_i = i;
                    max_j = j;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    // replace the corresponding cells in the grid with the full character
    for (i = max_i - max_size + 1; i <= max_i; i++)
    {
        for (j = max_j - max_size + 1; j <= max_j; j++)
        {
            map->grid[i][j] = map->full_char;
        }
    }

    // free the dp array
    for (i = 0; i < map->num_lines; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return 0;
}
```

---
Now we have implemented the `solver` function. We can move on to the next step, which is printing the result. We will implement the `print_map` function in a separate file called `print.c`.

### Step 7: `void print_map(t_map *map)`

``` c
#include "map.h"

void print_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->num_lines)
    {
        fprintf(stdout, "%s\n", map->grid[i]);
        i++;
    }
}
```
easy, ne?

---
Now it is the last step, which is cleaning up memory. We will implement the `clean_up` function in a separate file called `clean.c`.

### Step 7: `void clean_up(t_map *map)`

``` c
#include "map.h"

void clean_up(t_map *map)
{
    free_grid(map);
}
```
---

### At the eEnd:
I used to think that the subject is just a description of the problem, but after reading it deeply and analyzing it, I realized that it is more than that. It is a guide that helps us to design and implement our program. It gives us the structure of the program, the data we need to store, the functions we need to implement, and the flow of the program.

Here is a summary of the steps we followed to design and implement our program:

```
Read the subject
↓
Identify the program flow
↓
Design the data structure
↓
Implement parsing
↓
Validate input
↓
Solve the algorithm
↓
Print the result
↓
Clean memory
```

This is the overall architecture of our program. Each step corresponds to a function that we implemented in a separate file. This way, we kept our code clean, organized, and modular. We can easily understand what each part of the code does and how it contributes to solving the problem.

```
main()
└── bsq()
    ├── init_map()
    ├── parse()
    ├── solve()
    ├── print()
    └── clean_up()
```

To make folders for each part of the program, we can create a folder called `src` for the source files and a folder called `include` for the header files. Then we can organize our files as follows:

```project/
├── src/
│   ├── main.c
│   ├── bsq.c
│   ├── init.c
│   ├── parse.c
│   ├── validate.c
│   ├── solve.c
│   ├── print.c
│   └── clean.c
└── include/
    └── map.h
└── utils.c
└── Makefile
```

You can Download the full code from [here](github.com/yourusername/bsq). Don't forget to give it a star on GitHub if you like it! ⭐