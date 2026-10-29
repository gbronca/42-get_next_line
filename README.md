*This project has been created as part of the 42 curriculum by `gcouto-b`*

# get_next_line

| FD | Description |
| - | - |
| 0 | stdin |
| 1 | stdout |
| 2 | stderr |
| - | - |

## Code Decisions

- If `BUFFER_SIZE` isn't defined when calling `get_next_line`, the value of `BUFSIZ` is assigned. `BUFSIZ` expands to an integer constant expression that represents the recommended size (in bytes) of the buffer used by stream input/output functions. The C standard specifies that BUFSIZ must be at least `256` bytes. The value is platform dependent though:
  - **Mac / macOS**: Typically 1024 bytes
  - **Ubuntu / Linux (glibc)**: Typically 8192 bytes
  - **Windows (MinGW / Visual C++)**: Typically 512 bytes (though underlying runtime streams may allocate larger chunks like 4096 bytes).

## Resources

[get_next_line explained : develop a function that reads a file line by line](https://www.youtube.com/watch?v=8E9siq7apUU)


