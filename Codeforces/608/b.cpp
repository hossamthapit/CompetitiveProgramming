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

    string s , t ;
    cin >> s >> t ;
    vector < int > fre(szz(t));
    for(int i = 0 ; i < szz(t);i++)fre[i]=(t[i]-'0');
    for(int i = 1 ; i < szz(t);i++)fre[i]+=fre[i-1];

    ll ans = 0 ;
    for(int i = 0 ; i < szz(s);i++){
        int temp = ( fre[szz(t)-szz(s)+i] - (!i?0:fre[i-1]) ) ;
        if(s[i]=='1')ans+=((szz(t)-szz(s)+1)-temp);
        else ans += temp;
    }
    cout << ans << endl;
}
