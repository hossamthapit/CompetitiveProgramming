#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

int ar[50][50];
int rr[50];

int main()
{fast //ll t;cin>>t;while(t--)
{

   ll x , y , z , mn = -1,o=1;

   cin >> x ;

	for(int i = 1 ; i <= x ;i++)
        for(int y = 1 ; y <= x ; y++)
            cin >> ar[i][y];


	for(int i = 1 ; i <= x ;i++)
    {
        for(int y = 1 ; y <= x ; y++)
        {
             if(ar[y][i]>mn)mn=ar[y][i];
        }
        rr[o++]=mn;
        mn = -1 ;
    }

	for(int i = 1 ; i <= x ;i++)
    {
        for(int y = 1 ; y <= x ; y++)
        {
             if(rr[i]==rr[y]&&y!=i)rr[y]+=1;
        }
    }

    for(int u = 1 ; u <= x ;u++)
    {
        cout << rr[u]<<" " ;
    }


}
}
