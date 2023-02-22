
#include <bits/stdc++.h>

using namespace std;

inline unsigned gcd(unsigned u, unsigned v) {
    auto shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if(u > v)
            std::swap(u, v);
    } while((v -= u));
    return u << shift;
}

int main() {
    
}




