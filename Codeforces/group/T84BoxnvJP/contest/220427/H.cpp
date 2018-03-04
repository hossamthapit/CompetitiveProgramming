#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

int ar[100000];
int l[100000];
int r[100000];

int main()
{fast //ll t;cin>>t;while(t--)
{
    ll x , m , k=0 , a , b , c=0;

   cin >> x ;

   for(int i = 1; i <= x ;i++)
    cin >> ar[i];

   cin >> m ;

   while(m--)
   {
       cin >> a >> b ;
        l[a]+=1;
        r[b]+=1;
   }

   for(int i = 1 ; i <= x ; i++)
   {
       if(l[i]>0)c+=l[i];
       if(c)ar[i]=0;
       if(r[i]>0)c-=r[i];
   }

   for(int i = 1 ; i <= x ; i++)
    if(ar[i]>0)k++;

    cout << k <<endl;

   for(int i = 1 ; i <= x ; i++)
    if(ar[i]>0)cout << ar[i] << " ";


}
}
