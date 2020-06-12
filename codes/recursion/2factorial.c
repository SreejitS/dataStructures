#include <stdio.h>
/*
fact(n) = fact(n-1)*n if n>0 or 1 if n == 0
This is tail recursion
*/

//large number problematic
//takes O(n) time and O(n) space 
unsigned long factorial_recursive(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    return factorial_recursive(n - 1) * (unsigned long)n;
}

int main()
{
    printf("%lu ", factorial_recursive(25));

    return 0;
}
