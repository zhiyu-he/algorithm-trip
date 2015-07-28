#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10020
#define MAX_LEN  15
#define ALPHABET_SIZE 30
#define MAX_QUERY 10020

struct trie_node
{
  int index[MAX_SIZE];
  int size;
  struct trie_node* children[ALPHABET_SIZE];
};

char words[MAX_SIZE][MAX_LEN];
int answer[MAX_QUERY];

struct trie_node* create_trie_node ()
{
  struct trie_node*  p_node = (struct trie_node*) malloc (sizeof (struct trie_node));
  int i;
  for (i = 0; i < ALPHABET_SIZE; i++)
    p_node->children[i] = NULL;
  
  p_node->size = 0;
  return p_node;
}

void trie_insert (struct trie_node* root, char word[], int index)
{
  struct trie_node* node = root;
  int i = 0;
  while (word[i] != '\0')
    {
      if (node->children[word[i] - 'A'] == NULL)
        {
          node->children[word[i] - 'A'] = create_trie_node ();
        }
      node = node->children[word[i] - 'A'];
      i++;
    }
  node->index[node->size] = index;
  node->size += 1;
}

struct trie_node* trie_search (struct trie_node* root, char word[])
{
  struct trie_node* node = root;
  int i = 0;
  while (word[i] != '\0' && node != NULL)
    {
      node = node->children[word[i] - 'A'];
      i++;
    }
  return node;
}

void quick_sort (char str[], int i, int j)
{
  if (str == NULL || i > j)
    return;
  
  int left = i;
  int right = j;
  char base = str[i];
  char ts; // ts means temp_swap
  while (left != right)
    {
      while (str[right] > base && left < right)
        right--;
      while (str[left] <= base && left < right)
        left++;
      if (left < right)
        {
          ts = str[left];
          str[left] = str[right];
          str[right] = ts;
        }
    }

  str[i] = str[left];
  str[left] = base;

  quick_sort (str, i, left - 1);
  quick_sort (str, right + 1, j);
}


int main()
{
  
  char str_hash[MAX_LEN];
  int n;
  scanf ("%d", &n);
  getchar();

  int i;
  for (i = 0; i < n; i++)
    gets (words[i]);

  //  for (i = 0; i < n; i++)
  //    quick_sort (words[i], 0, strlen (words[i]) - 1);


  struct trie_node* root = create_trie_node ();
  
  for (i = 0; i < n; i++)
    {
      strcpy (str_hash, words[i]);
      quick_sort (str_hash, 0, strlen (str_hash) - 1);
      trie_insert (root, str_hash, i);
    }

  int q;
  scanf ("%d", &q);
  getchar();
  for (i = 0; i < q; i++)
    {
      char query[MAX_LEN];
      gets (query);
      strcpy (str_hash, query);
      quick_sort (str_hash, 0, strlen (str_hash) - 1);
      struct trie_node* node = trie_search (root, str_hash);
      if (node == NULL)
        {
          answer[i] = 0;
        }
      else
        {
          //          printf ("p->size: %d\n", node->size);
          answer[i] = node->size;
          int j;
          for (j = 0; j < node->size; j++)
            {
              //              printf ("ori: %s\n", words[node->index[j]]);
              //              printf ("current: %s\n", query);
              if (strcmp (words[node->index[j]], query) == 0)
                answer[i] -= 1;
            }
        }
    }

  for (i = 0; i < q; i++)
    printf ("%d\n", answer[i]);
  return 0;
}
