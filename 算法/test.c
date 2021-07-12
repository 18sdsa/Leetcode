#include <stdio.h>

int main()
{
    int i = 0;
    int sum = 0;
    int n = 100;
    while (sum < n)
    {
        sum += ++ i;
        printf("%d\n",sum);
    }
    
}