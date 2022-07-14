#include <bits/stdc++.h>

using namespace std;

void solve()
{
    ifstream myfile;
    myfile.open("project11.txt");
    vector<vector<int>> matrix;
    vector<string> dummy;
    string num;

    int j=0;

    //reading the numbers from the file
    while (getline(myfile, num, '\n'))
    {
        dummy.push_back(num);
    }

    //converting string to int
    for(int i=0;i<20;i++)
    {
        vector<int> tmp;
        for(int j=0;j<58;j++)
        {
            
            if(dummy[i][j]!= ' ' && dummy[i][j+1] != ' ')
            {
                int num = ((dummy[i][j]-'0')*10)  + (dummy[i][j+1]-'0');
                tmp.push_back(num);
            }
            
        }
        matrix.push_back(tmp);
        tmp.clear();
        
    }

    // up
    long long curr=1;
    long long lar=1;
    for(int i=3;i<20;i++)
    {
        
        for(int j=0;j<20;j++)
        {   

            curr = matrix[i][j]*matrix[i-1][j]*matrix[i-2][j]*matrix[i-3][j];
            if(curr>lar)
            {
                lar = curr;
            }
        }
    }

    //left
    for(int i=0;i<20;i++)
    {
        
        for(int j=0;j<17;j++)
        {   

            curr = matrix[i][j]*matrix[i][j+1]*matrix[i][j+2]*matrix[i][j+3];
            if(curr>lar)
            {
                lar = curr;
            }
        }
    }

    //left diagonal
    for(int i=0;i<17;i++)
    {
        
        for(int j=3;j<20;j++)
        {   

            curr = matrix[i][j]*matrix[i+1][j-1]*matrix[i+2][j-2]*matrix[i+3][j-3];
            if(curr>lar)
            {
                lar = curr;
            }
        }
    }

    //right diagonal
    for(int i=0;i<17;i++)
    {
        
        for(int j=0;j<17;j++)
        {   

            curr = matrix[i][j]*matrix[i+1][j+1]*matrix[i+2][j+2]*matrix[i+3][j+3];
            if(curr>lar)
            {
                lar = curr;
            }
        }
    }
    cout << lar << '\n'; 
    
}

int main()
{
    solve();
}