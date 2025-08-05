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

Constraints:
0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/

int myAtoi(char* s) {
    int i=0;
    int sign=1;
    long result=0;

    while(s[i]==' ')
    {
        i++;
    }

    if(s[i]=='+' || s[i]=='-')
    {
        if(s[i]=='-')
        {
            sign=-1;
        }
    i++;
    }

    while(s[i]>='0' && s[i]<='9')
    {
        result=result*10 + (s[i]-'0');

        if(sign==1 && result>2147483647)
        {
            return 2147483647;
        }
        if(sign==-1 && result>2147483648)
        {
            return -2147483648;
        }
    i++;
    }

    return (int)(sign * result);
}
