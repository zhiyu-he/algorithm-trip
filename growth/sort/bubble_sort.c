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
	
	// control loop times = n - 1
	for(int i = 0; i < n - 1; i++)
	{	
		// e.g 第一次比较, 需要比较全部
		// e.g 第二次比较, 需要比较 n-1个元素
		for(int j = 0; j < n-i-1; j++)
		{
			if(num[j] > num[j+1])
			{
				int tmp = num[j];
				num[j] = num[j+1];
				num[j+1] = tmp;
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
    return 0;
}
