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

bool prime(ll x){
    if((x%2==0&&x!=2)||x==1)return 0 ;
    for(ll i = 3 ; i*i <= x ;i++)
        if(x%i==0)return 0 ;
    return 1;
}

int main(){

    file();
    int t ;
    cin >> t ;
    while(t--){
        ll x ;
        cin >> x ;
        if(ll(sqrt(x))*ll(sqrt(x))==x&&prime(sqrt(x)))cout << "YES" << endl;
        else cout << "NO" << endl;
    }







}
