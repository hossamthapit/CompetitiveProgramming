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

string k ;
int p = 0 , m = 0 , cor = 0 , fal = 0;

void solve(int idx = 0 , int p1 = 0 , int m1 = 0){
    if(idx==szz(k)){
        if(p1==p&&m1==m)cor++;
        else fal++;
        return ;
    }
    if(k[idx]=='?'||k[idx]=='+')
        solve(idx+1,p1+1,m1);
    if(k[idx]=='?'||k[idx]=='-')
        solve(idx+1,p1,m1+1);
}

int main(){file();

    string s ;
    cin >> s >> k ;
    int p1 = 0 , m1 = 0 ;
    cout << fixed << setprecision(10);
    for(auto e : s)(e=='+'?p++:m++);
    solve();
    cout << (cor*1.0)/(fal+cor) << endl;
}
