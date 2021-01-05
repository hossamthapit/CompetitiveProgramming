#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}

vector < vector < char > > v  ;
bool vis[100][100];
int n  ;

bool valid(int x , int y){
    return(x>=0&&y>=0&&x<n&&y<n);
}

void dfs(int x , int y){
    if(!valid(x,y)||vis[x][y]||v[x][y]!='1')return ;
    vis[x][y]=1;

    for(int i = 0 ; i < 8;i++)
            dfs(x+dx[i] , y + dy[i]);
}

int main(){file();

    int t = 1 ;
    while(cin >> n){
        int c = 0 ;
        memset(vis,0,sizeof vis);
        v.resize(n, vector < char > (n));
        for(int i = 0 ; i < n ;i++){
            for(int k = 0 ; k < n ;k++){
                cin >> v[i][k];
            }
        }

        for(int i = 0 ; i < n ;i++){
            for(int k = 0 ; k < n ;k++){
                if(!vis[i][k]&&v[i][k]=='1'){
                    dfs(i,k);
                    c++;
                }
            }
        }

        cout << "Image number " << t << " contains " << c << " war eagles." << endl;
        t++;

    }






}
