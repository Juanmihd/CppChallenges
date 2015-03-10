#include<iostream>
#include <vector>


int prime_number[296] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
811, 821, 823, 827, 829, 839, 853, 857, 859, 863,
877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013,
1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069,
1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151,
1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223,
1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291,
1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373,
1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451,
1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511,
1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583,
1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657,
1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733,
1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811,
1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889,
1901, 1907, 1913, 1931, 1933, 1949 };

std::vector<int> cool_prime_numbers;
std::vector<int> prime_numbers;


//This one is binary search (recursion)
bool is_in_set_bs(int number, int* set, int size_set){
  bool is_in_set = false;

  // Stop recursion
  if (size_set == 1){
    return (number == set[0]);
  } 

  //check middle point
  int middle_point = size_set / 2;
  is_in_set = (number == set[middle_point]);
  
  if (!is_in_set){
    bool look_left;
    //decide where to look for it later
    look_left = (number < set[middle_point]);
    //look for it in the half subset
    if (look_left){
      if (middle_point > 0)
        is_in_set = is_in_set_bs(number, set, middle_point);
    }
    else{ // look right
      if (size_set - (middle_point + 1) > 0)
        is_in_set = is_in_set_bs(number, &set[middle_point + 1], size_set - (middle_point + 1));
    }
  }

  return is_in_set;
}

// Linear search for the prime number
bool is_prime_number(int number){
  bool is_prime = false;
  for (int i = 0; i < 296 && !is_prime; ++i){
    is_prime = (number == prime_number[i]);
  }
  return is_prime;
}

// Check if a number has repeated digits
bool has_repepated_digits(int number, bool* digits){
  int our_number = number;
  while (our_number > 0){
    int last_digit = our_number % 10;
    if (digits[last_digit])
      return true;
    else
      digits[last_digit] = true;
    our_number = our_number / 10;
  }
  return false;
}

// Check if a number has repeated digits
bool has_repepated_digits(int number){
  bool digits[10];
  for (int i = 0; i != 10; ++i){
    digits[i] = false;
  }
  int our_number = number;
  while (our_number > 0){
    int last_digit = our_number % 10;
    if (digits[last_digit])
      return true;
    else
      digits[last_digit] = true;
    our_number = our_number / 10;
  }
  return false;
}

// Cool binary search for the prime number
bool is_prime_number_bs(int number){
  return is_in_set_bs(number, &prime_number[0], 296);
}

void generate_cool_prime_numbers(){
  int a = 0;
  cool_prime_numbers.push_back(1);
  for (int i = 2; i != 1951; ++i){
    bool is_prime = true;
    //check with the previous prime numbers with the sivier aristotle method
    int j = 0; 
    while (is_prime){
      int rest = i % prime_numbers[j];
      if (rest == 0)
        is_prime = false;
      ++j;
    }
    if (is_prime){
      prime_numbers.push_back(i);
      if (!has_repepated_digits(i))
        cool_prime_numbers.push_back(i);
    }
  }
}

int main(int argc, char **argv){
  int x, y, z;
  int x2, second_number_limit;
  int sum;
  long long start = __rdtsc();
  bool* digits = new bool[10];
  /*
  printf("TEST-1\n");
  //Generate prime numbers (with different digits) instead of cheating!
  generate_cool_prime_numbers();

  printf("TEST\n");
  for (int i = 0; i < prime_numbers.size(); ++i){
    printf("%i\n", prime_numbers[i]);
  }
  printf("TEST2\n");
  */
  for (x = 1; x < 44; ++x){
    //Initialize our vector of bool
    bool digits_repeated = false;
    for (int i = 0; i != 10; ++i){
      digits[i] = false;
    }
    //obtain the x2
    x2 = x*x;
    //check if the digits are different in x2
    digits_repeated = has_repepated_digits(x2, digits);

    if (!digits_repeated){
      second_number_limit = 1951 - x2;
      y = 0;
      bool temp_digits[10];
      for (int i = 0; i != 10; ++i)
        temp_digits[i] = digits[i];
      while (y < 296){
        for (int i = 0; i != 10; ++i)
          digits[i] = temp_digits[i];
        digits_repeated = has_repepated_digits(prime_number[y], digits);
        if (!digits_repeated){
          z = 1951 - x2 - prime_number[y];
          if (z > prime_number[y])
          if (is_prime_number_bs(z)){ // X is square, Y is prime and Z is prime
            digits_repeated = has_repepated_digits(z, digits);
            if (!digits_repeated){
              printf("x2 = %i, y = %i, z = %i \n", x2, prime_number[y], z);
            }
          }
        }
        else{
         // printf("x2 = %i, y = %i <==== REPEATED!!!\n", x2, prime_number[y]);
        }
        ++y;
      }
    }
  }

  long long end = __rdtsc();
  printf("I've finished the execution with time %lld", end-start);

  delete [] digits;
}