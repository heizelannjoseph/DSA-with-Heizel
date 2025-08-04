/*
Problem: Zigzag Conversion

Given a string `s`, write it in a zigzag pattern on a given number of rows. 
After writing in this pattern, read line by line to generate the converted string.

Constraints:
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1 || numRows >= strlen(s)) {
        char* result = (char*)malloc(strlen(s) + 1);
        strcpy(result, s);
        return result;
    }

    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* lens = (int*)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc(strlen(s) + 1);
    }

    int row = 0;
    int goingDown = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        rows[row][lens[row]++] = s[i];
        if (row == 0 || row == (numRows - 1)) {
            goingDown = !goingDown;
        }
        row += goingDown ? 1 : -1;
    }

    char* result = (char*)malloc(strlen(s) + 1);
    int pos = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < lens[i]; j++) {
            result[pos++] = rows[i][j];
        }
    }
    result[pos] = '\0';

    for (int i = 0; i < numRows; i++) {
        free(rows[i]);
    }

    free(rows);
    free(lens);

    return result;
}

int main() {
    char s[] = "PAYPALISHIRING";
    int numRows = 3;
    char* result = convert(s, numRows);
    printf("%s\n", result);
    free(result);
    return 0;
}
