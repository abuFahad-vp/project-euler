#include <bits/stdc++.h>

using namespace std;

int rectangle(int m, int n) {
    return (m*(m+1)/2)*(n*(n+1)/2);
}

int firstTerms[50] = {0};

int nDiaRect(int m, int n) {
    if (m > n) {
        return nDiaRect(n,m);
    }

    int d = (m*(2*m+1)*(2*m-1)) / 3;

    if (m==n) {
        int value = (nDiaRect(m-1,m) + (d-m));
        firstTerms[m] = value;
        return value;
    }
    return (firstTerms[m] + (n-m)*d);
}

int main() {
    int M = 47;
    int N = 43;
    int ans = 0;
    for(int m=1;m<=M;m++) {
        for(int n=1;n<=N;n++) {
            int value = rectangle(m,n) + nDiaRect(m,n);
            // cout << m << " " << n << " " << value << '\n';
            ans += value;
        }
    }
    cout << "answer = " << ans << '\n';
}
