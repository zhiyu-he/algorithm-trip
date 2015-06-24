#include <stdio.h>
#include <stdlib.h>

long long capacity; // 船容量
int N; // 人数

long long person[10001]; 

void merge (long long arr[], long begin, long mid, long end);

void divide(long long arr[], long begin, long end);


int min_boat (long long arr[], long long cap, int n)
{
  int left  = 1;
  int right = n;
  int size = 0;

  
  while (left < right)
    {
      if (arr[left] + arr[right] <= cap)
        {
          left++;
          right--;
          size++;
        }
      else
        {
          size++;
          right--;
        }
    }
  if (left == right)
    size++;
  
  return size;
}

int main()
{
  scanf ("%d %lld", &N, &capacity);

  int i;
  for (i = 1; i <= N; i++)
    scanf ("%lld", &person[i]);

  divide (person, 1, N);

  printf ("%d\n", min_boat (person, capacity, N));


  //for (i = 1; i <= N; i++)
    //    printf ("%lld ", person[i]);
  
  return 0;
}


void merge(long long arr[], long begin, long mid, long end)
{
  long n1 = mid - begin + 1;
  long n2 = end - mid;

  long long  *l1 = (long long *) malloc (sizeof (long long) * n1);
  long long *l2 = (long long *) malloc (sizeof (long long) * n2);
  
  long i, j, k;
  for (i = 0; i < n1; i++)
    {
      l1[i] = arr[begin + i];
    }
  for (j = 0; j < n2; j++)
    {
      l2[j] = arr[mid + 1 + j];
    }
  
  i = j = 0;
  k = begin;
  while (i < n1 && j < n2)
    {
      if (l1[i] < l2[j])
        {
          arr[k++] = l1[i++];
        } 
      else 
        {
          arr[k++] = l2[j++];
        }
    }
  while (i < n1)
    {
      arr[k++] = l1[i++];
    }
  while (j < n2)
    {
      arr[k++] = l2[j++];
    }

  free(l1);
  free(l2);
}


void divide(long long arr[], long begin, long end)
{
  long mid;
  if (begin < end)
    {
      mid = begin + (end - begin) / 2;
      divide (arr, begin, mid);
      divide (arr, mid + 1, end);
      merge (arr, begin, mid, end);
    }
}
