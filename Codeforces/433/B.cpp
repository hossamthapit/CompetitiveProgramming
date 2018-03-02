#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
typedef unsigned long long ull;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

ull com1[100001];
ull com2[100001];

int main()
{fast //ll t;cin>>t;while(t--)
{
    ull n , m , x , y , z;

    cin >> n  ;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> com1[i];
        com2[i]=com1[i];
    }

    sort(com2,com2+n);

    for(int i = 1 ; i < n ; i++)
    {
        com2[i]+=com2[i-1];
        com1[i]+=com1[i-1];
    }

    cin >> m;

    while(m--)
    {
        cin >> z >> x >> y ;

        if(z==1)
            cout << com1[y-1]-com1[x-2] <<endl;
        else
            cout << com2[y-1]-com2[x-2] <<endl;
    }

}
}
