#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;
void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
bool vis[26];
int c = 0 ;

void dfs(int u , vector < vector < int > > adj){
    if(vis[u])return ;
    vis[u]=1;
    c++;
    for(auto p : adj[u])
        if(!vis[p])
            dfs(p,adj);
}

int main()
{
    file();

    int t ;
    cin >> t ;
    while(t--){
        vector < vector < int > > adj(26);
        memset(vis,0,sizeof vis);
        int tree = 0 , corn = 0;
        string s ;
        while(cin >> s){
            if(s[0]=='*')break;
            adj[s[1]-'A'].push_back(s[3]-'A');
            adj[s[3]-'A'].push_back(s[1]-'A');
        }
        cin >> s ;
        c=0;
        for(int i = 0 ; i < szz(s);i+=2){
            if(!vis[s[i]-'A']){
                dfs(s[i]-'A',adj);
                if(c==1)corn++;
                else tree++;
                c=0;
            }
        }
        cout << "There are " << tree << " tree(s) and " << corn << " acorn(s)." << endl;
    }



}
