#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
}

int main(){
    file();

    ll n , a ,b , z  ;
    cin >> n >> a >> b ;
    for(int i = 0 ; i < n; i++){

        cin >> z ;
        ll mid , l = 0 , r = z , ans = 0 , k = (z*a)/b;

        while(l<=r){
            mid = (l+r)/2;

            if(ll((mid*a)/b)<k)
                l = mid+1;
            else {
                r = mid-1;
                ans = mid ;
            }
        }
        cout << z - ans << " ";
    }

}
