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
vector < int > dfsNumber, lowLink, sccID;
vector < bool > inStack , notSCN;
stack < int > stk;
int tarjanTime;

void initializerTarjan(int n){
    scc = vector < vector < int > > ();
    adjList = vector < vector < int > >(n);
    dfsNumber = lowLink = sccID = vector < int >(n);
    inStack = notSCN = vector < bool > (n);
    tarjanTime = 0;
}

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
set < int > subDic2 ;

void dfs(int u){
    if(!notSCN[u])
        return ;
    notSCN[u]=0;
    subDic2.insert(u);

    for(auto p : adjList[u])
        if(notSCN[p])
            dfs(p);
}

int main()
{
    file();


    int n ;
    while(cin >> n&&n){
        int hashCnt=1;
        initializerTarjan(n+10);
        map < string , int > Hash ;
        map < int , string > index;
        subDic2.clear();

        for (int i = 0; i < n; i++)
        {
            string x , y , z ;
            cin >> x ;
            if(!Hash[x]){
                Hash[x]=hashCnt;
                index[hashCnt]=x;
                hashCnt++;
            }
            getline(cin,y);
            stringstream ss(y);

            while(ss>>z){
                if(!Hash[z]){
                    Hash[z]=hashCnt;
                    index[hashCnt]=z;
                    hashCnt++;
                }
                adjList[Hash[x]].push_back(Hash[z]);
            }
        }

        for(int i = 1 ; i < hashCnt ;i++)
            if(!dfsNumber[i])
                tarjan(i);

        set < int > subDic ;

        for(auto p : scc){
            if(szz(p)>1)
                for(auto w : p)
                    subDic.insert(w);
            else
                notSCN[p[0]]=1;
        }

        vector < string > ans ;

        for(auto p : scc)
            if(szz(p)>1)
                for(auto w : p)
                    for(auto q : adjList[w])
                        if(notSCN[q])
                            dfs(q);

        for(auto e : subDic)
            ans.push_back(index[e]);
        for(auto e : subDic2)
            ans.push_back(index[e]);

        sort(all(ans));

        cout << szz(ans) << endl;
        cout << ans[0];
        for(int i = 1 ; i < szz(ans);i++)
            cout << " " << ans[i];
        cout << endl;
    }
}
