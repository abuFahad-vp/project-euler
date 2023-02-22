
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

typedef struct {
    int q;
    int r;
    int s;
    long long value;
} Hex;

bool isPrime(int num) {
    if(num <= 1) return false;
    if (num <= 3)  return true; 
    
    int range = sqrt(num);
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (num % 2 == 0 || num % 3 == 0) 
        return false; 
    

    for (int i = 5; i <= range; i += 6) 
        if (num % i == 0 || num % (i + 2) == 0) 
            return false; 
    
    return true;
}

void printHex(Hex block) {
    cout << block.q << " " << block.r << " " << block.s << " " << block.value;
}

vector<Hex> cube_direction_vectors = {
    Hex{-1, 1, 0, 0}, Hex{0, 1, -1, 0}, Hex{1, 0, -1, 0}, 
    Hex{1, -1, 0, 0}, Hex{0, -1, 1, 0}, Hex{-1, 0, 1, 0}, 
};

bool operator < (const Hex a, const Hex b) {
    return (a.q < b.q && a.r < b.r && a.s < b.s);
}

bool operator == (Hex a, Hex b) {
    return a.q == b.q && a.r == b.r && a.s == b.s;
}

bool operator != (Hex a, Hex b) {
    return !(a == b);
}

int main() {

    vector<Hex> hexGrid;
    map<vector<int>, int> hexValue;

    hexGrid.push_back(Hex{0,0,0,1});
    Hex start = Hex{0,-1,1,2};

    hexValue[vector<int> {0,-1,1}] = 2;
    hexValue[vector<int> {0,0,0}] = 1;

    int n = 1;
    int HexSize = 10;
    for(int i=1;i<HexSize;i++) {
        Hex current;
        current = start;
        hexGrid.push_back(start);
        for(int a=0;a<6;a++) {
            for(int b=0;b<n;b++) {
                Hex temp = current;
                temp.q += cube_direction_vectors[a].q;
                temp.r += cube_direction_vectors[a].r;
                temp.s += cube_direction_vectors[a].s;
                temp.value += 1;
                current = temp;
                if(current == start) break;
                hexGrid.push_back(temp);
                hexValue[vector<int> {temp.q,temp.r,temp.s}] = temp.value;
            }
        }
        n++;
        start.q  = 0;
        start.r -= 1;
        start.s += 1;
        start.value += 6*i;
        hexValue[vector<int> {start.q,start.r,start.s}] = start.value;
    }
    int index = 1;
    for(auto hex:hexGrid) {
        Hex test = hex;
        int primeCount = 0;
        cout << test.value << " = ";
        for(int i=0;i<6;i++) {
            int q = test.q;
            int r = test.r;
            int s = test.s;
            q += cube_direction_vectors[i].q;
            r += cube_direction_vectors[i].r;
            s += cube_direction_vectors[i].s;
            long long value = hexValue[vector<int> {q,r,s}];
            cout << value << ", ";
        }
        cout << '\n';

    }
}




