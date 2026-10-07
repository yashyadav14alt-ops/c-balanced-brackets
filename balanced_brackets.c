#include <stdio.h>
#include <string.h>

#define MAX_INPUT 4095

static int is_opening(char c) { return c == '(' || c == '[' || c == '{'; }
static int is_closing(char c) { return c == ')' || c == ']' || c == '}'; }
static int matches(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

int main(void) {
    char input[MAX_INPUT + 2];
    char stack[MAX_INPUT + 1];
    if (fgets(input, sizeof input, stdin) == NULL) {
        fputs("Error: expected one line of input.", stderr);
        fputc(10, stderr);
        return 1;
    }
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == 10) input[--length] = 0;
    if (length > MAX_INPUT) {
        fprintf(stderr, "Error: input must be at most %d characters.", MAX_INPUT);
        fputc(10, stderr);
        return 1;
    }
    size_t top = 0;
    for (size_t i = 0; i < length; ++i) {
        char c = input[i];
        if (is_opening(c)) stack[top++] = c;
        else if (is_closing(c)) {
            if (top == 0 || !matches(stack[top - 1], c)) { puts("NO"); return 0; }
            --top;
        }
    }
    puts(top == 0 ? "YES" : "NO");
    return 0;
}
