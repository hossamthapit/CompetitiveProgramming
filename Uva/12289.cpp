#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

string ar[100000];

int main()
{fast //ll t;cin>>t;while(t--)
{

   int x ;
   cin >> x ;

   while(x--)
   {
       int on=0 , tw=0 , th=0 ;
       string one = "one" , two = "two" , three="three" , s;
       cin >> s ;

       for(int i = 0 ; i < s.size() ;i++)
       {
           if(s[i]==one[i])on++;
       }
       for(int i = 0 ; i < s.size() ;i++)
       {
           if(s[i]==two[i])tw++;
       }
       for(int i = 0 ; i < s.size() ;i++)
       {
           if(s[i]==three[i])th++;
       }

       if(on==2||on==3)cout << 1 <<endl;
       else if(tw==2||tw==3)cout << 2 <<endl;
       else if(th==4||th==5)cout << 3 <<endl;


   }



}
}
