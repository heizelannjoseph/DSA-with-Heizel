/*
 * Problem: Longest Substring Without Repeating Characters
 *
 * Given a string s, find the length of the longest substring without repeating characters.
 
 * Constraints:
 * - 0 <= s.length <= 5 * 10^4
 * - s consists of English letters, digits, symbols, and spaces.
 */

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int lastIndex[256]; 
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLen = 0;
    int start = 0;  

    for (int end = 0; s[end] != '\0'; end++) {
        unsigned char currentChar = (unsigned char)s[end];

        if (lastIndex[currentChar] >= start) {
            start = lastIndex[currentChar] + 1;  
        }

        lastIndex[currentChar] = end;  
        int windowLen = end - start + 1;
        if (windowLen > maxLen) {
            maxLen = windowLen;
        }
    }

    return maxLen;
}

void test(char* input) {
    int result = lengthOfLongestSubstring(input);
    printf("Input: \"%s\"\n", input);
    printf("Output: %d\n", result);
    printf("-----------------------\n");
}

int main() {
    test("abcabcbb");  
    test("bbbbb");    
    test("pwwkew");   
    test("");          
    test("aab");      
    test("dvdf");      

    return 0;
}
