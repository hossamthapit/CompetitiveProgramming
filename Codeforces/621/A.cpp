#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

int alph[26];
int main()
{fast //ll t;cin>>t;while(t--)
{
    ll x , mn=INT_MAX , c=0 ,m,s=0;


    cin >> x ;

    for(int i = 0; i < x ;i++)
    {
        cin >> m ;
        if(m%2==1)
        {
            c++;
            if(m<mn)mn=m;
        }
        s+=m ;
    }
    if(c%2==0)cout << s <<endl;
    else if(c%2==1)cout << s-mn <<endl;
    else cout << s <<endl;


}
}
