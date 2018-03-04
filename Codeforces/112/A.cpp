#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

int main()
{fast// ll t;cin>>t;while(t--)
{

	ll c =0;

    string y , x;
	cin >> x  >> y;

	for(int  i = 0 ; i < x.size();i++)
    {
        if(x[i]>='a')x[i]=x[i]-32;
        if(y[i]>='a')y[i]=y[i]-32;
    }

    if(x<y)cout << -1 <<endl;
    else if(x>y)cout << 1 <<endl;
    else cout << 0 <<endl;
}
}
