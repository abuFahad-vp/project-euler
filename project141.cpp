
#include <iostream>
#include <math.h>

typedef unsigned long long ull;

using namespace std;

bool isSquare(ull x) {
  return (sqrt(x) == floor(sqrt(x)));
}

int main() {

  for(ull n = 1;n<=1000000;n++) {
    ull g2Cube = pow(n,3);
    ull g2 = n;
    cout << n <<'\n';
    for(ull i=1;i<=sqrt(g2Cube);i++) {
      cout << n << " " << i << '\n';
      if(g2Cube % i == 0) {
        cout << n << " " << i << '\n';
        ull g1 = i;
        ull value = (g1 + g2Cube/i);
        if(isSquare(value)) {
          cout << n << " " << i << '\n';
          ull g3 = g1*((g2/g1)*(g2/g1));
          cout << g3 << '\n';
          if(g2Cube % g3 == 0 && (g1 < g2 || g1 < g3)) {
            cout << g1 << " " << g2 << " " << g3 << " " << g2Cube << " " << value << '\n';
            break;
          }
        }
      }
    }
  }
}