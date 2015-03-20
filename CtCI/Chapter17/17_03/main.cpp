/// This is a solution for the problem 3 of the chapter 17 of CtCI
//
// 17.3 Write an algorithm which computes the number of trailing zeros in n factorial

// This function will receive n and will return the number of zeros in the n factorial
// Will return -1 if n <= 0
int number_zeros_in_factorial(int n){
  //Check errors with n and return -1 if error
  if(n < 0) return -1;
  
  //Obtain n factorial (maybe use a hash table of factorials)
  unsigned int factorial = 1;
  for(unsigned int number = n; number > 1; --number)
    factorial*=number;
  
  //Parse the number, counting zeros
  int count = 0;
  while(factorial >= 0){
    unsigned int digit = factorial%10;
    if(factorial == 0)
      ++count;
    factorial = factorial/10;
  }
  
  return count;
}


// Other solution, count how many "10" has it.
// Count multiples of 10, (that at the same time are multiples of 2 and 5 at the same time)

int number_zeros_in_factorial_2(int n){
  //we have to count only how many multiples of 5 are there!
  if(n < 0) return -1;
  
  int count = 0;
  for (unsigned int i = 5; i < n; i*=5){
    count += n / i;
  }  
  return count;
}