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
map < int , int > mp ;
bool vis[1000005];

void factor(){

    for(int i = 2 ; i <= 1000000 ;i++)
        if(!vis[i])
            for(int k = i ; k <= 1000000 ;k+=i)
                mp[k]++,vis[k]=1;

}

int main(){
    file();
    ll n ;
    factor();
    while(cin >> n && n){
        cout << n << " : " << mp[n] << endl;
    }

}
