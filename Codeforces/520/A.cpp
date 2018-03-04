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
    ll x , y , z ;

    cin >> x ;
    string s ;
    cin >> s ;

    for(int i = 0 ; i < x ;i++)
    {
        if(s[i]>='a')alph[s[i]-'a']++;
        else alph[s[i]-'A']++;
    }

    for(int i = 0 ; i < 26;i++)
    {
        if(alph[i]==0){cout << "NO" <<endl; return 0 ;}
    }
    cout << "YES" <<endl;
}
}
