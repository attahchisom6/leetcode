/**
 * Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.



Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"


Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself
*/

const sumLongNums = (str1, str2) => {
  let shortest, longest;
  let result = '';
  let k, carryOver = 0;

  if (str1.length > str2.length) {
    longest = revStr(str1);
    shortest = revStr(str2);
  } else {
    longest = revStr(str2);
    shortest = revStr(str1);
  }

  k = 0;
  while (k < shortest.length) {
    let num1 = parseInt(shortest[k]);
    let num2 = parseInt(longest[k]);
    let sum = num1 + num2 + carryOver;
    carryOver = Math.floor(sum / 10);
    sum = sum % 10;

    result += sum;
    k++;
  }


  // add remaining digits from longest
  while (k < longest.length) {
    let num2 = parseInt(longest[k]);
    let sum = num2 + carryOver;
    carryOver = Math.floor(sum / 10);
    sum = sum % 10;
    result += sum;
    k++;
  }

  if (carryOver > 0)
    result += carryOver;

  return revStr(result);
}

const revStr = (str) => {
  return str.split('').reverse().join('')
}

console.log(sumLongNums('123', '456'));
console.log(sumLongNums('125', '456'));
console.log(sumLongNums('12565829', '456'));
console.log(sumLongNums('456', '12565829'));
