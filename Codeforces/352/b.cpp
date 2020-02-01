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

    int n ;
    cin >> n ;
    vector < int > vis(100003);
    map < int , set < int > > mp;
    for(int i = 1 ; i <= n ;i++){
        int a ;cin >> a ;
        if(!vis[a]){
            vis[a]=i;
            mp[a]=set<int>();
        }
        else {
            mp[a].insert(i-vis[a]);
            vis[a]=i;
        }
    }
    vector < pair < int , int > > ans;
    for(auto e : mp)
        if(szz(e.second)<=1)ans.push_back({e.first,*e.second.begin()});

    cout << szz(ans) << endl;
    for(auto e : ans)
        cout << e.first << " " << e.second << endl;
}
