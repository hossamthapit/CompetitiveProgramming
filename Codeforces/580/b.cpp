#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

typedef long long ll;
using namespace std;

void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int main(){file();

    int n , d  ;
    cin >> n >> d ;
    vector < pair < int , ll > > v(n);
    for(auto &e :v)cin >> e.first >> e.second ;
    sort(all(v));

    for(int i = 1 ; i < n ;i++)v[i].second+=v[i-1].second;
    ll ans = 0 , l = 0 , r = 0;

    while(r<n){
        while(r<n&&v[r].first-v[l].first<d){
            ans = max(ans,0LL+v[r].second-(l-1>=0?v[l-1].second:0));
            r++;
        }
        l++;
    }
    cout << ans << endl;
}
