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

int main(){file();

    int t ;
    cin >> t ;
    while(t--){
        int n , ans = 0 ;
        cin >> n ;
        for(int i = 1 ; i <= n ;i++){
            int fac = 0;
            for(int k = 1 ; k*k <= i ;k++)
                if(i%k==0&&k==i/k)fac++;
                else if(i%k==0)fac+=2;
            ans+= (fac&1);
        }
        cout << ans << endl;
    }
}
