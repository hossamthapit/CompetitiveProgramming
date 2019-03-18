#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define all(x) x.begin(),x.end()
#define szz(s) ll(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
}

int vis[200];
int main(){
    file();

    ll n , m, a , ss = 0;
    cin >> n >> m ;
    vector < int > v(n) , no , au ;
    for(int i = 0 ; i < n ;i++)
        cin >> v[i];

    for(int k = 0 ; k < m ;k++){
        cin >> a ;
        vis[a]++;
    }

    for(int i = 0 ; i < n ;i++){
        if(vis[i+1])au.push_back(v[i]);
        else ss+=v[i];
    }

    sort(all(au));
    reverse(all(au));

    for(int i = 0 ; i < szz(au);i++){
        if(ss*2>ss+au[i]){
            ss*=2;
        }
        else {
            ss+=au[i];
        }
    }

    cout << ss << endl;


}
