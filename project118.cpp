
#include <bits/stdc++.h>

using namespace std;

#define TOTAL_COMBS 362880

bool isPrime(int num) {
    if(num <= 1) return false;
    if (num <= 3)  return true; 
    
    int range = sqrt(num);
    if (num % 2 == 0 || num % 3 == 0) 
        return false; 
    

    for (int i = 5; i <= range; i += 6) 
        if (num % i == 0 || num % (i + 2) == 0) 
            return false; 
    
    return true;
}

//all Possible combination
set<vector<int>> allCombs() {
    set<vector<int>> all;
    for(int a=0;a<9;a++) {
        for(int b=0;b<9;b++) {
            for(int c=0;c<9;c++) {
                for(int d=0;d<9;d++) {
                    for(int e=0;e<9;e++) {
                        for(int f=0;f<9;f++) {
                            if(a+b+c+d+e+f == 9) {
                                vector<int> position;
                                if (a != 0) position.push_back(a);
                                if (b != 0) position.push_back(b);
                                if (c != 0) position.push_back(c);
                                if (d != 0) position.push_back(d);
                                if (e != 0) position.push_back(e);
                                if (f != 0) position.push_back(f);
                                sort(position.begin(),position.end(),greater<int>());
                                all.insert(position);
                            }
                        }
                    }
                }
            }

        }
    }
    return all;
}

int main() {

    // File with all possible permutations
    FILE* combs = fopen("combs1.txt","r");

    set<vector<int>> COMBS;

    set<vector<int>> all = allCombs();

    for(int i=0;i<TOTAL_COMBS;i++) {
        vector<int> pandigits(9);
        vector<int> temp(9);
        fscanf(combs,"%d%d%d%d%d%d%d%d%d",&pandigits[0],&pandigits[1],&pandigits[2],&pandigits[3],&pandigits[4],&pandigits[5],&pandigits[6],&pandigits[7],&pandigits[8]);
        for(auto position:all) {
            temp = pandigits;
            int term = 0;
            int term1 = 0;
            int term2 = 0;
            int term3 = 0;

            for(int k=0;k<position[0];k++) {
                term = term*10 + temp.back();
                temp.pop_back();
            }

            for(int k=0;k<position[1];k++) {
                term1 = term1*10 + temp.back();
                temp.pop_back();
            }

            for(int k=0;k<position[2];k++) {
                term2 = term2*10 + temp.back();
                temp.pop_back();
            }

            for(int k=0;k<position[3];k++) {
                term3 = term3*10 + temp.back();
                temp.pop_back();
            }

            if (position[0] != 0) temp.push_back(term);
            if (position[1] != 0) temp.push_back(term1);
            if (position[2] != 0) temp.push_back(term2);
            if (position[3] != 0) temp.push_back(term3);

            bool flag = true;

            for(int x:temp) {
                if(!isPrime(x)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                sort(temp.begin(),temp.end());
                COMBS.insert(temp);
            }
        }
    }
    int count = COMBS.size();
    cout << COMBS.size() << '\n';
}

