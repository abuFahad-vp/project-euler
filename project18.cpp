#include <bits/stdc++.h>

using namespace std;


int main()
{
    ifstream myfile;
    myfile.open("project18.txt");
    string name;
    
    int c =0;
    vector<vector<int>> n;
    vector<int> dum;
    for(int i=0;i<15;i++)
    {
        getline(myfile,name);
        stringstream ss(name);
        while (ss >> c)
        {
            dum.push_back(c);
        }
        n.push_back(dum);
        dum.clear();
    }
    
    for(int i=14;i>0;i--)
    {
        for(int j=0;j<n[i].size()-1;j++)
        {
            n[i-1][j] = max(n[i][j]+n[i-1][j], n[i][j+1]+n[i-1][j]);
            
        }
    }
    
    cout << n[0][0] << '\n';

    return 0;
}

