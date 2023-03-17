
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

typedef struct {
    double x;
    double y;
}coord;

bool compare_float(float x, float y, float epsilon = 0.01f){
    if(fabs(x - y) < epsilon)
        return true; 
    return false; 
}

double slopeOfLine(coord A, coord B) {
    return ((A.y-B.y) / (A.x-B.x));
}

double slopeOfEllipseT(coord A) {
    return (A.y/(4*A.x));
}

double slopeAngle(double m1, double m2) {
    return ((m1 - m2) / (1+(m1*m2)));
}

coord nextPoint(double m, coord A) {
    double s = -m*A.x + A.y;
    double a = 4 + m*m;
    double b = 2*m*s;
    double c = s*s - 100;
    double x1 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
    double x2 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
    coord ans;
    if(compare_float(x1,A.x) == 1) {
        ans.y = m*x2 - m*A.x + A.y;
        ans.x = x2;
    }else {
        ans.y = m*x1 - m*A.x + A.y;
        ans.x = x1;
    }
    return ans;
}

int main() {

    coord first;
    coord second;

    first.x = 0;
    first.y = 10.1;
    second.x = 1.4;
    second.y = -9.6;

    int count = 1;
    while(true) {

        double m1 = slopeOfLine(first,second);
        double m2 = slopeOfEllipseT(second);
        double m3 = slopeAngle(m1,m2);
        double m4 = -(slopeAngle(m3,m2));

        first = second;
        second = nextPoint(m4,second);

        if((-0.01 <= second.x) && (second.x <= 0.01) && (second.y > 0)) {
            cout << count << '\n';
            return 0;
        }
        count++;
    }
}

