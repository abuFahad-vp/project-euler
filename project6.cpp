#include <bits/stdc++.h>

using namespace std;

double sum_of_squares_of_N(int len)
{
    double sum = (2*pow(len,3)) + (3*pow(len,2)) + len;
    sum = sum/6;

    return sum;
}

double sum_of_N(int len)
{
    double sum = pow(len,2) + len;
    sum = sum/2;
    
    return sum;
}

void solve()
{
    double N = sum_of_N(100);
    N = pow(N,2);
    double NS = sum_of_squares_of_N(100);

    cout << N - NS << '\n';


}

int main()
{
    cout.setf(ios::fixed);
    setprecision(0);
    
    solve();
    return 0;
}