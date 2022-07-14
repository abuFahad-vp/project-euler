#include <bits/stdc++.h>

using namespace std;

long long sumfactor(int n)
{
    long long sum=0;
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    long long t=0;
    for(int i=220;i<10000;i++)
    {
        long long m = sumfactor(i);
        long long n = sumfactor(m);

        if(n==i)
        {
            if(i!=m)
            {
                t+=i;
            }
        }
        
    }
    printf("%lld\n",t);
}