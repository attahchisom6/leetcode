const sort_arr = (arr1, arr2) => {
  let like_items = [];
  let rest_items = [];
  
  arr2.forEach((item) => {
    if (item < 0) {
      item = 0;
    }

    if (item > 1000) {
      item = 1000;
    }

    arr1.forEach((num) => {
      if (num < 0) {
        num = 0;
      }

      if (num > 1000) {
        num = 10000;
      }

      if (num === item) {
        like_items.push(num);
      }
    });
  });

  // Find elements in arr1 that are not in arr2
  arr1.forEach((num) => {
    if (!arr2.includes(num)) {
      rest_items.push(num);
    }
  });

  // Sort the rest_items
  rest_items.sort((a, b) => a - b);

  return like_items.concat(rest_items);
}

let arr1 = [2,3,1,3,2,4,6,7,9,2,19];
let arr2 = [2,1,4,3,9,6];

console.log(sort_arr(arr1, arr2));

arr1 = [28,6,22,8,44,17];
arr2 = [22,28,8,6];
console.log(sort_arr(arr1, arr2));
