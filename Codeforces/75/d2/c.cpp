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
    ll n , m , q  ,a , b , x ;
    cin >> n >> m >> q;
    if(n>m)swap(n,m);
    set < int > st ;

    for(ll i = 1 ; i*i <= n ;i++){
        if(n%i==0&&m%i==0)st.insert(i);
        if(n%(n/i)==0&&m%(n/i)==0)st.insert(n/i);
    }

    while(q--){
        cin >> a >> b ;
        auto it = st.lower_bound(b);
        auto it2 = st.lower_bound(a);
        auto it1 = it ;
        if(it1!=st.begin())it1--;

        if(it2==st.end()||*it2>b)cout << -1 << endl;
        else if(*it==b)cout << *it << endl;
        else cout << *it1 << endl;
    }








}
