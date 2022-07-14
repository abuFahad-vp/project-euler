

/* This is Brute force method
Actually U dont need a program to find that
Refer to :- C:\robot\project euler\project4.euler.png*/


#include <bits/stdc++.h>
#include "project.h"

using namespace std;

// to Find the palindrome

//6 digit palindrome
//family  = 900009
// vector<int> palindrome(){
//     int num;
//     vector<int> pal;
//     //change the 9 to any number you want to find

//     for(int y=0;y<10;y++){
//         for(int z=0;z<10;z++){
//             num = (900009) + (y*10010) + (z*1100);
//             pal.push_back(num);
//         }
//     }
//     return pal;

// }

//to reverse the number
int rev(int x){
    string n;
    stringstream ss;
    ss << x;
    ss >> n;
    reverse(n.begin(), n.end());
    stringstream line(n);
    line >> x;
    return x;

    
}


// int main(){
//     // int num = 1;
//     // int ans = 0;
//     // for(int i=100;i<1000;i++){
//     //     for(int j=100;j<1000;j++){
//     //         for(auto x:palindrome()){
//     //             if(x==i*j){
//     //                ans = x;
//     //                cout << "FOund: " << i << '*' << j << " = " << x << '\n';
//     //                break; 
//     //             }
//     //         }
//     //         if(ans != 0){
//     //             break;
//     //         }
//     //     }
        
//     // }

//     //to reverse the number

// }
int main(){
    int num = 1;
    int ans = 0;
    for(int i=900;i<1000;i++){
        for(int j=900;j<1000;j++){
            if((i*j) == rev(i*j)){
                cout << "Found: " << i <<"*"<<j<<" = " << i*j<<'\n';
            }
        }
        
    }
    

}


