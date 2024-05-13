/*
logo
59 minutes remaining

Question 1

Question 2

Exit Session
Description
Submissions
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/

// Solution

const sortSquares = (nums) => {
  let result = [];

  if (nums.length < 1 || nums.length > 104)
    return result;

  result = nums.map((elem) => {
    if (elem < -104)
      elem = -104;
    else if (elem > 104)
      elem = 104;
    return elem * elem
  }).sort((a, b) => a - b);

  return result;
}

const nums1 = [-4,-1,0,3,10];
const nums2 = [-7,-3,2,3,11];

console.log(sortSquares(nums1));
console.log(sortSquares(nums2));
