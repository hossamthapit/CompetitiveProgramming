#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
using namespace std;
#define endl '\n'
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
}

int main(){file();

    int n , m , v , k  , ok = 1 , forbidden;
    cin >> n >> m >> v ;
    k = n -1 ;
    if(v==1)forbidden = 2;
    else forbidden = 1;

    if(m<n-1||m>(k*(k-1)/2+1))return cout << -1 << endl , 0 ;
    vector < int > vv;

    for(int i = 1 ;i <= n ;i++)
        if(i!=forbidden)vv.push_back(i);

    for(int i = 0 ; i+1 < szz(vv) ;i++)
        cout << vv[i] << " " << vv[i+1] << endl;

    m-=(n-2);

    for(int i = 0 ; i < szz(vv) && ok ;i++){
        for(int k = i+2 ; k < szz(vv) ;k++){
            if(m<=1){ok=0;break;}
            cout << vv[i] << " " << vv[k] << endl;m--;
        }
    }
    if(m)cout << forbidden << " " << v << endl;
}
