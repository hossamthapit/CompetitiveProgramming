#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;

void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


int main()
{
    file();

    int n , m , a ;
    cin >> n >> m ;
    map < int , set < int > > mp ;
    set < pair < int , int > > ans ;
    vector < int > colors(n+1);
    for(int i = 0 ; i < n ;i++){
        cin >> colors[i+1];
        mp[colors[i+1]].insert(colors[i+1]);
    }
    while(m--){
        int a , b ;
        cin >> a >> b ;
        a = colors[a];
        b = colors[b];
        mp[a].insert(b);
        mp[b].insert(a);
    }

    for(auto p : mp)
        ans.insert({szz(p.second)*-1,p.first});

    for(auto p : ans){
        cout << p.second << endl;
        break;
    }

}
