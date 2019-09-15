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

vector < vector < int > > adjList, scc;
vector < int > dfsNumber, lowLink, sccID , value;
vector < bool > inStack;
stack < int > stk;
int tarjanTime;

void tarjan(int node,int parent) {
	dfsNumber[node] = lowLink[node] = ++tarjanTime;
	inStack[node] = 1;
	stk.push(node);
	for (auto child : adjList[node]) {
	//    if(child==parent)continue;
		if (!dfsNumber[child]) {
			tarjan(child,node);
			lowLink[node] = min(lowLink[node], lowLink[child]);
		}
		else if (inStack[child])
			lowLink[node] = min(lowLink[node], dfsNumber[child]);
	}
	if (lowLink[node] == dfsNumber[node]) {
		scc.push_back(vector<int>());
		int z = -1;
		while (z != node) {
			z = stk.top(); stk.pop();
			inStack[z] = 0;
			scc.back().push_back(z);
			sccID[z] = scc.size() - 1;
		}
	}
}
int main()
{
    file();

    int n, m ;
    cin >> n ;
    adjList = vector < vector < int > > (n);
    dfsNumber =  lowLink = sccID = value = vector < int > (n);
    inStack  = vector < bool > (n);
    tarjanTime = 1 ;
    for(int i = 0 ; i < n ;i++)
        cin >> value[i];

    cin >> m ;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        --u;--v;
        adjList[u].push_back(v);
    }

    for(int i= 0; i<n; i++){
        if(!dfsNumber[i])
            tarjan(i,-1);
    }
    ll ways = 1, mx , cnt = 0 , total = 0 ;
    for(auto e : scc){
        mx = INT_MAX , cnt = 0;
        for(auto w : e){
            if(value[w]<mx){
                mx=value[w];
                cnt=1;
            }
            else if(value[w]==mx){
                cnt++;
            }
        }
        total += mx;
        ways *= cnt;
        ways%=1000000007;
    }
    cout << total << " " << ways << endl;
}
