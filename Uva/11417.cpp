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

ll lcm(ll x , ll y){
    return (x*y)/__gcd(x,y);
}

int main(){

    file();
    ll n ;
    while(cin >> n && n ){
        ll ans = 0 ;
        for(int i = 1 ; i < n ;i++)
            for(int j = i+1 ; j <= n ;j++)
                ans+=__gcd(i,j);
        cout << ans << endl;
    }


}
