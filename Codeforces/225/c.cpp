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

int n , m , mn , mx ;
int value[2][1001];
ll memo[1001][1001][2];

ll solve(int idx, int cnt , bool type){
    if(idx==m&&cnt<mn)return 1e7;
    if(idx==m&&cnt>mx)return 1e7;
    if(idx==m)return 0;
    if(cnt>mx)return 1e7;

    ll &ret = memo[idx][cnt][type];
    if(~ret)return ret ;
    ret = 1e7;

    ll choice1 = INT_MAX ;
    if(cnt>=mn)
         choice1 =  solve(idx+1,1,!type)+value[!type][idx];
    ll choice2 = solve(idx+1,cnt+1,type)+value[type][idx];
    ret = min(choice1,choice2);

    return ret;
}

int main(){file();

    memset(memo,-1,sizeof memo);
    cin >> n >> m >> mn >> mx ;
    for(int i = 0 ; i < n ;i++){
        for(int k = 0 ; k < m ;k++){
            char a ;
            cin >> a ;
            if(a=='.')value[0][k]++;
            else value[1][k]++;
        }
    }
    cout << min(solve(0,0,1),solve(0,0,0)) << endl;
}
