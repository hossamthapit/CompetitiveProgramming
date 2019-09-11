#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
using namespace std;
#define endl '\n'
void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
vector<vector<int>>g;
vector<int>idx, low,vis;
vector < bool > cut;
int T,chiled;
void DFS(int u, int p) {
	idx[u] = low[u] = ++T;
	for (auto t : g[u]) {
		if (!idx[t]) {
			if (p == -1)chiled++;
			DFS(t, u);
			low[u] = min(low[u], low[t]);
			if (low[t] >= idx[u])cut[u] = 1;
		}
		else if (t != p) {
			low[u] = min(low[u], idx[t]);
		}
	}
}
int main() {
	file();

	int n, m;
	while(cin >> n >> m){
        if(!n)break;
        n++;
        T = 0 ;
        chiled = 0;
        g = vector < vector < int > > (n);
        vis = idx = low = vector < int > (n);
        cut = vector < bool > (n);
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v; --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int c = 0 ;
        DFS(0,-1);
        cut[0] = (chiled > 1);
        for(int i=0;i<n;i++)if(cut[i])c++;
        cout << c << endl;
	}
}

