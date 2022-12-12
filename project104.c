
#include <stdio.h>
#include <math.h>

int main()
{
  int sum = 0;
  int sum1 = 0;
  int sum2 = 0;
  int count = 541;
  sum1 = (pow(1+sqrt(5),count) / pow(2,count));
  sum1 = sum1 * ((5 + sqrt(5)) / 10);
  sum2 = (pow((1-sqrt(5)),count) / pow(2,count));
  sum2 = sum2 * ((5-sqrt(5))/10);
  sum = sum1 + sum2 + 1;
  printf("%d\n",sum);
}
