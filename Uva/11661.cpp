#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

vector <int> ar(6);

int main()
{fast //ll t;cin>>t;while(t--)
{

   int x ;
   while(cin >> x)
   {
       if(x==0)break;
       ll r = 0 , z = 0 , d = 0 ;
       int mn = INT_MAX;
       string s ;
       cin >> s ;

       for(int i = 0 ; i < x ;i++)
       {
           if(s[i]=='R')
           {
               r=1;
               if(d<mn&&d>0)mn=d;
               d=0;
           }
           else if(s[i]=='D')
           {
               d=1;
               if(r<mn&&r>0)mn=r;
               r=0;
           }
           else if(s[i]=='Z')
           {
               z = 1 ;
               break;
           }
           else {
               if(r>0)r++;
               if(d>0)d++;
           }
       }
       if(z==1)cout << 0 << endl;
       else cout << mn <<endl;
   }

}
}
