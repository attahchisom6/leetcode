#!/usr/bin/node

const relativeSort = (arr1, arr2) => {
  const map = new Map();

  // create a map with elements in arr2 as key and their index as values
  arr2.forEach((num, index) => {
    map.set(num, index);
  });

  // rehaersh or adjust array 1 baseed on their index in arr2
  arr1.sort((a, b) => {
    const indexA = map.has(a) ? map.get(a) : arr2.length + a;
    const indexB = map.has(b) ? map.get(b) : arr2.length + b;
    return indexA - indexB;;
  });
  return arr1;
}

arr1 = [2,3,1,3,2,4,6,7,9,2,19];
arr2 = [22,28,8,6];
console.log(relativeSort(arr1, arr2))

a = [2,3,1,3,2,4,6,7,9,2,19];
b = [2,1,4,3,9,6];
