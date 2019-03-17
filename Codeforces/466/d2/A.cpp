#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define all(x) x.begin(),x.end()
#define szz(s) ll(s.size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define endl '\n'

void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}

int main(){

    file();
    ll a , b , n , m , z1 = 0 , z2 = 0 , z3 = 0 ;
    cin >> n >> m >> a >> b ;

    z1 = ( (n/m)+(n%m!=0) ) * b ;
    z2 = a * n ;
    z3 = (n/m) * b + (n%m) * a ;

    cout << min(min(z1,z2),z3) << endl;


}
