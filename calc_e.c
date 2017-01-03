/* A script to calculate the nth digit of euler's number.
It is precise up to the 20th digit before it runs into issues
regarding precision.*/

#include <stdio.h>
#include <math.h>

unsigned long factorial(int f);

int main(void){
  //This section reads in the number of digits necessary for e.
  int digits;
  printf("Please input the number of digits of e you would like to see:\n");
  scanf("%d", &digits);

  //Putting together the necessary precision.
  double digits2 = (double) digits + 1.0;
  double precision = (double) 1.0 / pow((double) 10.0, digits2);

  //Set up some preliminary variables.
  int n = 2;
  double approximation = 2.0;
  double prev_approx = 1.0;
  double error = approximation - prev_approx;

  /* A while loop because it is of indeterminate length.
  We're using the Taylor Series approximation of e^x at x = 1, and subtracting
  terms until the distance between the two is less than our required precision.
  */
  while (error > precision){
    prev_approx = approximation;
    approximation += ((double) 1.0 / (double) factorial(n));
    error = approximation - prev_approx;
    //printf("%lf\n", approximation);
    n++;
    //printf("%d\n", n);
  }

  //Print it out. Note that we have to use a long data type to prevent precision issues.
  double holder = approximation * pow(10, digits);
  long rev_digit = (long) holder % (long) 10;
  printf("The %dth digit is %li.\n", digits, rev_digit);
}

// This function calculate the factorial of number f. Returns an unsigned long.
unsigned long factorial(int f){
  if(f == 0){
    return (unsigned long) 0;
  }
  unsigned long ans = 1;
  for(int i = 1; i <= f; i++){
    ans = ans * i;
  }
  return ans;
}
