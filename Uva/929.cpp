#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define OO 9000000
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;
void file(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
int n , m ;
vector < vector < int > > ar , dist;

bool valid(int x , int y){
    return (x>=0&&y>=0&&x<n&&y<m);
}

int dijkstra(){
    priority_queue < pair < int , pair < int , int > > > q ;
    q.push({-ar[0][0],{0,0}});
    dist[0][0]=ar[0][0];

    while(szz(q)){
        int d = -q.top().first;
        pair < int , int > u = q.top().second;
        q.pop();
        int x = u.first , y = u.second;

        if(x==n-1&&y==m-1)return d ;
        if(d > dist[x][y])continue;

        for(int i = 0 ; i < 4 ;i++){
            int x1 = x+dx[i] , y1 = dy[i]+y;
            if(valid(x1,y1)&&dist[x1][y1] > dist[x][y]+ar[x1][y1]){
                dist[x1][y1] = dist[x][y]+ar[x1][y1];
                q.push({-dist[x1][y1],{x1,y1}});
            }
        }
    }
}

int main(){file();

    int t;
    cin >> t ;
    while(t--){
        cin >> n >> m ;
        dist = vector < vector < int > > (n,vector < int > (m,OO));
        ar = vector < vector < int > > (n,vector < int > (m));
        for(int i = 0 ; i < n ;i++)
            for(int k = 0 ; k < m ;k++)
                scanf("%d",&ar[i][k]);
        printf("%d\n",dijkstra());
    }
}
