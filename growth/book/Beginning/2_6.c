#include<stdio.h>
#include<time.h>

int main()
{
    printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
