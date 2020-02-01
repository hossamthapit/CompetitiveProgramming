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

    ll a , b , c , d , idx=0;
    cin >> a >> b >> c >> d ;

    ll den = (b*d);
    a = (den/b)*a;
    c = (den/d)*c;
    b=den;d=den;
    if(a<c)swap(a,c);

    cout << (a*b-c*d)/__gcd(c*d,a*b) << "/" << (a*b)/__gcd(c*d,a*b) << endl;
}
