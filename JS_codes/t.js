f = (s) => {
  let frt = 0, brk = 0;
  let res = exp = '';
  for (let char of s) {
    if (char === '(') {
      frt++;
      res += char;
    } else if (char === ')') {
      brk++;
      break;
    }
    //char++;
  }
  if ((frt - brk) === 0)
    exp = res;;
  return exp;
}

const s = '((hello)()(()))';
console.log(f(s));
