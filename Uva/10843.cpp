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
ll mod  = 2000000011;
long long fast_power(int x, int y)
{
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	long long result = fast_power(x, y / 2) % mod;
	result = (result*result) % mod;
	if (y % 2 != 0)
		result = result * x;
	result %= mod;
	return result;
}

int main(){file();


    ll t ;
    cin >> t ;
    while(t--){
        ll n ;
        cin >> n ;
        cout << fast_power(n,max(n-2,0LL)) << endl;

    }
}
