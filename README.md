# Get_Next_Line - 42 Project

![Get_Next_Line](https://img.shields.io/badge/Get_Next_Line-42-success)

The **Get_Next_Line** project is part of the curriculum at [42 Adelaide](https://www.42adel.org.au/) and aims to create a function that reads and returns a line from a file descriptor.

## Project Objectives

The project aims to introduce students to file manipulation and advanced memory management techniques. It provides them with an opportunity to practice the following skills:

- Reading files and handling file descriptors
- Memory allocation and deallocation
- String manipulation and parsing
- Static variables and buffer management

## How to use

To use the **Get_Next_Line** function, you need to:
1. Clone the repository to your local machine
```bash
git clone https://github.com/fionashane/get_next_line.git
```

2. Compile the function using the provided Makefile
```bash
make
```

3. Include the appropriate header file in your C file
```c
#include "get_next_line.h"
```

4. Call the `get_next_line` function to read lines from a file descriptor
```c
#include <stdio.h>

int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Function Signature

The **Get_Next_Line** function has the following signature:
```c
int get_next_line(int fd]);
```

The `fd` parameter is the file descriptor to read from, and `line` is the address of a pointer that will be allocated to store the line read from the file. The function returns 1 if a line was read successfully, 0 if the end of file was reached, or -1 in case of an error.
