#include <bits/stdc++.h>
#define write ofstream file_out ; file_out.open("output.txt");
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read ifstream file_in ; file_in.open("input.txt");
typedef long long ll;typedef unsigned long long ull;
#define rer(i,n) for(int i = 0 ; i < n ;i++)
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
#define out(x) cout << x << endl
#define all(x) x.begin(),x.end()
#define szz(x) ll(x.size())
#define stop exit(0);
#define pb push_back
using namespace std;
#define endl '\n'
#define s second
#define f first
/*************/
bool vis[10][10];
char ar[10][10];
ll n , m , l , r , number ;
string s = "IEHOVA#";
vector < pair < char , string > >  vv ;

ll t = 0 ;
string ss ;
bool isfind(int x , int y){

    if(x<0||y<0||x>=n||y>=m||vis[x][y]||(ar[x][y]!=s[t]&&ar[x][y]!='@'))return false ;

    if(ar[x][y]!='@'){t++;vv.pb(make_pair(ar[x][y],ss));}
    vis[x][y]=1;
    ss = "right";isfind(x,y+1);
    ss = "left";isfind(x,y-1);
    ss = "forth";isfind(x+1,y);
    ss = "forth";isfind(x-1,y);
    vis[x][y]=0;
    t = 0 ;
}

int main(){fast write read

    cin >> number ;

    while(number--){
        cin >> n >> m ;
        memset(vis,0,vis[0][0]*10*10);
        vv.clear();
        rer(i,n){
            rer(k,m){
                cin >> ar[i][k];
                if(ar[i][k]=='@'){
                    l = i ;r = k ;
                }
            }
        }
        isfind(l,r);

        for(int i = 0 ; i < szz(vv)-6;i++)
            if(vv[i].f=='I'&&vv[i+1].f=='E'&&vv[i+2].f=='H'&&vv[i+3].f=='O'&&vv[i+4].f=='V'&&vv[i+5].f=='A'&&vv[i+6].f=='#'){
                for(int k = i ; k < i+7 ; k++)
                    if(k==i+6)cout << vv[k].s ;
                    else cout << vv[k].s << " ";
                }
        cout << endl;
    }

}
