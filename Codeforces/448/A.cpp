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
    ll a1 , a2 , a3 , b1 , b2 , b3 , sh;

    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> sh ;

    a1+=a2+a3;
    b1+=b2+b3;

    if(a1==0)a1=0;
    else if(a1%5==0)a1/=5;
    else a1=a1/5+1;

    if(b1==0)b1=0;
    else if(b1%10==0)b1/=10;
    else b1=b1/10+1;


    if(a1+b1<=sh)cout << "YES" <<endl;
    else cout << "NO" <<endl;

}
}
