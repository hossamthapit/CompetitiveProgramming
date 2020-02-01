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
    deque < int > q(n);
    for(auto &e : q)cin >> e;
    while(szz(q)&&q.front()==0)q.pop_front();
    while(szz(q)&&q.back()==0)q.pop_back();

    ll ans = (szz(q)>0) , cnt = 0 ;
    for(int i = 0 ; i < szz(q);i++){
        if(q[i]==0)cnt++;
        else {
            ans *=max(cnt+1,1LL);
            cnt=0;
        }
    }
    ans *= max(cnt+1,1LL);
    cout << ans << endl;
}
