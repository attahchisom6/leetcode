#!/usr/bin/node

/**
 * sort using dotch flag algprithm
 */

const sortColors = (nums) => {
  let low = 0, mid = 0, high = nums.length - 1;

  while (mid <= high) {
    if (nums[mid] === 0) {
      [nums[low], nums[mid]] = [nums[mid], nums[low]];
      low++;
      mid++;
    } else if (nums[mid] === 1) {
      mid++;
    } else {
      [nums[high], nums[mid]] = [nums[mid], nums[high]];
      high--;
    }
  }
  return nums;
}

arr1 = [2, 1, 0];
arr2 = [2,0,2,1,1,0];
arr3 = [2,0,1];
console.log(sortColors(arr1));
console.log(sortColors(arr2));
console.log(sortColors(arr3));
