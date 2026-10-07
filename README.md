# Balanced Brackets in C

A small C11 command-line solution that checks whether (), [], and {} are correctly balanced and properly nested.

## Problem

Read one line of text. Ignore characters other than brackets. Print YES when every opening bracket has a matching closing bracket in the correct order; otherwise print NO. An empty line is balanced.

Examples:

| Input | Output |
| --- | --- |
| {[()]} | YES |
| ([)] | NO |
| hello | YES |

## Build and run

Use a C11 compiler such as GCC:

~~~
gcc -std=c11 -Wall -Wextra -pedantic balanced_brackets.c -o balanced_brackets
printf '{[()]}\n' | ./balanced_brackets
~~~

The program accepts up to 4,095 characters on its input line.

## Approach

Each opening bracket is pushed onto a stack. For every closing bracket, the program checks the top of the stack and rejects a missing or mismatched pair immediately. It accepts the input only when the stack is empty at the end. Other characters are ignored.

Time complexity: O(n). Space complexity: O(n), where n is the input length.
