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


ll mod = 1000000007;
ll fast_power(ll x, ll y){
	if (y == 0)return 1;
	if (y == 1)return x;
	ll result = fast_power(x, y / 2) % mod;
	result = (result*result) % mod;
	if (y % 2 != 0)result = result * x;
	result %= mod;
	return result;
}

int main(){file();

    int n ;cin >> n ;
    for(int i = 1 ; i <= 100 ;i++){
        for(int j = 1 ; j <= 100 ;j++){
            for(int k = 1 ; k <= 100;k++){
                if(i==k||k==j||i==j)continue;
                if(fast_power(i,n)+fast_power(j,n)==fast_power(k,n))return cout << i << " " << j << " " << k , 0 ;
            }
        }
    }
    cout << -1 << endl;
}
