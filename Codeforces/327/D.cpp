#include <bits/stdc++.h>
#define write ofstream file_out ; file_out.open("output.txt");
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read ifstream file_in ; file_in.open("input.txt");
typedef long long ll;typedef unsigned long long ull;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
#define rep(i,s,n) for(int i=s;i<n;i++)
#define all(x) x.begin(),x.end()
#define szz(x) ll(x.size())
#define stop exit(0);
using namespace std;
#define endl '\n'
/**************/
ll n , m ;
char ar[600][600];
bool vis[600][600];
pair < int , int > p ;
deque < pair < int , int > > tmp  , cpy;
pair < char , pair < int ,int > > pp ;
vector < pair < char , pair < int , int > > > ans ;

bool valid(int x ,int y){
    return (x>=1&&y>=1&&x<=n&&y<=m&&ar[x][y]=='.');
}

void fun(int x , int y){

    if(!valid(x,y)||vis[x][y])return ;
    vis[x][y]=1;
    p.first = x ; p.second = y ;
    tmp.push_front(p);
    cpy.push_front(p);
    fun(x,y-1);
    fun(x,y+1);
    fun(x-1,y);
    fun(x+1,y);

}


int main(){fast write read

    cin >> n >> m ;
    n++;
    m++;
    rep(i,1,n)
        rep(k,1,m)
            cin >> ar[i][k];

    rep(i,1,n)
        rep(k,1,m){
            fun(i,k);

            while(szz(tmp)){
                pp.first = 'B';
                pp.second.first = tmp.front().first ;
                pp.second.second = tmp.front().second;
                ans.push_back(pp);
                tmp.pop_front();
            }
            while(szz(cpy)>1){
                pp.first = 'D';
                pp.second.first = cpy.front().first ;
                pp.second.second = cpy.front().second;
                ans.push_back(pp);
                pp.first = 'R';
                pp.second.first = cpy.front().first ;
                pp.second.second = cpy.front().second;
                ans.push_back(pp);

                cpy.pop_front();
            }
            cpy.clear();
            tmp.clear();
        }
        cout <<szz(ans) << endl;
        for(auto c : ans){
            cout << c.first << " " << c.second.first << " " << c.second.second << endl;
        }

}
