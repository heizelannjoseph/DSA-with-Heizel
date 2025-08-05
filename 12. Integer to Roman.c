/*
Problem: Integer to Roman

Seven different symbols represent Roman numerals with the following values:
Symbol  Value
I       1
V       5
X       10
L       50
C       100
D       500
M       1000

Rules for conversion:
1. Roman numerals are formed by appending conversions of decimal place values from highest to lowest.
2. If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted, append it, and continue converting the remainder.
3. If the value starts with 4 or 9, use the subtractive form:
   - 4  = IV
   - 9  = IX
   - 40 = XL
   - 90 = XC
   - 400= CD
   - 900= CM
4. Powers of 10 (I, X, C, M) can be repeated at most 3 times. Symbols for 5 (V), 50 (L), and 500 (D) cannot be repeated.

Constraints:
1 <= num <= 3999
*/

char* intToRoman(int num) {
    static char roman[20];
    int pos=0;
    int i=0;

    int values[]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV","I"};
    while(num>0)
    {
        while(num>=values[i])
        {
            strcpy(roman + pos, symbols[i]);
            pos+=strlen(symbols[i]);
            num-=values[i];
        }
        i++;
    }
    roman[pos]='\0';
    return roman;
}
