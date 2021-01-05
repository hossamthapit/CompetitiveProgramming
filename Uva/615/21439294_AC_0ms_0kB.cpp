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
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector < vector < int > > adj ;
vector < int > vis , par ;
map < int , int > numbers , child ;

void dfs(int u){
    vis[u]=1;
    for(auto p : adj[u])
        if(!vis[p])
           dfs(p);
}

int main()
{
    file();
    int  a , b = 2 , k = 1;
    while(1)
    {
        adj = vector < vector < int > > (100001);
        par = vector < int > (100001);
        vis = vector < int > (100001,0);
        set < int > vertices;
        bool valid = 1;
        while(cin >> a >> b){
            if(!a&&!b)
                break;
            else if(a==-1&&b==-1)
                return 0 ;
            numbers[a]=1;
            numbers[b]=1;
            if(child[b])valid=0;
            child[b]=1;
            adj[a].push_back(b);
            vertices.insert(a);
            vertices.insert(b);
        }

        int rot , c = 0 ;
        for(auto i : numbers)
            if(!child[i.first])
                rot = i.first;

        dfs(rot);

        for(auto p : vertices)
            if(!vis[p])
                valid=0;

        if(valid)cout << "Case " << k << " is a tree." << endl;
        else cout << "Case " << k << " is not a tree." << endl;

        k++;
        child.clear();
        numbers.clear();
        //return 0 ;

    }




}
