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
vector < vector < int > > adjList;
vector < vector < int > >  scc;
vector < int > dfsNumber, lowLink, sccID;
vector < bool > inStack;
stack < int > stk;
int tarjanTime;

void tarjan(int node) {
	dfsNumber[node] = lowLink[node] = ++tarjanTime;
	inStack[node] = 1;
	stk.push(node);
	for (auto child : adjList[node]) {
	//	if (child == par)continue;
		if (!dfsNumber[child]) {
			tarjan(child);
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

    int n, m , t;
    while(cin >> n >> m && n){
        tarjanTime = 0 ;
        adjList = vector < vector < int > > (n);
        dfsNumber = lowLink = sccID = vector < int > (n);
        inStack = vector < bool > (n);
        scc = vector < vector < int > > () ;
        stk = stack < int > ();

        int a , b , c ;
        for(int i = 0 ; i < m ;i++){
            cin >> a >> b >> c ;
            a--;b--;
            adjList[a].push_back(b);
            if(c==2)adjList[b].push_back(a);
        }
        for(int i = 0 ; i < n ;i++){
        if(!dfsNumber[i])
            tarjan(i);
        }

        if(szz(scc)==1)cout << 1 << endl;
        else cout << 0 << endl;
    }
}
