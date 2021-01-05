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
	freopen("input.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
}

int main(){
    file();
    int t ;
    cin >> t ;
    for(int te = 1 ; te <= t ;te++){
        int n ;
        cin >> n ;
        vector < int > v(n) , cpy(n);
        for(int i = 0 ; i < n ;i++)
            cin >> v[i];
        for(int i = 1 ; i < n;i++)
            cpy[i] = abs(v[i]-v[i-1]);
        cpy[0]=v[0];

        int l = 0 , r = 1e9 ,mid , ans , k ;
        while(l<=r){
            mid = (l+r)/2;
            bool valid = 1 ;
            k = mid ;
            for(int i = 0 ; i < n ;i++){
                if(k==cpy[i])k--;
                else if(k<cpy[i]){valid = 0 ;break;}
            }

            if(valid){
                r = mid - 1 ;
                ans = mid ;
            }
            else
                l = mid +1 ;

        }
        cout << "Case " << te << ": " << ans << endl;
    }
}
