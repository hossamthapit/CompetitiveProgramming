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

    int n;
    while(cin >> n&&n){
        int S = 0 , O = 0 ;
        vector < pair < int , int > > v(n);
        for(auto &e : v)cin >> e.first >> e.second ;

        int x = v[n/2].first , y = v[n/2].second ;
        for(auto e : v){
            if(e.second==y||e.first==x)continue;
            if((e.first>=x)^(e.second>=y))O++;
            else S++;
        }
        cout << S << " " << O << endl;
    }
}  

