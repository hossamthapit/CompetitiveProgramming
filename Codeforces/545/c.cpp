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

int n ;
vector < pair < int , int > > v;
ll memo[100002];

ll solve(int idx, int mx){
    if(idx==n)return 0 ;

    ll &ret = memo[idx];
    if(~ret)return ret ;
    if(v[idx].first<=mx)return -1e6;

    ret = 0 ;
    if(v[idx].first-v[idx].second>mx)solve(idx+1,v[idx].first)+1;
    ret = solve(idx+1,v[idx].first+v[idx].second)+1;
    ret = max(solve(idx+1,v[idx].first),ret);

    return ret ;
}


int main(){file();

    memset(memo,-1,sizeof memo);
    cin >> n ;
    v.resize(n);
    for(int i = 0 ; i < n ;i++)
        cin >> v[i].first >> v[i].second;

    cout << solve(1,v[0].first)+1 << endl;

}
