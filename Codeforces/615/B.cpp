#include<bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define TRACE(x) if(DEBUG) cerr << #x << " = " << x << endl;
#define TRACE2(x,y) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << endl;
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
using namespace std;
#define endl '\n'
void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int main(){file();

    int n , m ;
    cin >> n >> m ;
    vector < vector < int > > adj(n);
    vector < int > ar(n);
    vector < int > childs(n);

    for(int i = 0 ; i < m ;i++){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        adj[max(a,b)].push_back(min(a,b));
        childs[a]++;
        childs[b]++;
    }

    for(int i = 0 ; i < n ; i++)
        for(auto e : adj[i])
            ar[i] = max(ar[e]+1,ar[i]);

    ll ans = 0 ;
    for(int i = 0 ; i < n ; i++)
        ans = max(ans,childs[i]*1LL*(ar[i]+1));
    cout << ans << endl;
}
