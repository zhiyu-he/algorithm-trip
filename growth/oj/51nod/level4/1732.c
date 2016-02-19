#include <stdio.h>
#include <string.h>

char sample[10002];
int n;
long q;


int match(int a, int b)
{
    int len = 0;
    while (a < n && b < n)
    {
        if (sample[a] == sample[b])
        {
            len++;
            a++;
            b++;
        }
        else
        {
            break;
        }
    }
    return len;
}

int main()
{   
    scanf ("%d", &n);
    getchar();
    gets(sample);
    scanf ("%ld", &q);
    while (q--)
    {
        int a, b;
        scanf ("%d %d", &a, &b);
        printf ("%d\n", match(a, b));
    }
    return 0;
}
