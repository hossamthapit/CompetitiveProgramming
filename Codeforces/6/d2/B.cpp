#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define all(x) x.begin(),x.end()
#define szz(s) ll(s.size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define endl '\n'

void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}
char ar[102][102];
bool vis[102][102];
ll n , m , ans = 0 ;

bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m ;
}

int main(){

    file();
    char c ;
    cin >> n >> m >> c ;
    set < char > st ;

    for(int i = 0 ; i < n ;i++)
        for(int k = 0 ; k < m ;k++)
            cin >>ar[i][k];

    for(int i = 0 ; i < n ;i++)
        for(int k = 0 ; k < m ;k++){
            if(ar[i][k]==c)
                for(int j = 0 ; j < 4 ;j++){
                    int xx = i+dx[j] , yy = k+dy[j];
                    if(valid(xx,yy)&&ar[xx][yy]!='.'&&ar[xx][yy]!=c)
                        st.insert(ar[xx][yy]);
                }
        }

    cout << max(szz(st),0LL) << endl;

}
