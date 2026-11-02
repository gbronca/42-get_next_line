*This project has been created as part of the 42 curriculum by `gcouto-b`*

# get_next_line

This is an implementation of `get_next_line`, which reads from a file descriptor and returns a new line each time it is called, until it reaches the end of the file.
The function returns a pointer to a string containing the line that was read, without the newline character `\n`. It returns `NULL` when the end of file is reached or an error occurs. The function uses `static variable` to store the state of the call.

## Instructions

To compile the code, run command below in the terminal:

```bash
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
```

If you wish the replace the default value of `BUFFER_SIZE` with any positive value you want, replace 42 on the command below:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

To compile the bonus code, run:

```bash
cc -Wall -Wextra -Werror main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

Or the command below with your chosen `BUFFER_SIZE`.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

Please not that `main.c` is not included in this repo, bring your own `main.c`.

A quick example of a `main.c`:

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
  int   fd;
  char  *line;
  
  fd = open(argv[1], O_RDONLY);
  line = "";
  while (line != NULL)
  {
    line = get_next_line(fd);
    printf("%s", line);
  }
  fd = close(fd);
  return (0);
}
```

## Code Decisions

- If `BUFFER_SIZE` isn't defined when calling `get_next_line`, the value of `BUFSIZ` is assigned. `BUFSIZ` expands to an integer constant expression that represents the recommended size (in bytes) of the buffer used by stream input/output functions. The C standard specifies that BUFSIZ must be at least `256` bytes. The value is platform dependent though:
  - **Mac / macOS**: Typically 1024 bytes
  - **Ubuntu / Linux (glibc)**: Typically 8192 bytes
  - **Windows (MinGW / Visual C++)**: Typically 512 bytes (though underlying runtime streams may allocate larger chunks like 4096 bytes).
- For the bonus part, we define `GNL_FD_MAX` to 1024. It represents the limit of how many files can be open at the same time. It can be chancked by typing `ulimit -n` on the terminal. If the value is higher than the system limit, all file descriptors above that would return `NULL`.

I've opted to use structs for both the buffer and the current line to minimise the number of functions and to have the minimum amount of changes for the bonus part. It took a few iteractions and rewrites of the code to get to this point but I believe it made for a clean, concise and easy to read implementation. The `t_state` struct keeps the state of the application across `get_next_line()` calls while `t_line` is maintain the state of the line being built.

## Resources

[Handling a File by its Descriptor in C](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
[gnlTester](https://github.com/Tripouille/gnlTester) to test the implementation.
