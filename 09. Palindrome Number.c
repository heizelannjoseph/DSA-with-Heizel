/*
Problem: Palindrome Number

Given an integer x, return true if x is a palindrome, and false otherwise.

A palindrome is a number that reads the same forward and backward.

Constraints:
-2^31 <= x <= 2^31 - 1
*/

bool isPalindrome(int x) {
    int temp=x;
    int rev=0;
    if(temp<0)
    {
        return false;
    }

    while(temp!=0)
    {
        int pop=temp%10;
        temp/=10;

        if((rev>(2147483647-pop)/10) || (rev<(-2147483648-pop)/10))
        {
            return false;
        }

        rev=(rev*10) + pop;
    }

    if(x==rev)
    {
        return true;
    }
    else
    {
        return false;
    }
}
