
#include <bits/stdc++.h>
#include "project.h"

using namespace std;

//to reverse the number
long long rev(long long x){
    string n;
    stringstream ss;
    ss << x;
    ss >> n;
    reverse(n.begin(), n.end());
    stringstream line(n);
    line >> x;
    return x;

    
}


bool ispalbin(long long n)
{
    vector<int> bine;
    while(n>0)
    {
        bine.push_back(n%2);
        n /= 2;
    }
    vector<int> palin = bine;
    reverse(bine.begin(), bine.end());
    if(palin == bine)
    {
        return true;
    }
    return false;   
}
int main(){
    vector<long long> pal;
    for(int i=1;i<1000000;i++)
    {
        if(i==rev(i))
        {
            pal.push_back(i);
        }
    }
    long long sum=0;
    for(auto x:pal)
    {
        if(ispalbin(x))
        {
            sum += x;
            // printf("%lld\n",x);
        }
    }
    printf("%lld\n",sum);

}


