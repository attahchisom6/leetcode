#!/usr/bin/node

const fizzBuzz = (n) => {
  let msg = '';
  let num = 1;

  while (num <= n) {
    if (!(num % 3) && num % 5)
      msg += ', Fizz';
    else if (num % 3 && !(num % 5))
      msg += ', Buzz';
    else if (!(num % 3) && !(num % 5))
      msg += ', FizBuzz';
    else {
      if (num === 1)
        msg += String(num);
      else if (num === n)
        msg += `, ${num}`;
      else
        msg += `, ${num}`;
    }
    num++;
  }
  console.log(msg);
}

fizzBuzz(23);
 console.log('------------------');
fizzBuzz(27);
console.log('------------------');
fizzBuzz(100);

