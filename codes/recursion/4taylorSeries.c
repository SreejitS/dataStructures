#include <stdio.h>
/*
e^x = 1 + (x/1) + (x^2/2!) + (x^3/3!) + .... n times

e(x,n) = 1, n=0 or r=e(x,n-1); p = p*x; f = f*n

*/

double e(unsigned int x, unsigned int n)
{
    static double power = 1;
    static double fact = 1;

    if (n == 0)
    {
        return 1;
    }
    double result = e(x, n - 1);
    power = power * x;
    fact = fact * n;
    return (result + power / fact);
}

double e_horner_formula(unsigned int x, unsigned int n)
{
    static double sum = 0;

    if (n == 0)
    {
        return sum;
    }
    sum = 1 + x * sum / n;
    e_horner_formula(x, n - 1);
}

int main()
{
    printf("%lf ", e(1, 10));
    printf("%lf ", e_horner_formula(1, 10));

    return 0;
}
