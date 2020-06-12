#include <stdio.h>
/*
 recursive definition
 sum(n) = 0 if n=0 or sum(n-1)+n if n>0
 
 better use n*(n+1)/2 as it takes O(1) constant time.
 this is tail recursion
*/

//limited by stack depth, will give seg fault for large numbers
//This takes O(n) time and O(n) space
unsigned long sum_recursive(unsigned int n)
{
    if (n == 0)
    {
        return 0;
    }
    return sum_recursive(n - 1) + (unsigned long)n;
}

// this gives right answer for even largest 32-bit integer 2^32-1
//type casting needed at the n+1.
unsigned long sum_constant_time(unsigned int n)
{
    return (n * ((unsigned long)n + 1)) / 2;
}

int main()
{
    printf("%ld ", sum_constant_time(4294967295));

    return 0;
}
