#include <bits/stdc++.h>
#include <cstdio>
#include <iterator>
#include <vector>

typedef  struct {
    int x;
    int y;
}range;

std::vector<int> primes;
std::vector<range> ranges;

void read() {
    FILE* primes_file = fopen("primes.txt", "r");
    FILE* range_file = fopen("range.txt", "r");
    
    int a;
    range b;
    for(int i=0;i<1013278;i++) {
        fscanf(primes_file,"%d", &a);
        primes.push_back(a);
    }

    fclose(primes_file);

    for(int i=0;i<35414;i++) {
        fscanf(range_file,"%d%d", &b.x,&b.y);
        ranges.push_back(b);
    }

    fclose(range_file);

}

int main() {
    read();
    int ans = 0;
    for(auto x:ranges) {
        std::vector<int>::iterator it = std::find(primes.begin(),primes.end(),x.x);
        std::vector<int>::iterator it2 = std::find(primes.begin(),primes.end(),x.y);
        int index = std::distance(primes.begin(), it);
        int index2 = std::distance(primes.begin(), it2);
        ans += index2-index;
    }
    std::cout << ans << '\n';
}
