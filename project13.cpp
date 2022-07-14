#include <bits/stdc++.h>

using namespace std;

// converting first 12 digits of string to long long 
long long digits(string num)
{
    long long n=0;
    long long tmp;
    int p = 11;
    for(int i=0;i<12;i++)
    {
        tmp = num[i]-'0';
        tmp = tmp*pow(10,p);
        n += tmp;
        // cout << n << '\n'; 
        p--;

    }
    return n;
}

int main()
{
    string number="",line;
    ifstream myfile;
    myfile.open("project13.txt");
    vector<string> num;

    while(getline(myfile,line))
    {
        num.push_back(line);
    }
    vector<long long> h_n(100);
    for(int i=0;i<100;i++)
    {
        h_n[i] = digits(num[i]);
    }
    long long sum = 0;
    for(auto x:h_n)
    {
        sum += x;
    }
    cout << sum << '\n';

}