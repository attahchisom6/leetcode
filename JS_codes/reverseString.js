/*
 * Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.
*/

// Solution


const reversedFirstK = (s, start, end) => {
  // serves to reverse a string of length k
  let reversed = '';

  while (start <= end) {
    reversed += s[end];
    end--;
  }
  return reversed;
}

const reversedString = (s, k) => {
  let result = '';
  for (let i = 0; i < s.length; i += 2*k) {
    reversed = reversedFirstK(s, i, Math.min(i + k - 1, s.length - 1))
    result += reversed;
    result += s.substring(i + k, Math.min(i + 2*k, s.length));
  }
  return result;
}

result = reversedString('abcdefg', 2)
console.log(result)
