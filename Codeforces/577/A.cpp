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
    ll x , n , c=0;

    cin >> x >> n ;

    for(int i = 1 ; i <= x ;i++)
    {
        if(n%i==0&&i*x>=n)c++;
    }

    cout << c <<endl;

}
}
