#include <bits/stdc++.h>

using namespace std;

int main(){
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    int total = 0;

    int count = 2;

    while(sum <= 4000000){
        sum1 = (pow(1+sqrt(5),count) / pow(2,count));
        sum1 = sum1 * ((5 + sqrt(5)) / 10);
        sum2 = (pow((1-sqrt(5)),count) / pow(2,count));
        sum2 = sum2 * ((5-sqrt(5))/10);
        sum = sum1 + sum2 + 1;
        if(sum>4000000){
            break;
        }
        cout << sum << '\n';
        total += sum;
        count = count + 3;
        
    }
    cout <<"sum of total even numbers = " << total << '\n';
    
    // double sum = 0;
    // double sum1 = 0;
    // double sum2 = 0;
    // sum1 = (pow(1+sqrt(5),10) / pow(2,10));
    // sum1 = sum1 * ((5 + sqrt(5)) / 10);
    // sum2 = (pow((1-sqrt(5)),10) / pow(2,10));
    // sum2 = sum2 * ((5-sqrt(5))/10);
    // sum = sum1 + sum2;
     
    cout <<'\n';

}