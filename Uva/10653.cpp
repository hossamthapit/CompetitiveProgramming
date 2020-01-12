#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
int enx,eny , n , m;
vector < vector < int > > adj;
vector < vector < bool > > vis;

bool valid(int x , int y){
    return (x>=0&&y>=0&&x<n&&y<m);
}

int bfs(int x , int y){

    queue < pair < pair < int , int > , int > > qu;
    qu.push({{x,y},0});
    vis[x][y]=1;

    while(qu.size()){
         pair < pair < int , int > , int > p = qu.front();
         qu.pop();
         int x1 = p.first.first , y1 = p.first.second , dist = p.second;
         if(x1==enx&&y1==eny)return dist;

         for(int i = 0 ; i < 4 ; i++){
            int x2 = x1+dx[i] , y2 = y1+dy[i];
            if(valid(x2,y2)&&!adj[x2][y2]&&!vis[x2][y2]){
                vis[x2][y2]=1;
                qu.push({{x2,y2},dist+1});
            }
         }
    }
}
int main(){file();

    int q , stx ,sty ;
    while(cin >> n >> m  && n && m){
        adj = vector < vector < int > > (n,vector < int > (m,0));
        vis = vector < vector < bool > > (n,vector < bool > (m,0));
        cin >> q ;
        while(q--){
            int row , num , col;
            cin >> row >> num ;
            while(num--){
                cin >> col ;
                adj[row][col]=1;
            }
        }
        cin >> stx >> sty;
        cin >> enx >> eny;
        cout << bfs(stx,sty) << endl;
    }
}
