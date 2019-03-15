#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define all(x) x.begin(),x.end()
#define szz(s) ll(s.size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define endl '\n'

void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}

ull ar[110][110];

void pascal(ll x){
    ar[1][1]=1;
    for(int i= 2 ; i <= x ;i++)
        for(int k = 1 ; k <= x ;k++)
            ar[i][k]=ar[i-1][k]+ar[i-1][k-1];
}

int main(){

    file();
    pascal(106);

    ll n , m ;
    while(cin >> n >> m && n )
        cout << n << " things taken " << m << " at a time is " << ar[n+1][m+1] << " exactly." << endl;
}
