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
        int c = 0 ;
        map < string , int > Hash ;
        tarjanTime = 0 ;
        adjList = vector < vector < int > > (n);
        dfsNumber = lowLink = sccID = vector < int > (n);
        inStack = vector < bool > (n);
        scc = vector < vector < int > > () ;
        stk = stack < int > ();

        string s1 , s2 , s3 , s4 ;
        for(int i = 0 ; i < n ;i++){
            cin >> s1 >> s2 ;
            Hash[s1+s2] = c;c++;
        }

        for(int k = 0 ; k < m ;k++){
            cin >> s1 >> s2 >> s3 >> s4;
            adjList[Hash[s1+s2]].push_back(Hash[s3+s4]);
        }

          for(int i = 0 ; i < n ;i++){
            if(!dfsNumber[i])
                tarjan(i);
          }

        cout << szz(scc) << endl;
    }
}
