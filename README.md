# Monty ByteCode Interpreter

## Overview

Monty 0.98 is a scripting language that is first compiled into Monty byte codes. This project implements an interpreter for Monty ByteCode files.

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All files will be compiled on Ubuntu 20.04 LTS using `gcc` with the options `-Wall -Werror -Wextra -pedantic -std=c89`
- All files should end with a new line
- A `README.md` file, at the root of the folder of the project, is mandatory
- Code should use the Betty style
- Maximum of one global variable allowed
- No more than 5 functions per file
- Allowed to use the C standard library
- Function prototypes should be included in the header file `monty.h`
- Header files should be include guarded

## Compilation

To compile the project, use the following command:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
