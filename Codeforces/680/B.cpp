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
    ll a , n  , c = 0 , z , y;

    cin >> a >> n ;

    for(int i = 1 ; i <= a ;i++)
    {
        cin >> ar[i];
    }

    if(ar[n]==1)c++;

    int k = n-1 , m = n+1 ;
    for(; k >= 1 || m <= a ; k-- , m++ )
    {
        if(ar[k]==1&&ar[m]==1&&k>=1&&m<=a)c+=2;
        else if(ar[k]==1&&m>a)c++;
        else if(ar[m]==1&&k<1)c++;


    }

    cout << c <<endl;

}
}
