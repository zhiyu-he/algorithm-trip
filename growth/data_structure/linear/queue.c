#include <stdio.h>

struct queue 
{
  int data[100];
  int head; 
  int tail;
};

int main()
{
  int arr[] = {6, 3, 1, 7, 5, 8, 9, 2, 4};
  struct queue q;
  // init queue;
  q.head = 0;
  q.tail = 0;

  for (int i = 0; i < 9; i++)
  {
    q.data[q.tail] = arr[i];
    q.tail++;
  }
  
  while (q.head < q.tail)
  {
    printf("%d\t", q.data[q.head]);
    q.head++;
    q.data[q.tail] = q.data[q.head];
    q.tail++;
    q.head++;
  }
  return 0;
}
