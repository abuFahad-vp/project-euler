
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}

int main()
{
    int a = 3;
    int b = 2;
    int limit = 12000;
    int result = 0;

    for (int d = 5; d <= limit; d++)
    {
        for (int n = d/a+1; n < (d-1)/b+1; n++)
        {
            if (gcd(n,d) == 1)
            {
                result++;
            }
            
        }
        
    }
    cout << result << '\n';
    
}