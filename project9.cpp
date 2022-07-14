
#include <bits/stdc++.h>

using namespace std;

void solve()
{

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            int num = 0;
            num = 500 - i - j;
            num = num*1000;
            num = num + (i*j);
            if(num==0){
                cout << i*j*sqrt((i*i)+(j*j)) << '\n';
            }
        }
        
    }
    
}

int main()
{
    cout.setf(ios::fixed);
    solve();
}