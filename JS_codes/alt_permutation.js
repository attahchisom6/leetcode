const permutationOrder = (order, s) => {
  if (!s) return '';
  if (!order) return s;

  const charIndexMap = new Map();
  let result = '';

  // Map each character in 'order' to its index
  for (let i = 0; i < order.length; i++) {
    charIndexMap.set(order[i], i);
  }

  // Sort 's' based on the index mapping in 'order'
  const sortedS = Array.from(s).sort((a, b) => {
    const indexA = charIndexMap.get(a);
    const indexB = charIndexMap.get(b);
    return (indexA !== undefined ? indexA : Infinity) - (indexB !== undefined ? indexB : Infinity);
  });

  // Build the result string
  result = sortedS.join('');

  return result;
};

order = 'abedg';
s = 'gfdphazbe';
console.log(`result permutation: ${permutationOrder(order, s)}`);
