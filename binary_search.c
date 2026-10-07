#include <stdio.h>

#define MAX_VALUES 100000

int main(void) {
    int values[MAX_VALUES];
    int count;
    int target;

    if (scanf("%d", &count) != 1 || count < 0 || count > MAX_VALUES) {
        fputs("Error: count must be between 0 and 100000.", stderr);
        fputc(10, stderr);
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            fputs("Error: expected all array values.", stderr);
            fputc(10, stderr);
            return 1;
        }
        if (i > 0 && values[i] < values[i - 1]) {
            fputs("Error: values must be sorted in nondecreasing order.", stderr);
            fputc(10, stderr);
            return 1;
        }
    }
    if (scanf("%d", &target) != 1) {
        fputs("Error: expected a target value.", stderr);
        fputc(10, stderr);
        return 1;
    }

    int low = 0;
    int high = count - 1;
    int result = -1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (values[middle] == target) {
            result = middle;
            high = middle - 1;
        } else if (values[middle] < target) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }

    printf("%d\n", result);
    return 0;
}
