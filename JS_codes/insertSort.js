#!/usr/bin/bode

// Note both methods seen here works for me

/**
 * insertSort - sorts the array using insert algorithm
 * where the first element is assumed to be sorted
 * @arr: arr to sort
 *
 * Returm: sorted array
 */

/*const insertSort = (arr) => {
  let k, p;

  for (p = 1; p < arr.length; p++) {
    let current = arr[p];

    let k = p - 1; // last element of sorted array
    while (k >= 0 && arr[k] > current) {
      arr[k + 1] = arr[k];
      k--;
    }
    arr[k + 1] = current;
  }
  return arr;
}*/

const insertSort = (arr) => {
  let k, p, size = arr.length - 1;

  k = 1;
  while (k < size) {

    for (p = size; p >= 0; p--) {
      if (arr[p] > arr[p + 1])
        [arr[p], arr[p + 1]] = [arr[p + 1], arr[p]];
    }
    k++;
  }
  return arr;
}

const arr = [2, 4, 11, 5, 3, 7, 88, 27, 40];
console.log(insertSort(arr));
