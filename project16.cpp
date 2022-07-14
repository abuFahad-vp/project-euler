#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<string>_1_9 = {"one","two","three","four","five","six","seven","eight","nine"};
    vector<string>_11_19 = {"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    vector<string> _20_90 = {"twenty", "thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    string hun = "hundred";
    string thoun = "onethousand";
    string an = "and";

    int sum1_9 = 0;
    int sum1_10 = 0;
    int sum11_19 = 0;
    int sum20_99 = 0;
    int sum1_99 = 0;
    int sum100_999 = 0;
    int total = 0;

    for(auto x:_1_9)
    {
        sum1_9 += x.size();
    }

    sum1_10 = sum1_9 + 3;

    for(auto x:_11_19)
    {
        sum11_19 += x.size();
    }

    for(auto x:_20_90)
    {
        sum20_99 += (x.size()*10) + sum1_9;
    }

    sum1_99 = sum1_10 + sum11_19 + sum20_99;

    sum100_999 = 36*100 + 9*sum1_99;

    total = sum1_99+sum100_999+thoun.size();
    
    cout <<  sum1_99 + 20259 + thoun.size() << '\n';
}

int main()
{
    solve();
}