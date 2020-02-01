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

    string s ;
    cin >> s ;
    int q ;
    cin >> q ;
    vector < int > v(szz(s)+1);
    while(q--){
        int a ;
        cin >> a;a--;
        v[a]++;
        v[szz(s)-a]--;
    }

    for(int i = 1 ; i < szz(s) ;i++)
        v[i]+=v[i-1];

    for(int i = 0 ; i < szz(s)/2;i++)
        if(v[i]&1)swap(s[szz(s)-i-1],s[i]);
    cout << s << endl;
}
