#include <stdio.h>
#include <string.h>

void findSmall(char *S)
{
    int n = strlen(S);
    char result[n];
    strcpy(result, S);

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        char temp[n];
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            if (S[i] != ch){temp[k++] = S[i];}
        }
        temp[k] = '\0';

        if (k > 0 && strcmp(temp, result) < 0){strcpy(result, temp);}
    }

    printf("%s\n", result);
}

int main()
{
    char S[1000];
    scanf("%s", S);
    findSmall(S);
    return 0;
}


// Created by zerri on 10/27/2024.

