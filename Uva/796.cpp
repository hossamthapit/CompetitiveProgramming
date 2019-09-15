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
vector < vector < int > > adj;
vector < int > dfsNum , dfsLow ,vis ;
vector < bool > ArcPoint;
vector < pair < int , int > > bridges;
int targanTimer,childs;

void targan(int node, int parent){
    dfsNum[node] = dfsLow[node] = ++targanTimer;
    for (auto child : adj[node]){
        if (!dfsNum[child]){
            if (parent == -1)
                childs++;
            targan(child, node);
            dfsLow[node] = min(dfsLow[node], dfsLow[child]);
	    if (dfsLow[child] > dfsNum[node])bridges.push_back({ min(child,node),max(child,node) });
        if (dfsLow[child] >= dfsNum[node])ArcPoint[node] = 1;
        }
        else if (child != parent){
            dfsLow[node] = min(dfsLow[node], dfsNum[child]);
        }
    }
}
int main()
{
    file();

    int n , x  , y , z;
    char a ;
    while(cin >>n)
    {
        targanTimer = 1 ;
        childs = 0;
        adj = vector < vector < int > > (n);
        vis = dfsNum = dfsLow = vector < int > (n);
        bridges = vector < pair < int , int > >() ;
        ArcPoint = vector < bool > (n);
        for (int i = 0; i < n; i++)
        {
            cin >> x ;
            cin >> a >> y >> a ;
            for(int k = 0 ; k < y ;k++){
                cin >> z ;
                adj[x].push_back(z);
                adj[z].push_back(x);
            }
        }
        for(int i=0; i<n; i++)
            if(!dfsNum[i])
                targan(i,-1);
        cout << szz(bridges) << " critical links" << endl;
        sort(all(bridges));
        for(auto r : bridges)
            cout << r.first << " - " << r.second << endl;
        cout << endl;
    }
}
