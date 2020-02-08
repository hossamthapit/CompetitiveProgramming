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

    ll a , b , c , d , ans = 0 ;
    cin >> a >> b >> c >> d ;

    if(c==d)cout << a << endl;
    else if(c>d)cout << b*(c-d)*2 + a*((c-d)+1) << endl;
    else cout << b*(d-c)*2 + a*((d-c)-1) << endl;

}
