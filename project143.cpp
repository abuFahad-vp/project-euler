
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ull;

bool isSquare(ull n) {
    return (sqrt(n) == floor(sqrt(n)));
}

int main2() {
    cout << isSquare(6) << '\n';
    return 0;
}

int main() {
    ull ans = 488389;
    ofstream fp;
    fp.open("0803.txt");
    int p = 7728;
    while(true) {
    // for(int p=1;p<2000;p++) {
        if (p+2 > 120000) return 0;
        for(int q=1;q<=p;q++) {
            for(int r=1;r<=q;r++) {
                int a = p*p + q*q + p*q;
                int b = p*p + r*r + p*r;
                int c = q*q + r*r + q*r;
                if(isSquare(a) && isSquare(b) && isSquare(c)) {
                    ans += p+q+r;
                    cout << p << " " << q << " " << r << ":- " << sqrt(a) << " " << sqrt(b) << " " << sqrt(c) << " " << p+q+r << " " << ans << '\n';
                    fp << p << " " << q << " " << r << ":- " << sqrt(a) << " " << sqrt(b) << " " << sqrt(c) << " " << p+q+r << " " << ans << std::endl;
                    // fprintf(fp,"%d %d %d %f %f %f %d %llu\n", p,q,r, sqrt(a), sqrt(b), sqrt(c), p+q+r, ans);
                }
            }
        }
        p++;
    }
    return 0;
}
