#!/usr/bin/env node

const revStr = (str) => {
    return str.split('').reverse().join('');
}

const sumLongNums = (str1, str2) => {
    let result = '', carryOver = 0;
    let p = str1.length - 1;
    let k = str2.length - 1;

    while (p >= 0 || k >= 0 || carryOver) {
        let dig1 = p >= 0 ? parseInt(str1[p]) : 0;
        let dig2 = k >= 0 ? parseInt(str2[k]) : 0;
        let sum = dig1 + dig2 + carryOver;
        carryOver = Math.floor(sum / 10);
        sum = sum % 10;
        result += sum;
        p--;
        k--;
    }
    return revStr(result);
}

console.log(sumLongNums('123', '456'));
console.log(sumLongNums('125', '456'));
console.log(sumLongNums('12565829', '456'));
console.log(sumLongNums('456', '12565829'));