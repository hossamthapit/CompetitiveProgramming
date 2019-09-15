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
vector < int > dfsNum , dfsLow ;
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
            if (dfsLow[child] >= dfsNum[node])
                ArcPoint[node] = 1;
        }
        else if (child != parent){
            dfsLow[node] = min(dfsLow[node], dfsNum[child]);
        }
    }
}

int main()
{
    file();

    int n, m , t;
    while(cin >> n&& n){
        targanTimer = 0 ;
        childs = 0;
        adj = vector < vector < int > > (n);
        dfsNum = dfsLow = vector < int > (n);
        ArcPoint = vector < bool > (n);

        int a , b ;
        string s ;
        while(1){
            cin >> a ;
            if(!a)break;
            getline(cin,s);
            stringstream List(s);
            while(List>>b){
                adj[a-1].push_back(b-1);
                adj[b-1].push_back(a-1);
            }
        }
        int c = 0 ;
        targan(0,-1);
        ArcPoint[0] = (childs > 1);
        for(int i=0; i<n; i++)
            if(ArcPoint[i])
                c++;
        cout << c << endl;
    }
}
