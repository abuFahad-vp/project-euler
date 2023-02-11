#include <bits/stdc++.h>

using namespace std;

int main() {
    int index = 0;
    map<int,int> dict;
    vector<vector<int>> array = {{1}};
    int n = 2;
    while(true) {
        if(n > 200) break;
        int lastElem = array[index].back();
        int lenx = array[index].size();
        for(int x=0;x<lenx;x++) {
            vector<int> temp = array[index];
            int term = array[index][x] + lastElem;
            temp.push_back(term);
            array.push_back(temp);
            if(dict[term] == 0) {
                dict[term] = lenx;
            }
            while(true) {
                if(n>200) break;
                if(dict[n] != 0) {
                    n++;
                }else if(dict[n] == 0) {
                    break;
                }
            }
        }
        index += 1;
    }
    int ans = 0;
    for(int i=2;i<=200;i++) {
        ans += dict[i];
    }
    cout << "ans = " << ans << '\n';
    
}