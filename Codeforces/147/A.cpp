#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

int ar[100];

int main()
{fast //ll t;cin>>t;while(t--)
{
    ll sz,sz2 ;

    string x , c , v , m , k ;

    getline(cin,x);

    sz=x.size();
    for(int i = 0 ; i < sz ; i++)
    {
        c+=x[i];
        if(x[i]=='!'||x[i]=='?'||x[i]=='.'||x[i]==',')c+=' ';
    }

    sz=c.size();
    for(int i = 0 ; i < sz ; i++)
    {
        if(c[i]==' '&&c[i-1]==' ');
        else v+=c[i];
    }

    sz=v.size();
    for(int i = 0 ; i < sz ; i++)
    {
        if(v[i]==' '&&(v[i+1]=='!'|v[i+1]=='?'||v[i+1]=='.'||v[i+1]==','));
        else k+=v[i];
    }

    cout << k <<endl;





}
}
