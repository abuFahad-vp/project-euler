#include <bits/stdc++.h>

using namespace std;

map<int, int> fac;

void fact()
{
    int s=1;
    for(int i=1;i<10;i++)
    {
        s *= i;
        fac[i] = s;
    }
    fac[0] = 1;
}

int main()
{
    fact();
    long long sum=0;
    long long total=0;

    int d;
    for(long long i=3;i<99999;i++)
    {
        long long n = i;
        while (n>0)
        {
            d = n % 10;
            sum += fac[d];
            n /= 10;    
        }
        if(sum==i)
        {
            total += i;
        }
        sum = 0;
        
    }
    printf("%lld\n", total);
    // printf("%d\n",fac[9]);

}