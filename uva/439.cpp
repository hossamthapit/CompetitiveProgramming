#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int dxx[] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int dyy[] = { 1, -1, 1, -1, 2, 2, -2, -2 };
typedef long long ll;
using namespace std;

void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int bfs(pair < int , int > &source , pair < int , int > &dest){
    vector < vector < int > > vis(9,vector < int > (9,0));
    queue < pair < pair < int , int > , int > > q ;
    q.push({source,0});

    while(q.size()){
        pair < pair < int , int > , int > p = q.front();q.pop();
        vis[p.first.first][p.first.second]=1;
        if(make_pair(p.first.first,p.first.second)==dest)return p.second;
        for(int i = 0 ; i < 8 ;i++){
            int x = p.first.first+dxx[i] , y = p.first.second+dyy[i];
            if(x>=1&&x<=8&&y>=1&&y<=8){
                vis[x][y]=1;
                q.push({{x,y},p.second+1});
            }
        }
    }
}

int main(){file();

    string s , d ;
    pair < int , int > src , dest ;

    while(cin >> s >> d ){
        src.first = (s[0]-'a')+1;
        src.second = (s[1]-'0');
        dest.first = (d[0]-'a')+1;
        dest.second = (d[1]-'0');
        cout << "To get from " << s << " to " << d << " takes " << bfs(src,dest) << " knight moves." << endl;
    }

}
