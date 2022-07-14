#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string number="",line;
    ifstream myfile;
    myfile.open("project8.txt");
    long long high = 1;
    long long curr = 1;

    while(getline(myfile,line))
    {
        number += line;
    }
    for(int i=0;i<number.size();i++)
    {
        for(int j=i;j<i+13;j++)
        {
            if(number[j] == '0')
            {
                break;
            }
            curr *= (number[j]-'0');  
        }
        if(curr > high)
        {
            high = curr;
        }
        curr = 1;
    }
    cout << "high = " << high << '\n';

}

int main()
{

    solve();
    return 0;
}