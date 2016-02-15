#include <stdio.h>

long f[201];

int main()
{      
    int A, B, N, i;
    scanf ("%d %d %d", &A, &B, &N);
    
    if (N < 3)
    {
        printf("1\n");
        return 0;
    }
    // 计算循环节的长度
    f[1] = f[2] = 1;
    for (i = 3; i < 200; i++)
    {   
        /*
        long tmp_1 = A * f[i - 1];
        long tmp_2 = B * f[i - 2];
        while (tmp_1 < 0)
            tmp_1 += 7;
        while (tmp_2 < 0)
            tmp_2 += 7;
        f[i] = (tmp_1 % 7+ tmp_2 % 7) % 7;
        */
        f[i] = ((A * f[i - 1] + B * f[i - 2]) % 7 + 7) % 7;
        //printf ("f[%d] = %ld\n", i, f[i]);
        if (f[i] == 1 && f[i - 1] == 1) break;
    }
    //printf ("repeated: %d\n", i - 2);
    f[0] = f[i - 2];
    printf ("%ld\n", f[N % (i - 2)]);
    return 0;
}
