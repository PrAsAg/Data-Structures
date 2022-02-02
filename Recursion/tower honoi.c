#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void tower(int, char, char, char);
int main()
{
    int n;
    printf("Enter no. of disc?\t");
    scanf("%d", &n);
    tower(n, 'A', 'B', 'c');
    return 0;
}
void tower(int n, char frompeg, char topeg, char auxpeg)
{
    static int k = 0;
    if (n == 1)
    {
        printf("\n%d . Move disc %d from %c to %c", ++k, n, frompeg, topeg);
    }
    else
    {
        tower(n - 1, frompeg, auxpeg, topeg);
        printf("\n%d . Move disc %d from %c to %c", ++k, n, frompeg, topeg);
        tower(n - 1, auxpeg, topeg, frompeg);
    }
}
