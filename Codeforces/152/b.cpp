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

int n , m ;

bool valid(ll x , ll y){
    return (x>0&&y>0&&x<=n&&y<=m);
}

int getSteps(ll &x , ll &y , ll xMove , ll yMove){
    ll l = 0 , r = 1e9+2 , mid , ans = 0 ;
    while(l<=r){
        mid = (l+r)/2;
        if(valid(x+xMove*mid,y+yMove*mid)){
            ans = mid ;
            l = mid+1;
        }
        else
            r = mid-1;
    }
    x = x+xMove*ans;
    y = y+yMove*ans;
    return ans;
}

int main(){file();

    ll x , y , q , ans = 0 ;
    cin >> n >> m >> x >> y >> q ;

    while(q--){
        int a , b ;
        cin >> a >> b ;
        ans += getSteps(x,y,a,b);
    }
    cout << ans << endl;
}
