#include <stdio.h>
long long int fact(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
    {
        return (n * fact(n - 1));
    }
}
int main()
{while(1){
    int n;
    printf("Please enter number to calculate factorial?\t");
    scanf("%d", &n);
    printf("%lld is your result\n", fact(n));

}
return 0;
}
