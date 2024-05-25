#!/usr/bin/node

const resetMap = (freq, chars) => {
  for (const char of chars)
    freq.set(char, 0);
}
const uniqueStr = (words, chars) => {
  const freq = new Map();
  const goodStr = [];

  resetMap(freq, chars);

  for (const word of words) {
    let isValidWord = true, isUnique = true;

    for (const char of word) {
      if (!chars.includes(char)) {
        isValidWord = false;
        break;
      }
    }

    if (!isValidWord)
      continue;

    for (const char of word) {
      if (freq.has(char))
        freq.set(char, freq.get(char) + 1);
    }

    for (const char of word) {
      const val = freq.has(char) ? freq.get(char) : 0;
      if (val >= 2) {
        isUnique = false;
        break;
      }
    }

    if (!isUnique)
      continue;
    goodStr.push(word);
    console.log([...freq]);
    resetMap(freq, chars);
  };
  return goodStr.join('').length;
}

const words = ["good", "house", "cat", "hat", "attach"];
const chars = "attach";
console.log(uniqueStr(words, chars));
