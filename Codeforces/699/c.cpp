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
vector < int > v;
ll memo[102][3];

ll solve(int idx , int last = 0){
    if(idx==n)return 0 ;

    ll &ret = memo[idx][last];
    if(~ret)return ret;

    ret = INT_MAX ;
    if(v[idx]==1&&last!=1)ret = min(ret,solve(idx+1,1));
    else if(v[idx]==2&&last!=2)ret = min(ret,solve(idx+1,2));
    else if(v[idx]==3){
        if(last!=1)ret = min(ret,solve(idx+1,1));
        if(last!=2)ret = min(ret,solve(idx+1,2));
    }
    else
        ret = min(ret,solve(idx+1,0))+1;

    return ret ;
}


int main(){file();

    memset(memo,-1,sizeof memo);
    cin >> n ;
    v.resize(n);
    for(int i = 0 ; i < n ;i++)
        cin >> v[i];

    cout << solve(0) << endl;

}
