#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define szz(s) ll(s.size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define endl '\n'

void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}


int main(){

    file();
    ll x , y , x1 , y1;
    cin >> x >> y >> x1 >> y1 ;
    int xx = min(x1,x);
    int yy = min(y1,y);
    int d = max(abs(x-x1),abs(y-y1));

    if(abs(x-x1)!=abs(y-y1)&&abs(x-x1)!=0&&abs(y-y1)!=0)return cout << -1 , 0 ;

    set < pair < int , int > > st ;
    st.insert({xx,yy});
    st.insert({xx+d,yy});
    st.insert({xx,yy+d});
    st.insert({xx+d,yy+d});

    for(auto p : st)
        if(!(p.first==x&&p.second==y)&&!(p.first==x1&&p.second==y1))cout << p.first << " " << p.second << " ";






}
