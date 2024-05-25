/**
 * logo
58 minutes remaining

Question 1

Question 2

Exit Session
Description
Submissions
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 */


/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
const sortColors = function(nums) {
  let k = 0, p;
  let isIncreasing = true;
  
  for (p = 0; p < nums.length; p++) {
    if (nums[p + 1] !== undefined)
    {
      if (nums[p] > nums[p + 1])
      {
        isIncreasing = false;
        break;
      }
    }
  }
  
  if (isIncreasing)
    return nums;

  while (k < nums.length) {
    let temp;

    if (nums[k + 1] !== undefined) {
      if (nums[k] > nums[k + 1]) {
        temp = nums[k];
        nums[k] = nums[k + 1];
        nums[k + 1] = temp;
      }
    }
    k++;
  }
  nums = sortColors(nums);
  return nums;
}

arr1 = [2, 1, 0];
arr2 = [2,0,2,1,1,0];
arr3 = [2,0,1];
console.log(sortColors(arr1));
console.log(sortColors(arr2));
console.log(sortColors(arr3));

// Time Complexity: O(n^2)
// Space Complexity: O(n)
