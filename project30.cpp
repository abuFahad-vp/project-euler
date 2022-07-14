#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long sum=0;
    int curr = 0;
    for(int i=2;i<352000;i++)
    {
        int num = i;
        while(num>=1)
        {
            curr += pow(num%10,5);
            num /=10;
        }
        if(curr==i)
        {
            cout << i << '\n';
            sum += i;
        }
        curr = 0;
    }
    cout << sum << '\n';
}