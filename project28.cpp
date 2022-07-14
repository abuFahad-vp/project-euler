#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // long long sum = 0;
    //(2n-1)^2 = 1,9,25,49....1002001
    int t=1;
    for(int n=3;n<=1001;n+=2)
    {
        
        t +=4*pow(n,2)-6*n+6;
    }
    cout << t <<'\n';

}

int main()
{
    solve();
}