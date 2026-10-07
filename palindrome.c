#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 4095

int main(void) {
    char line[MAX_INPUT + 2];
    char normalized[MAX_INPUT + 1];
    size_t count = 0;

    if (fgets(line, sizeof line, stdin) == NULL) {
        fputs("Error: expected one line of input.", stderr);
        fputc(10, stderr);
        return 1;
    }

    size_t length = strlen(line);
    if (length > 0 && line[length - 1] == 10) line[--length] = 0;
    if (length > MAX_INPUT) {
        fprintf(stderr, "Error: input must be at most %d characters.", MAX_INPUT);
        fputc(10, stderr);
        return 1;
    }

    for (size_t i = 0; i < length; ++i) {
        unsigned char c = (unsigned char)line[i];
        if (isalnum(c)) normalized[count++] = (char)tolower(c);
    }

    int is_palindrome = 1;
    for (size_t i = 0; i < count / 2; ++i) {
        if (normalized[i] != normalized[count - 1 - i]) {
            is_palindrome = 0;
            break;
        }
    }
    puts(is_palindrome ? "YES" : "NO");
    return 0;
}
