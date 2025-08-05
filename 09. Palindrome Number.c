/*
Problem: Palindrome Number

Given an integer x, return true if x is a palindrome, and false otherwise.

A palindrome is a number that reads the same forward and backward.

Examples:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:
-2^31 <= x <= 2^31 - 1
*/

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    int temp = x;
    int rev = 0;

    if (temp < 0) {
        return false;
    }

    while (temp != 0) {
        int pop = temp % 10;   
        temp /= 10;         

        if ((rev > (2147483647 - pop) / 10) || (rev < (-2147483648 - pop) / 10)) {
            return false;
        }

        rev = (rev * 10) + pop;  
    }

    return (x == rev);
}

int main() {
    int x1 = 121;
    int x2 = -121;
    int x3 = 10;

    printf("Input: %d, Output: %s\n", x1, isPalindrome(x1) ? "true" : "false");
    printf("Input: %d, Output: %s\n", x2, isPalindrome(x2) ? "true" : "false");
    printf("Input: %d, Output: %s\n", x3, isPalindrome(x3) ? "true" : "false");

    return 0;
}
