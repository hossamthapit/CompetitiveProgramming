#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define all(x) x.begin(),x.end()
#define szz(s) ll(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
}

int vis[200005];
int main(){
    file();

    int n , m ;
    while(cin >> n >> m ){
        vector < int > v(n);
        for(int i = 0 ; i < n ;i++)
            cin >> v[i];

        ll l = *max_element(all(v)) , r = 1e18 , mid , s = 0 , ans = 0 , c =0 ;

        while(l<=r){
            mid = (l+r)/2 ;
            s = 0 ;
            c = 0 ;

            for(int i = 0 ; i < n ;i++){
                if(s+v[i]<=mid){
                    s+=v[i];
                }
                else {
                    c++;
                    s = v[i];
                }
            }
            if(s)c++;

            if(c<=m){
                ans = mid ;
                r= mid-1;
            }
            else
                l = mid+1;
        }
        cout << ans << endl;
    }
}
