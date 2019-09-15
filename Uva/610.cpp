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
vector < vector < int > > adj , scc;
vector < int > dfsNum , dfsLow , sccID ;
vector < pair < int , int > > bridges;
stack < int > stk;
int targanTimer;

void targan(int node, int parent){
    dfsNum[node] = dfsLow[node] = ++targanTimer;
    for (auto child : adj[node]){
        if (!dfsNum[child]){
            targan(child, node);
            dfsLow[node] = min(dfsLow[node], dfsLow[child]);
            if (dfsLow[child] > dfsNum[node])bridges.push_back({node,child});
        }
        else if (child != parent){
            dfsLow[node] = min(dfsLow[node], dfsNum[child]);
        }
    }
}

void tarjanScc(int node ,int  parent) {
	dfsNum[node] = dfsLow[node] = ++targanTimer;
	stk.push(node);
	for (auto child : adj[node]) {
		if (child == parent)continue;
		if (!dfsNum[child]) {
			tarjanScc(child,node);
			dfsLow[node] = min(dfsLow[node], dfsLow[child]);
		}
		else if (child!=parent)
			dfsLow[node] = min(dfsLow[node], dfsNum[child]);
	}
	if (dfsLow[node] == dfsNum[node]) {
		scc.push_back(vector<int>());
		int z = -1;
		while (z != node) {
			z = stk.top(); stk.pop();
			scc.back().push_back(z);
			sccID[z] = scc.size() - 1;
		}
	}
}

map < pair < int , int > , int > mp;
void dfs(int u){
    for(auto p : adj[u])
        if(sccID[u]==sccID[p]&&mp[{min(u,p),max(u,p)}]==2){
            cout << u+1 << " " << p+1 << endl;
            mp[{min(u,p),max(u,p)}] = 1;
            dfs(p);
        }
}

int main(){
    file();

    int n, m , t = 0;
    while(cin >> n >> m&& n&&++t){
        targanTimer = 0 ;
        dfsNum = dfsLow = sccID = vector < int > (n);
        bridges = vector < pair < int , int > > ();
        scc = vector < vector < int > > ();
        adj = vector < vector < int > > (n);
        stk = stack < int > ();
        vector < pair < int , int > > edges;

        int a , b ;
        for(int i = 0 ; i < m ;i++){
            cin >> a >> b ;a--;b--;
            edges.push_back({a,b});
            if(a>b)swap(a,b);
            mp[{a,b}]=2;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0; i<n; i++)
            if(!dfsNum[i])
                targan(i,-1);
        targanTimer = 0 ;
        dfsNum = dfsLow = vector < int > (n);

        for(int i=0; i<n; i++)
            if(!dfsNum[i])
                tarjanScc(i,-1);
        cout << t << endl << endl;
        for(int i=0; i<n; i++)
                dfs(i);

        for(auto e : bridges){
            cout << e.first+1 << " "<< e.second+1 << endl;
            cout << e.second+1 << " "<< e.first+1 << endl;
        }

        cout << "#" << endl;
    }
}

