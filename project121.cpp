
#include <bits/stdc++.h>

using namespace std;

int main() {
    fstream file;
    file.open("project121.txt",ios::in);
    string tp;
    long long numeratorSum = 0;
    long long denominatorSum = 0;
    while(getline(file,tp)) {
        vector<int> position = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        stringstream ss(tp);
        int num;
        long long numerator = 1;
        long long denominator = 1;
        while(ss >> num) {
            numerator *= num;
            denominator *= (num+1);
            int index = 0;
            for(int x:position) {
                if(num == x){
                    position.erase(position.begin()+index);
                }
                index++;
            }
        }
        for(int x:position) {
            denominator *= (x+1);
        }
        numeratorSum += numerator;
        denominatorSum = denominator;
    }
    cout << (int)(1/((double)numeratorSum/denominatorSum)) << '\n';
    file.close();
    return 0;
}