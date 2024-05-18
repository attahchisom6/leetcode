#!/usr/bin/env node

/**
 * In this code, we sort string s to follow a predefined permutation and shffle it so the order is always maintained
 */

const shuffleArray = (arr) => {
  if (!arr)
    return [];
  let k = arr.length - 1;
  while (k > 0) {
    const p = Math.floor(Math.random() * (k + 1));

    [arr[k], arr[p]] = [arr[p], arr[k]];
    k--;
  }
  return arr;
}

const permutationOrder = (order, s) => {
  const mapOrder = new Map();
  const orderedArray = [];
  const randomArray = [];

  if (!s)
    return '';
  if (!order)
    return s;

  for (let k = 0; k < order.length; k++) {
    mapOrder.set(order[k], k);
  }

  for (const char of s) {
    if (mapOrder.has(char))
      orderedArray.push(char);
    else
      randomArray.push(char);
  }

  orderedArray.sort((a, b) => {
    const indexA = mapOrder.has(a) ? mapOrder.get(a) : Infinity;
    const indexB = mapOrder.has(b) ? mapOrder.get(b) : Infinity;
    return indexA - indexB;
  });
  shuffleArray(randomArray);

  // insert element of randomArray, randomly around orderedArray
  randomArray.forEach((elem) => {
    const pos = Math.floor(Math.random() * (orderedArray.length + 1));
    orderedArray.splice(pos, 0, elem);
  });

  return orderedArray.join('');
}

order = 'abedg';
s = 'gfdphazbe';
console.log(`result permutation: ${permutationOrder(order, s)}`);
