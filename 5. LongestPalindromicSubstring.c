/*
 ============================================================================
 Name        : Longest Palindromic Substring
 Author      : Heizel Ann Joseph
 Description : 
     This program finds the longest palindromic substring in a given string.
     A palindrome is a sequence of characters which reads the same backward as forward.
     
     Constraints:
     - 1 <= s.length <= 1000
     - s consists only of digits and English letters
 ============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len < 2) {
        return s;
    }

    int start = 0, maxLen = 1;

    for (int i = 0; i < len; i++) {
        int left = i, right = i;
        while (left >= 0 && right < len && s[left] == s[right]) {
            if ((right - left + 1) > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }

        left = i;
        right = i + 1;
        while (left >= 0 && right < len && s[left] == s[right]) {
            if ((right - left + 1) > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }

    char* res = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(res, s + start, maxLen);
    res[maxLen] = '\0';
    return res;
}

int main() {
    char s[1001];

    printf("Enter a string (only letters and digits): ");
    scanf("%1000s", s);

    char* result = longestPalindrome(s);
    printf("Longest Palindromic Substring: %s\n", result);

    if (result != s) {
        free(result);
    }

    return 0;
}
