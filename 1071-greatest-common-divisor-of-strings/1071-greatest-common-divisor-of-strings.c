#include <string.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    while (b)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char *temp1 = (char *)malloc(len1 + len2 + 1);
    char *temp2 = (char *)malloc(len1 + len2 + 1);

    strcpy(temp1, str1);
    strcat(temp1, str2);

    strcpy(temp2, str2);
    strcat(temp2, str1);

    if (strcmp(temp1, temp2) != 0)
    {
        free(temp1);
        free(temp2);
        char *ans = (char *)malloc(1);
        ans[0] = '\0';
        return ans;
    }

    free(temp1);
    free(temp2);

    int g = gcd(len1, len2);

    char *ans = (char *)malloc(g + 1);
    strncpy(ans, str1, g);
    ans[g] = '\0';

    return ans;
}
