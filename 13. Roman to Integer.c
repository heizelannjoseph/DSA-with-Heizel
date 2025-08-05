/*
Problem: Roman to Integer

Roman numerals are represented by seven different symbols:
Symbol  Value
I       1
V       5
X       10
L       50
C       100
D       500
M       1000

Rules:
1. Roman numerals are usually written from largest to smallest from left to right.
2. However, certain numbers use subtractive notation:
   - 4  = IV (1 before 5)
   - 9  = IX (1 before 10)
   - 40 = XL (10 before 50)
   - 90 = XC (10 before 100)
   - 400= CD (100 before 500)
   - 900= CM (100 before 1000)
3. These subtractive forms occur only in the above cases.

Constraints:
1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
*/

#include <stdio.h>

int romanToInt(char* s) {
    int values[256] = {0};  
    int result = 0;         
    int i = 0;             

    values['I'] = 1;
    values['V'] = 5;
    values['X'] = 10;
    values['L'] = 50;
    values['C'] = 100;
    values['D'] = 500;
    values['M'] = 1000;

    while (s[i] != '\0') {
        int current = values[(unsigned char)s[i]];     
        int next = values[(unsigned char)s[i + 1]];      

        if (current < next) {
            result += (next - current);  
            i += 2;                     
        }
        else {
            result += current; 
            i += 1;            
        }
    }
    return result;
}

int main() {
    printf("Input: III, Output: %d\n", romanToInt("III"));
    printf("Input: LVIII, Output: %d\n", romanToInt("LVIII"));
    printf("Input: MCMXCIV, Output: %d\n", romanToInt("MCMXCIV"));
    return 0;
}
