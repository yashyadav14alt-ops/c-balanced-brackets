# C Problem Solutions

Three standalone C11 programs solving common programming problems. Each source file has its own `main` function and should be compiled separately.

## 1. Balanced brackets — `balanced_brackets.c`

Checks whether (), [], and {} are balanced and nested in the right order. Non-bracket characters are ignored; an empty line is balanced.

| Input | Output |
| --- | --- |
| {[()]} | YES |
| ([)] | NO |

~~~sh
gcc -std=c11 -Wall -Wextra -pedantic balanced_brackets.c -o balanced_brackets
printf '{[()]}\n' | ./balanced_brackets
~~~

The input line may contain up to 4,095 characters. The solution uses a stack and runs in O(n) time and O(n) space.

## 2. Palindrome checker — `palindrome.c`

Checks whether the input line reads the same forward and backward after ignoring spaces, punctuation, and letter case. It prints YES or NO. An empty or punctuation-only line is considered a palindrome.

| Input | Output |
| --- | --- |
| A man, a plan, a canal: Panama! | YES |
| hello | NO |

~~~sh
gcc -std=c11 -Wall -Wextra -pedantic palindrome.c -o palindrome
printf 'A man, a plan, a canal: Panama!\n' | ./palindrome
~~~

The input line may contain up to 4,095 characters. The solution runs in O(n) time and O(n) space.

## 3. Binary search — `binary_search.c`

Reads an array length, that many integers in nondecreasing order, and a target integer. Prints the first (zero-based) index of the target, or -1 if it is absent. The program checks that the input array is sorted.

Example input:

~~~text
6
-4 0 3 3 8 12
3
~~~

Output:

~~~text
2
~~~

~~~sh
gcc -std=c11 -Wall -Wextra -pedantic binary_search.c -o binary_search
printf '6\n-4 0 3 3 8 12\n3\n' | ./binary_search
~~~

The array may contain up to 100,000 integers. The solution runs in O(log n) search time and O(1) extra space.

## Requirements

A C11 compiler such as GCC or Clang. Compile each file on its own because each contains a `main` function.

## Run the checks

The standard-library Python test runner compiles each program with warnings treated as errors, then checks representative and boundary inputs. It requires Python 3 and GCC on `PATH`.

~~~sh
python -m unittest -v
~~~
