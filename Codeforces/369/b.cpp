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

    int team , k , mn , mx , total , kTotal  ;
    cin >> team >> k >> mn >> mx >> total >> kTotal ;

    vector < int > ans ;

    total -= kTotal ;
    team -= k;
    if(team){
        int value1 = total/team;
        for(int i = 0 ; i < team-(total%team) ; i++)ans.push_back(value1);
        for(int i = 0 ; i < (total%team) ; i++)ans.push_back(value1+1);
    }
    if(k){
        int value2 = kTotal/k;
        for(int i = 0 ; i < k-(kTotal%k) ; i++)ans.push_back(value2);
        for(int i = 0 ; i < (kTotal%k) ; i++)ans.push_back(value2+1);
    }

    for(auto e : ans)cout << e << " ";

}
