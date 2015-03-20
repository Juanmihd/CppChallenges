//This is a solution to the problem 01 of the chapter 17 of the book CtCI
// Swap two integers without using auxiliar variables


void swap_MINUS(int A, int B){
  A = A - B;     //-4 = 5 - 9
  B = B + A;    // 5 = 9 - 4
  A = B - A;     // 9 = 5 + 4
}

void swap_XOR(int A, int B){
  A = A ^ B;    0001  =  1001 ^ 1000
  B = A ^ B;    1001 = 0001 ^ 1000
  A = A ^ B;    1000  = 0001 ^ 1001
}