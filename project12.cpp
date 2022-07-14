// #include <bits/stdc++.h>

// using namespace std;

// #define ll long long


// // A function to print all prime
// // factors of a given number n
// vector<long long> primeFactors(long long n)
// {
//     // Print the number of 2s that divide n
//     vector<long long> fac;
//     while (n % 2 == 0)
//     {
//         fac.push_back(2);
//         // cout << 2 << " ";
//         n = n/2;
//     }
 
//     // n must be odd at this point. So we can skip
//     // one element (Note i = i +2)
//     for (int i = 3; i <= sqrt(n); i = i + 2)
//     {
//         // While i divides n, print i and divide n
//         while (n % i == 0)
//         {
//             fac.push_back(i);
//             // cout << i << " ";
//             n = n/i;
            
//         }
//     }
 
//     // This condition is to handle the case when n
//     // is a prime number greater than 2
//     if (n > 2)
//     {
//         // cout << n << " ";
//         fac.push_back(n);
//     }

//     return fac;
        
// }

// // return the total number of factors
// long long nfact(vector<long long> fac)
// {
//     map<ll,ll> con;
//     for(auto x:fac)
//     {
//         con[x] += 1;
//     }
//     ll pro = 1;
//     for(auto x : con)
//     {
//         pro *= (x.second+1);
//     }


//     return pro;
// }

// int main(){
//     ll num = 1;
//     for(int i=1;i<100000;i++)
//     {
//         if(nfact(primeFactors(num)) >= 500)
//         {
//             cout << num << '\n';
//             break;
//         }
//         num = num+1+i;
//     } 
//     return 0;
// }


// Another Method

#include <bits/stdc++.h>

using namespace std;

void solve()

{
//  PE-12
  int j,k=0,f1=0,f2=0,ans;
  long long int t;
  for(int i=1;k<=500;i++)  //runs loop until a no. with more than 500 factors encountered 
  {
    k=0;
    f1=0;
    f2=0;
    t=(i*i+i)/2;    //formula for sum of natural nos upto n
    
   /* Main logic
      since  i and i+1 are coprime the dont have any common factor except 1
      total factors of i*(i+1) are =number of factors(i) * number of factors(i+1) 
      similarly for i*(i+1)/2
      factors of the even term will change 
      hence;
      total factors = number of factors(even/2)* number of factors(odd)
  */
    if(i%2!=0)      
    {
      for(j=1;j<=i;j++)
      {
        if(i%j==0)
        {
          f1++;
        }
      }
      for(j=1;j<=(i+1)/2;j++)
      {
        if(((i+1)/2)%j==0)
          f2++;
      }
    }
    else
    {
      for(j=1;j<=i+1;j++)
      {
        if((i+1)%j==0)
          {
            f2++;
          }
      }
      for(j=1;j<=i/2;j++)
      {
        if((i/2)%j==0)
          f1++;
      }
    }

    k=f1*f2;
    //cout<<i<<endl;
  }
  cout<<t<<'\n';
}

int main()
{
    solve();
}