#include <stdio.h>
#include <stdlib.h>

/*
* sort_squares: function to sort an an array in O(n) time complexity
* @nums: array arranged in strictly increasing order of magnitude
*
* Return: square of each element in the array in a strictly increasing
  order of magnitude
*/


int *sort_squares(int nums[], int n)
{
    int k, pos, neg;
    int *result;
    int skip = 0;


    result = malloc(n * n * sizeof(int));
    if (!result)
    {
        printf("memory allocation failed\n");
        exit(1);
    }

    while (skip < n && nums[skip] < 0)
        skip++;

    neg = skip - 1;
    pos = skip;
    k = 0;

    while (neg >= 0 && pos < n)
    {
        if (nums[neg] * nums[neg] < nums[pos] * nums[pos])
        {
            result[k++] = nums[neg] * nums[neg];
            neg--;
        }
        else
        {
            result[k++] = nums[pos] * nums[pos];
            pos++;
        }
    }

    // fill in thr remauning negative numbers
    while (neg >= 0)
    {
        result[k++] = nums[neg] * nums[neg];
        neg--;
    }

    // fill in the remaining positive number
    while (pos < n) {
        result[k++] = nums[pos] * nums[pos];
        pos++;
    }

    return result;
}

int main(void) {
    int nums1[] = {-22, -5, -4, -3, 1, 2, 4, 10};
    int n = sizeof(nums1) / sizeof(nums1[0]), k;
    int *result = sort_squares(nums1, n);

    printf("[");
    for (k = 0; k < n; k++ )
    {
        if (k == n - 1)
        {
            printf("%d", result[k]);
        }
        else
            printf("%d, ", result[k]);
    }
    printf("]\n");
    free(result);
}