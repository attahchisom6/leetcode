#!/usr/bin/env node

/**
 * trys to sort an an input array of increaing order in one pass
 * and returns an array of incrsing order of squared elements
 */

const sortSquares = (nums) => {
    const n = nums.length;
    let result = new Array(n);
    let skip = 0;

    while (skip < n && nums[skip] < 0)
        skip++;

    console.log(`skip here: ${skip}`)
    let neg = skip - 1;
    let pos = skip;
    let k = 0;
    while (neg >= 0 && pos < n) {
        if (nums[neg] * nums[neg] < nums[pos] * nums[pos]) {
            result[k++] = nums[neg] * nums[neg];
            neg--;
        } else {
            result[k++] = nums[pos] * nums[pos];
            pos++;
        }
    }

    // fill in the remaining negative number
    while (neg >= 0) {
        result[k++] = nums[neg] * nums[neg];
        neg--;
    }
    
    while (pos < n) {
        result[k++] = nums[pos] * nums[pos];
        pos++;
    }

    return result;
}

const arr1 = [-22, -5, -3, 1, 2, 4, 10];
console.log(sortSquares(arr1));

const nums1 = [-4,-1,0,3,10];
const nums2 = [-7,-3,2,3,11];
const nums3 = [-10000,-9999,-7,-5,0,0,10000];
const nums4 = [-10000, 2, 0, -9999, 10000];

console.log(sortSquares(nums1)); // Output: [0,1,9,16,100]
console.log(sortSquares(nums2)); // Output: [4,9,9,49,121]
console.log(sortSquares(nums3)); // Output: [0,0,25,49,99980001,100000000,100000000]
console.log(sortSquares(nums4));