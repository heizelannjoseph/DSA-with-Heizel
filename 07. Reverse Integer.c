/*
Problem: Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Constraints:
-2^31 <= x <= 2^31 - 1
*/

#include <stdio.h>

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;   
        x /= 10;            

        if (rev > 214748364 || (rev == 214748364 && pop > 7)) {
            return 0;
        } else if (rev < -214748364 || (rev == -214748364 && pop < -8)) {
            return 0;
        }

        rev = rev * 10 + pop;  
    }
    return rev;
}

int main() {
    int x = 123;
    printf("Input: %d, Output: %d\n", x, reverse(x));

    x = -123;
    printf("Input: %d, Output: %d\n", x, reverse(x));

    x = 120;
    printf("Input: %d, Output: %d\n", x, reverse(x));

    return 0;
}
