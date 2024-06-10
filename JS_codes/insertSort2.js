#!/usr/bin/node

/**
 * insertSort - sorts an arrauy in place using insertion algprithm
 * @arr: the array in question
 * 
 * Return: sorted array
 */

const InsertSort = (arr) => {
    let k, p;
    let size = arr.length - 1;

    p = 1;
    while (p < size) {
        for (k = size; k >= 0; k--) {
            if (arr[k] > arr[k + 1])
                [arr[k], arr[k + 1]] = [arr[k + 1], arr[k]];
        }
        p++;
    }
    return arr;
}

const arr = [1, 3, 32, 4, 17, 23];
console.log(InsertSort(arr))