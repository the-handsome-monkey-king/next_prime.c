/*
 * next_prime.c
 *
 * Find the next prime number that comes after
 * the user's submitted n, up to 1998, whose
 * next prime is 1999.
 *
 * Required linked libraries: math
 *
 * author: Ryan Morehouse
 * license: MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN 1
#define MAX 1998


void error_msg()
{
  printf("Usage: next_prime.o [n]\n");
  printf("[n] is a positive integer less than 1999\n");
  exit(EXIT_FAILURE);
}

int isPrime(int number)
{
  if(number < 2)
  {
    printf("Error in isPrime(): arg must be > 1\n");
    exit(EXIT_FAILURE);
  }

  int is_prime_local = 1;
  if(number > 2)
  {
    double max_range = ceil(sqrt((double)number));
    int i = 2;
    while(is_prime_local)
    {
      if(number % i == 0)
        is_prime_local = 0;
      else if(i > max_range)
        break;
      else
        i += 1;
    }
  }

  return is_prime_local;
}


int main(int argc, char *argv[])
{
  // verify there is an arg
  if(argc < 2)
    error_msg();

  // verify arg is within limits
  int n = atoi(argv[1]);
  if(n < MIN || n > MAX)
    error_msg();

  // simple cases
  if(n == 1)
  {
    printf("2\n");
    return 0;
  }
  else if(n == 2)
  {
    printf("3\n");
    return 0;
  }

  // iteration flag
  int prime_found = 0;

  // test values
  int test_max = n * 2;
  int i = n + 1;

  while(prime_found == 0)
  {
    if(i == test_max)
    {
      printf("There has been a fatal programming error.\n");
      printf("A prime should have been found but was not.\n");
      exit(EXIT_FAILURE);
    }
    prime_found = isPrime(i);
    if(prime_found)
      break;
    else if(i % 2 == 0)
      i += 1; // i is even, go to next odd
    else
      i += 2; // i is odd, go to next odd
  }

  printf("%d\n", i);
  return 0;
}

