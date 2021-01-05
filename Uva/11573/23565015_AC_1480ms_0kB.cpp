#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx4[] = { 0, 0, 1, -1};
int dy4[] = { 1, -1, 0, 0};
int dx8[] = { -1,-1, 0, 1, 1, 1, 0, -1 };
int dy8[] = { 0 , 1, 1, 1, 0,-1,-1, -1 };
typedef long long ll;
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
int n , m ;
int r1 , r2 , c1 , c2 ;

vector < string > adj;
bool vis2[1002][1002];
bool vis1[1002][1002];


bool valid(int x , int y){
    return (x>=0&&y>=0&&x<n&&y<m);
}

void genNew(set < pair < int , int > > &v){
    set < pair < int , int > > st;
    for(auto p : v){
        for(int i = 0 ; i < 8 ;i++){
            int x1 = p.first+dx8[i] , y1 = p.second+dy8[i] ;
            if(valid(x1,y1)&&!vis1[x1][y1]&&!vis2[x1][y1]){
                vis2[x1][y1]=1;
                st.insert({x1,y1});
            }
        }
    }
    v = st;
}

set < pair < int , int > > tempPairs;

void dfs(int r1 , int c1){
    if(vis1[r1][c1])return ;
    vis1[r1][c1]=1;
    tempPairs.insert({r1,c1});
    int idx = (adj[r1][c1]-'0');
    int r = r1+dx8[idx] , c = c1+dy8[idx];
    if(valid(r,c))dfs(r,c);
}

void debug(){
    for(int i= 0 ; i < n ;i++){
        for(int k = 0 ; k < m ;k++){
            cout << vis1[i][k];
        }
        cout << endl;
    }
}

int solve(set < pair < int , int > > vv){
    int ans = 0;
    set < pair < int , int > > v = vv ;
    while(1){
        tempPairs.clear();
        for(auto e : v)
            dfs(e.first,e.second);

        if(vis1[r2][c2])return ans;
        ans++;
        genNew(tempPairs);
        v = tempPairs;
    }
}



int main(){file();

    int q ;
    cin >> n >> m ;
    adj = vector < string > (n);
    for(auto &e : adj)cin >> e ;

    cin >> q ;
    while(q--){
        memset(vis1,0,sizeof vis1);
        memset(vis2,0,sizeof vis2);
        cin >> r1 >> c1 >> r2 >> c2 ;
        r1--;c1--;r2--;c2--;

        set < pair < int , int > > vv1;
        vv1.insert({r1,c1});
        cout << solve(vv1) << endl;
    }
}
