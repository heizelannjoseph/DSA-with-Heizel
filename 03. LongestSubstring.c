/*
 * Problem: Longest Substring Without Repeating Characters
 *
 * Given a string s, find the length of the longest substring without repeating characters.
 
 * Constraints:
 * - 0 <= s.length <= 5 * 10^4
 * - s consists of English letters, digits, symbols, and spaces.
 */

int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];  
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLen = 0;
    int start = 0;  

    for (int end = 0; s[end] != '\0'; end++) {
        if (lastIndex[(unsigned char)s[end]] >= start) {
            start = lastIndex[(unsigned char)s[end]] + 1;
        }
        lastIndex[(unsigned char)s[end]] = end;
        int windowLen = end - start + 1;
        if (windowLen > maxLen) {
            maxLen = windowLen;
        }
    }

    return maxLen;
}
