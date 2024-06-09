#!/usr/bin/node

/**
 * selectionSort - iterates through an arrsy linearly and sort in an asending order
 * @arr: the array to sorted
 * 
 * Return: a sorted aeeay
 */

const selectionSort = (arr) => {
    let last = arr.length - 1;
    
    while (last >= 0) {

        let p = 0;
        while (p < last) {
            if (arr[p] > arr[last]) {
                [arr[p], arr[last]] = [arr[last], arr[p]];
            }
            p++;
        }
        last--;
    }
    return arr;
}
    

arr = [1, 5, 9, 4, 7, 13, 8, 3];
console.log(selectionSort(arr));