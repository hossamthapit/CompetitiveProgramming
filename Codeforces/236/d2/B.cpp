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

ll mod = (1LL<<30);
map < int, int > mp ;
ll factor(ll n){
    int c = 0 ;
    for(ll i = 1 ; i*i <= n ;i++)
        if(n%i==0)if(i!=n/i)c+=2;else c++;
    mp[n]=c;
    return c ;
}

int main(){
    file();
    ll a , b , c , s = 0 ;
    cin >> a >> b >> c ;

    for(int e = 1 ; e <= a ;e++)
        for(int w = 1 ; w <= b ;w++)
            for(int i = 1 ; i <= c ;i++)
                if(mp[e*w*i])s+= (mp[e*w*i]%mod),s%=mod;
                else s+= (factor(e*w*i)%mod),s%=mod;
    cout << s%mod << endl;

}
