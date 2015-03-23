// This is a solution to the problem 18.1 of the book CtCI
//
// 18.1 Write a function that adds two numbers. You should not use + or any arithmetic operators.
//
//

int sum(int a, int b){
  if(b==0) return a;
  if(a==0) return b;
  int without_carry = a ^ b;
  int carry = (a & b) << 1;
  return sum(without_carry, carry);
}

