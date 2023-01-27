#include <iostream>
#include <vector>

#define N 3

int S[N] = {1,2,3};

using namespace std;

void allSubsets(int pos, int len, vector<int>* subset) {
    if (pos==N) {
        for(int i=0;i<len;i++) {
            cout << (*subset)[i] << " ";
        } 
        cout << '\n';
        return;
    }
    (*subset)[len] = S[pos];
    allSubsets(pos+1,len+1,subset);
    allSubsets(pos+1,len,subset);
}

int main() {
    vector<int> subset(N);
    allSubsets(0,0,&subset);
}