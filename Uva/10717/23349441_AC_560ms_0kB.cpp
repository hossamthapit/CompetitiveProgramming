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

ll lcm(ll x , ll y){
    return x/__gcd(x,y)*y;
}


int main(){file();

    ll a , b , n ,t , m ;
    while(cin >> n >> m && n){
        ll ans = 0 , temp = 0 , c = 0;
        vector < int > v(n);
        for(auto &e : v)cin >> e ;

        for(int i = 0 ; i < m ;i++){
            cin >> a ;
            ll mn = INT_MAX , mx = INT_MIN , p , pp;
            for(int i1 = 0 ; i1 < n ;i1++){
                for(int i2 = i1+1 ;i2 < n ;i2++){
                    for(int i3 = i2+1;i3 < n ;i3++){
                        for(int i4 = i3+1 ;i4 < n ;i4++){
                            int temp = lcm(v[i1],lcm(v[i2],lcm(v[i3],v[i4]))) ;
                            if(a/temp*temp > mx && a/temp*temp <= a)
                                mx = a/temp*temp ;
                            if(a/temp*temp==a){
                                mn = a ;mx=a;
                            }
                            if(a/temp*temp+temp < mn && a/temp*temp+temp >=a)
                                mn = a/temp*temp+temp ;
                        }
                    }
                }
            }
            cout << mx << " " << mn << endl;
        }
    }


}
