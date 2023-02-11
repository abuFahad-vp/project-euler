
#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> array) {
    for(int x:array) {
        cout << x << " ";
    }
    cout << '\n';
}

void printArrays(vector<vector<int>> array) {
    for(auto x:array) {
        for(auto y:x) {
            cout << y << " ";
        }
        cout << '\n';
    }
}

void printMap(map<int,int> Map) {
    map<int,int>::iterator it = Map.begin();
    while(it != Map.end()) {
        cout << it->first << " => " << it->second << '\n'; 
        it++;
    }
}