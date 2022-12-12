#include <stdio.h>

#define ll long long 

int main()
{
  ll xn;
  ll yn;
  ll xn1;
  ll yn1 = 0;
  xn = 15;
  yn = 21;

 while(yn1 < 1000000000000)
 {
   xn1 = 3*xn + 2*yn - 2;
   yn1 = 4*xn + 3*yn - 3;
   xn = xn1;
   yn = yn1;
 }
 printf("%lld\n",xn1);
 return 0;
}
