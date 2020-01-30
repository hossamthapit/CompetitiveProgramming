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

int n , m , shift = 0 ;

bool valid(int i , int j){
    return i>=0&&j>=0&&i<n&&j<m;
}
double dist(int x , int y , int x1 , int y1){
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}
map < char , double > charDist;
vector < string > v;
vector < bool > vis(26);

void solve(){
    for(int i = 0 ; i < n ;i++){
        for(int k = 0 ;k < m ;k++){
            if(v[i][k]!='S')continue;
            shift = 1;
            for(int i1 = 0 ; i1 < n ;i1++){
                for(int k1 = 0 ; k1 < m;k1++){
                    if(charDist.find(v[i1][k1])==charDist.end())
                        charDist[v[i1][k1]]=dist(i1,k1,i,k);
                    else
                        charDist[v[i1][k1]]=min(charDist[v[i1][k1]],dist(i1,k1,i,k));
                }
            }
        }
    }
}
int main(){file();

    int mxDist , q , ans = 0 , valid = 1 ;
    cin >> n >> m >> mxDist ;
    v.resize(n);
    for(auto &e:v)cin >> e ;
    for(auto e : v)for(auto r : e)if(r!='S')vis[r-'a']=1;
    solve();
    string s ;
    cin >> q >> s ;
    for(int i = 0 ; i < szz(s);i++){
        if(!vis[tolower(s[i])-'a']){valid=0;break;}
        else if(!vis[tolower(s[i])-'a']||(isupper(s[i])&&!shift)){valid=0;break;}
        else if(isupper(s[i])&&charDist[tolower(s[i])]>mxDist){ans++;}
    }
    if(!valid)cout << -1 << endl;
    else cout << ans << endl;
}
