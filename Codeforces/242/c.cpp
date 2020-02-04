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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
map < pair < int , int > , bool > vis;

void bfs(int i , int j , int tarX , int tarY){

    queue < pair < pair < int , int > , ll > > q ;
    q.push({{i,j},0});

    while(szz(q)){
        pair < int , int > p = q.front().first ;
        ll dist = q.front().second;
        q.pop();

        if(!vis[p])continue;
        if(p.first==tarX&&p.second==tarY)stop(dist);
        vis[p]=0;

        for(int e = 0 ; e < 8 ;e++){
            int x = p.first+dx[e] , y = p.second + dy[e];
            if(x<0||y<0||!vis[{x,y}])continue;
                q.push({{x,y},dist+1});
        }
    }
    return ;
}

int main(){file();

    int x , y , x1 , y1 ;
    cin >> x >> y >> x1>> y1 ;

    int q;
    cin >> q ;

    for(int i = 0 ; i < q ;i++){
        int r , a , b  ;
        cin >> r >> a >> b ;
        for(int i = a ; i<= b ;i++)
            vis[{r,i}]=1;
    }
    bfs(x,y,x1,y1);
    cout << -1 << endl;
}
