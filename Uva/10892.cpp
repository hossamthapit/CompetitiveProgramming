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
    freopen("input.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
}

ll lcm(ll x , ll y){
    return (x*y)/__gcd(x,y);
}

int main(){

    file();
    ll n ;
    while(cin >> n&&n!=0){

        set < ll > tri;
        set < pair < ll , ll > > st ;
        for(ll i = 1 ; i*i <= n;i++)
            if(n%i==0)tri.insert(i),tri.insert(n/i);

        for(auto k : tri)
            for(auto i : tri)
                if(lcm(i,k)==n)
                    st.insert({max(i,k),min(i,k)});
        cout << n << " " << szz(st) << endl;

    }







}
