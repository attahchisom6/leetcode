/** 
 * You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

 

Example 1:

Input:  order = "cba", s = "abcd" 

Output:  "cbad" 

Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:

Input:  order = "bcafg", s = "abcd" 

Output:  "bcad" 

Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.

Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "bacd" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.

 

Constraints:

1 <= order.length <= 26
1 <= s.length <= 200
order and s consist of lowercase English letters.
All the characters of order are unique.
*/

const permutationOrder = (order, s) => {
  if (!s || s.length === 0)
    return '';

  if (!order || order.length === 0) {
    return s;
  }

  const map1 = new Map();
  const map2 = new Map();
  let orderBlueprint = '';
  const alphab = [
    'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
  ];
  let result = '';

  alphab.forEach((elem, index) => map1.set(elem, index));

  Object.entries(order).forEach(([index, elem]) => {
    orderBlueprint += map1.has(elem) ? map1.get(elem) : '';
  });
  console.log(`(orderBlueprint: ${orderBlueprint}`);

  let k = 0;
  while (k < orderBlueprint.length) {
    const orderElem = parseInt(orderBlueprint[k]);
    for (let p = 0; p < s.length; p++) {
      sElem = map1.has(s[p]) ? map1.get(s[p]) : -1;
      if (orderElem === sElem) {
        map2.set(orderElem, s[p]);
      }
    }
    k++;
  }

  map2.forEach((elem) => {
    result += elem;
  });

  for (i = 0; i < s.length; i++) {
    if (result.includes(s[i]))
      continue;
    result += s[i];
  }
  console.log(`map1: ${[...map1]}`);
  console.log(`map2: ${[...map2]}`);
  console.log(`input string s: ${s}, order: ${order}`);
  return result;
}

order = 'abedg';
s = 'gfdphazbe';
console.log(`result permutation: ${permutationOrder(order, s)}`);
