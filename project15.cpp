#include "project.h"
#include <bits/stdc++.h>

using namespace std;

// to print all pascals triangle number
void pascal()
{
    vector<string> tri;
    vector<string> curr;
    tri.push_back("0");
    tri.push_back("1");
    tri.push_back("0");
    

    for(int i=0;i<1000;i++)
    {

        curr.push_back("0");
        for(int i=1;i<tri.size();i++)
        {
            // cout << findSum(tri[i-1],tri[i]) << '\n';
            curr.push_back(findSum(tri[i-1],tri[i]));
        }
        curr.push_back("0");
        tri = curr;
        long long sum = 0;
        string c = "0";
        for(int i=1;i<tri.size();i++)
        {
            c = findSum(c,tri[i]);
        }
        for(int z=0;z<c.size();z++)
        {
            sum += c[z]-'0';
        }
        if(i+1==1000)
        {
            cout << i+1 << " -> "<< sum << '\n';
        }
        
        curr.clear();

    }
}

int main()
{
    pascal();
}
