#include <stdio.h>
/*
m^n = m^(n-1)*m if n>0 or 1 if n==0
This is nested recursion

the number of calling can be halved by checking if the n is odd or even.
if even: power(m*m,n/2)
if odd: m*power(m*m,(n-1)/2)
*/

//here the number of multiplications are n
unsigned long power(unsigned int m, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    return power(m, n - 1) * (unsigned long)m;
}

//here the number of multiplications are n/2 by checking if n is odd/even
unsigned long power_optimised(unsigned int m, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        return power_optimised(m * m, n / 2);
    }
    else
    {
        return (unsigned long)m * power_optimised(m * m, (n - 1) / 2);
    }
}

int main()
{
    printf("%lu ", power(3, 2));
    printf("%lu ", power_optimised(3, 3));
    printf("%lu ", power_optimised(3, 2));

    return 0;
}
