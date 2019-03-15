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

int main(){
    file();

    ll n , mx = -1  ;
    cout << "PERFECTION OUTPUT" << endl;
    vector < pair < int , string > > vv ;
    while(cin >> n && n){
        set < int > st ;
        for(ll i = 2 ; i*i <= n;i++)
            if(n%i==0)st.insert(i),st.insert(n/i);
        ll s = 1 ;
        for(auto d : st)
            s+=d;

        if(s==n&&n!=1)vv.push_back({n, "PERFECT"});
        else if(s>n)vv.push_back({n, "ABUNDANT"});
        else vv.push_back({n, "DEFICIENT"});
        mx = max(mx,ll(log10(n))+1);
    }

    for(int i = 0 ; i < szz(vv);i++){
        int k = ll(log10(vv[i].first))+1;
        while(k<mx)
            cout << ' ',k++;
        cout << vv[i].first << "  " << vv[i].second << endl;
    }
    cout << "END OF OUTPUT" << endl;

}
