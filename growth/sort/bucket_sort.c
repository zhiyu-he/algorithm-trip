#include <stdio.h>


int main()
{
    int n;
    scanf("%d", &n);
    
    int num[100];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", num[i]);    
    }
    printf("\n");

    int book[101];

    for(int i = 0; i < n; i++)
    {
        book[num[i]] += 1;
    }

    for(int i = 0; i < 101; i++)
    {
        if(book[i] > 0)
        {
            for(int j = 0; j < book[i]; j++)
            {
                printf("%d ", i);
            }
        }
    }

    return 0;
}
