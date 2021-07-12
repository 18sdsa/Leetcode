#include <stdio.h>

void test(int &x)
{
    x = 1024;
}
int main() {
    int x = 1;
    test(x);
    printf("%d",x); 
}


