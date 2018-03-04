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

   int x  , n ;
   while(cin >> x >> n )
   {
       int a , b , c , d ;
       vector <int> v(21,0);

       if(x==0&&n==0)break;

       for(int i = 1 ; i <= x ;i++)
       {
           cin >> d ;
           v[i]+=d;
       }

       for(int i = 1 ; i <= n ;i++)
       {
           cin >> a >> b >> c ;
           v[b]+=c;
           v[a]-=c;
       }

       sort(v.begin()+1,v.end());

       if(v[1]<0)cout << "N\n";
       else cout << "S\n" ;
   }
}
}
