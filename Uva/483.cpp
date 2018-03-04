// 483 
#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

int main()
{fast // ll T;cin>>T;while(T--)
{
    string x ;
    ll sz ;
    
    while(getline(cin,x))
    {
        string s ;
        sz = x.size();
        
        for(int i = 0 ; i < sz ;i++)
        {
            if(x[i]==' '){reverse(s.begin(),s.end());cout << s ; s = "";}
            if(x[i]==' ')cout << ' ';
            if(x[i]!=' ')s+=x[i];
            if(i==sz-1){reverse(s.begin(),s.end());cout << s ;}
        }
        cout << endl;
    }
}
}
