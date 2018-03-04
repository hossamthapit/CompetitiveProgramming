#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

int main()
{fast //ll t;cin>>t;while(t--)
{

   int s ;
   cin >> s ;

   while(s--)
   {
       vector <int> ar(6,0);
       string x ;
       cin >> x ;

       for(int i = 0 ; i < x.size();i++)
       {
           if(x[i]=='A')ar[0]++;
           else if(x[i]=='R')ar[1]++;
           else if(x[i]=='M')ar[2]++;
           else if(x[i]=='G')ar[3]++;
           else if(x[i]=='T')ar[4]++;
           else if(x[i]=='I')ar[5]++;
       }
       
    ar[0]/=3;
    ar[1]/=2;
    sort(ar.begin(),ar.end());

    cout << ar[0] <<endl;

   }



}
}
