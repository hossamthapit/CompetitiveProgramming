#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

int vi[100000];
int arr[100000];

int main()
{fast //ll t;cin>>t;while(t--)
{
    ll n , m , a , h ;

    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> arr[i];
        vi[arr[i]]++;
    }

    for(int i = n ; i >= 1 ;i--)
    {
        h = arr[i];
        if(vi[h]>0){arr[i]=1;vi[h]=0;}
        else arr[i]=0;
    }

    for(int i = n-1 ; i>=1 ;i--)
    {
        arr[i]+=arr[i+1];
    }


    for(int i = 0;i < m ;i++)
    {
        cin >> a ;
        cout << arr[a]<<endl;
    }

}
}
