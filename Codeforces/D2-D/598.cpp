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
using namespace std;
#define endl '\n'
#define s second
#define f first
char ar[1004][1004];
int v[1004][1004];
int c = 0 , n , m  ;
bool a = 0 ;

bool valid(int x , int y){
    return (x >=1 && y>=1 && x <=n && y <=m);
}
map < pair < int , int > , int  > mp ;
vector < pair < int , int > > pairs ;
pair < int , int > p ;

int component(int x , int y){

    if(valid(x,y)==0||v[x][y]!=0||ar[x][y]=='*')return false;

    v[x][y]=1 ;
    if(valid(x-1,y)&&ar[x-1][y]=='*')c++;
    if(valid(x+1,y)&&ar[x+1][y]=='*')c++;
    if(valid(x,y-1)&&ar[x][y-1]=='*')c++;
    if(valid(x,y+1)&&ar[x][y+1]=='*')c++;
    p.f = x ;
    p.s = y ;
    pairs.push_back(p);

    component(x-1,y);
    component(x,y-1);
    component(x+1,y);
    component(x,y+1);
}

int main(){fast write read

    int k , l , r ;
    cin >> n >> m  >> k ;
    for(int i = 1 ; i <= n ;i++)for(int k = 1 ; k <= m ;k++)cin>>ar[i][k];

    rer(i,k){
        cin >> l >> r ;
        p.f = l ; p.s = r ;
        if(mp[p]!=0)cout << mp[p] << endl;
        else {
            component(l,r);
            for(int i = 0 ; i < szz(pairs);i++){
                mp[pairs[i]]=c;
            }
            pairs.clear();
            cout << c << endl;
        }
        c = 0 ;

    }

}
