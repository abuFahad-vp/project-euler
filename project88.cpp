#include <iostream>
#include <vector>
#include <set>
#include <map>

std::map<int,int> allFactors;

void factors(std::vector<int> *temp,int n, int start) {

    if(n<=1) {
        if (temp->size() > 1 ) {
            int sum = 0;
            int product = 1;
            for(int i=0;i<temp->size();i++){
                sum += (*temp)[i];
                product *= (*temp)[i];
            }
            int totaLen = temp->size() + (product - sum);
            if (allFactors[totaLen] == 0) allFactors[totaLen] = product;
            if (product < allFactors[totaLen]) allFactors[totaLen] = product;
        }
    }
    for (int i = start;i <= n; i++) {
        if (n%i == 0 ) {
            temp->push_back(i);
            factors(temp,n / i, i);
            temp->pop_back();
        }
    }
}


int main() {
    std::vector<int> temp;
    std::set<int> allFactorsUnique;
    int limit = 12200;
    int k = 12000;
    int i = 2;
    while(true) {
        if(allFactors[limit] != 0) {
            break;
        }
        factors(&temp,i,2);
        i++;
    }

    for(int i=2;i<=k;i++) {
        allFactorsUnique.insert(allFactors[i]);
    }
    
    long ans = 0;
    for (auto x : allFactorsUnique) {
        ans += x;
    }
    std::cout << '\n' << ans << '\n';
    return 0;
}
