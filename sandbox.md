Some important notes from my programming experience

How to properly use INT_MIN and INT_MAX? Knowing the limits and safety practice.

Avoid integer overflows. Make sure that you operate on INT_MIN/INT_MAX properly

`
//This can cause overflow
sum = (a+b);
// -> Always check for overflows: Lemma -> (a+b) <= INT_MAX;
sum = (a > INT_MAX - b) ? -1 : (a+b);
`
