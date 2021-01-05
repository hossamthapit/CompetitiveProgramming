#include<bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif
#define stop(x) {cout<<x<<endl;exit(0);}
#define TRACE(x) if(DEBUG) cerr << #x << " = " << x << endl;
#define TRACE2(x,y) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << endl;
#define TRACE3(x,y,z) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << " | " << #z << " = " << z << endl;
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;
void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

ll lcm (ll x , ll y){
    return x/__gcd(x,y)*y;
}

int main(){file();

    ll a , b , n , t , m;
    while(cin >> n >> m ){

        ll ans = 0 ;
        bitset < 16  > bts ;
        vector < ll > v(m) , vv(m);
        for(auto &e : v)cin >> e ;

        for(int i = 1 ; i < (1<<m);i++){
            bts = i ;
            ll lc = 1 , c = 0;
            for(int k = 0 ; k < m ;k++){
                if(bts[k]){
                    c++;
                    lc = lcm(lc,v[k]);
                }
            }
            if(c&1)ans+=n/lc;
            else ans -= n/lc;
        }
        cout << n-ans << endl;
    }


}
