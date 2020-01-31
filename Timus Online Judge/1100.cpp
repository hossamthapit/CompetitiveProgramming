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

    int n ;
    cin >> n ;
    vector < pair < int , pair < int, int > > > v(n);

    for(int i = 0 ; i < n ;i++){
        cin >> v[i].second.second >> v[i].first ;
        v[i].first=-v[i].first;
        v[i].second.first=i;
    }
    sort(all(v));
    for(auto e : v)
        cout << e.second.second << " " << -e.first << endl;

}
