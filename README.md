# get_next_line

`get_next_line` is a C project developed as part of the 42 School curriculum. This project implements a function that reads a file descriptor line-by-line until a newline character is encountered. It demonstrates efficient file I/O handling, dynamic memory management, and string manipulation in C.

## Table of Contents

- [get\_next\_line](#get_next_line)
	- [Table of Contents](#table-of-contents)
	- [Overview](#overview)
	- [Features](#features)
	- [Installation \& Testing](#installation--testing)
	- [Project Structure](#project-structure)
	- [Function Overview](#function-overview)

## Overview

The goal of the project is to create a function named `get_next_line` that reads from a file descriptor and returns a line ending with a newline character (if one exists). The implementation handles various edge cases such as memory allocation errors, multiple file descriptors, and incomplete reads.

## Features

- **Line-by-line reading:** Reads input until a newline character or end-of-file is reached.
- **Dynamic memory allocation:** Uses a defined `BUFFER_SIZE` to handle reads efficiently.
- **Robust error handling:** Checks for invalid file descriptors and read errors.
- **Modular design:** Utility functions for string operations (`ft_strdup`, `ft_strjoin`, `ft_strchr`, `ft_substr`, and `ft_strlen`) are separated for clarity.

## Installation & Testing

Clone the repository and navigate into the project directory:

```bash
git clone https://github.com/yourusername/get_next_line.git
cd get_next_line
```

For testing purposes, you can compile the project manually, after uncommenting the `main()` function in the `get_next_line.c` file:
```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o get_next_line
```

## Project Structure
```bash
get_next_line/
├── get_next_line.h          # Header file with function prototypes and macro definitions.
├── get_next_line.c          # Main implementation of the get_next_line function.
├── get_next_line_utils.c    # Utility functions for string manipulation.
└── README.md                # Project documentation.
```

## Function Overview
- **get_next_line:** Reads from a file descriptor and returns the next line including the newline character if present.
- **read_concatenate_line:** Reads from the file and concatenates the buffer with any leftover characters from previous reads.
- **set_leftover_chars:** Extracts the leftover part after a newline to be used in subsequent calls.
- **Utility Functions:**
	- **ft_strdup:** Duplicates a string.
	- **ft_strjoin:** Concatenates two strings.
	- **ft_strchr:** Searches for a specific character in a string.
	- **ft_substr:** Extracts a substring from a given string.
	- **ft_strlen:** Calculates the length of a string.
