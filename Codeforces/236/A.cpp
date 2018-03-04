#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;
int ar[26];

using namespace std;

int main()
{fast //ll t;cin>>t;while(t--)
{
    int x , a,y , b,c=0;


    string s ;
    cin >> s ;

    for(int i = 0 ;  i< s.size();i++)
    {
        ar[(s[i]-97)]++;
    }

    for(int i = 0 ; i < 26;i++)
    {
        if(ar[i]>0)c++;
    }

    if(c%2==0)cout << "CHAT WITH HER!" <<endl;
    else cout << "IGNORE HIM!" <<endl;

}
}
