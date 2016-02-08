#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 60000

char code[62] = {
    // 0-9 
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    // 
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', 
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z'
};


struct Case {
    int from;
    int to;
    char input[MAX_LENGTH];
    char *output;
};


int get_index_from_code(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    else if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 10;
    else
        return ch - 'a' + 36;
}

char * reverse(char *str)
{
    int len = strlen(str);
    char *new = (char *) malloc (sizeof(char) * len);
    int i = 0;
    while (len > 0)
    {
        new[i++] = str[len - 1];
        len--;
    }
    new[i] = '\0';
    return new;
}

void print_case(struct Case *c)
{
    printf ("%d %d %s\n", c->from, c->to, c->input);
}

char* conver(int from, int to, char *str)
{   
    if (from == to) return str;
    char *res = (char *) malloc (sizeof(char) * MAX_LENGTH);
    char *input = (char *) malloc (sizeof(char) * strlen(str));
    strcpy(input, str);
    int i, i_temp = 0, res_temp = 0, remainder = 0;
    while (strlen(input) != 0)
    {  
        char temp[MAX_LENGTH];
        remainder = 0;
        i_temp = 0;
        for (i = 0; i < strlen(input); i++)
        {
            // key point
            remainder = from * remainder + get_index_from_code(input[i]);
            if (remainder < to)
            {
                temp[i_temp++] = '0';
                continue;
            }
            else
            {
                temp[i_temp++] = code[remainder/to];
                remainder %= to;
            }
        }
        res[res_temp++] = code[remainder]; // 这个序列是反的
        for (i = 0; i < i_temp && temp[i] == '0'; i++);
        // 人肉copy下
        int start = 0;
        while (i < i_temp)
        {
            input[start++] = temp[i++];
        }
        input[start] = '\0';
    }
    res[res_temp] = '\0';
    res = reverse(res);
    return res;
}

int main()
{
    int n;
    scanf ("%d", &n);
    while (n--)
    {
        int from, to;
        char in[MAX_LENGTH];

        scanf ("%d %d %s", &from, &to, in);

        char *res = conver(from, to, in);

        printf ("%d %s\n", from, in);
        printf ("%d %s\n", to, res);
        printf ("\n");
    }
    return 0;
}
