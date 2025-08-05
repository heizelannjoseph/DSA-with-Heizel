/*
Problem: String to Integer (atoi)

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

Algorithm:
1. Whitespace: Ignore leading whitespace.
2. Signedness: Check if the next character is '-' or '+' to determine sign (default is positive).
3. Conversion: Read digits until a non-digit is encountered or the end of the string is reached.
   - Ignore leading zeros in the result.
   - If no digits are found, return 0.
4. Rounding: Clamp the result to the 32-bit signed integer range:
   - If result < -2^31 → return -2147483648
   - If result >  2^31-1 → return  2147483647
5. Return the final integer.

Examples:
Input: "42" → Output: 42
Input: "   -042" → Output: -42
Input: "1337c0d3" → Output: 1337
Input: "0-1" → Output: 0
Input: "words and 987" → Output: 0

Constraints:
0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/

#include <stdio.h>

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    long result = 0;

    while (s[i] == ' ') {
        i++;
    }

    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');

        if (sign == 1 && result > 2147483647) {
            return 2147483647;
        }
        if (sign == -1 && result > 2147483648) {
            return -2147483648;
        }

        i++;
    }

    return (int)(sign * result);
}

int main() {
    char s1[] = "42";
    char s2[] = "   -042";
    char s3[] = "1337c0d3";
    char s4[] = "0-1";
    char s5[] = "words and 987";

    printf("Input: \"%s\", Output: %d\n", s1, myAtoi(s1));
    printf("Input: \"%s\", Output: %d\n", s2, myAtoi(s2));
    printf("Input: \"%s\", Output: %d\n", s3, myAtoi(s3));
    printf("Input: \"%s\", Output: %d\n", s4, myAtoi(s4));
    printf("Input: \"%s\", Output: %d\n", s5, myAtoi(s5));

    return 0;
}
