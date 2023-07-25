
#include <bits/stdc++.h>
#include <math.h>

float g(float b) {
    return (int)b*(b-(int)b + 1);
}

int main() {
    float b = 2.22356101931351597789;
    for(int i=1;i<14;i++) {
        std::cout << "b" << i << " = " << b << " ,a" << i << " = " << (int)b << '\n';
        b = g(b);
    }

}
    
