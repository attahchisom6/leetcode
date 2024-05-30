#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* revStr - function to reverse a string
@str: pointer to strimg we wish to reverse
rETURN: Pointer to the reversed string
 */

char *revStr(char *str)
{
    int k, end, p = 0;
    char *result;

    k = 0;
    while (str[k] != '\0')
        k++;

    result = malloc((k + 1) * sizeof(char));
    if (!result)
        return NULL;

    end = k -1;
    while (end >= 0) {
        result[p++] = str[end];
        end--;
    }
    result[p] = '\0';
    return result;
}

/**
* add_long_nums - dunction to add long numbers character wise
@str1: first string
@str2: second string
Return: a pointer to the added result
*/

char *sum_long_nums(char *str1, char *str2)
{
    char *result;
    int k = strlen(str1), p = strlen(str2);
    int carryOver = 0, i = 0;
    int maxLen;

    maxLen = k > p ? k : p;
    result = malloc((maxLen + 1) * sizeof(char));
    if (!result)
        return NULL;
    k--, p--;
    while (k >= 0 || p >= 0 || carryOver)
    {
        int dig1, dig2, sum;

        dig1 = k >= 0 ? str1[k] - '0' : 0;
        dig2 = p >= 0 ? str2[p] - '0' : 0;
        sum = dig1 + dig2 + carryOver;
        carryOver = sum / 10;
        sum = sum % 10;
        result[i++] = sum + '0';
        p--;
        k--;
    }
    result[i] = '\0';
    char *processed = revStr(result);
    free(result);
    return (processed);
}

int main(void)
{
    char *result = sum_long_nums("555", "7777");
    printf("long sums: %d + %d = %s\n", 555, 7777, result);
    char *result1 = sum_long_nums("7777", "555");
    printf("long sums: %d + %d = %s\n", 555, 7777, result1);
    free(result);
    free(result1);
    return (0);
}