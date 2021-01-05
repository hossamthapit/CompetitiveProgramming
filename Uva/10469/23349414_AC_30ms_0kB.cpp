#include<bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif
#define stop(x) {cout<<x<<endl;exit(0);}
#define TRACE(x) if(DEBUG) cerr << #x << " = " << x << endl;
#define TRACE2(x,y) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << endl;
#define TRACE3(x,y,z) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << " | " << #z << " = " << z << endl;
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;
void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int main(){file();

    ll x , n , y;
    while(cin >> x >> y ){
      //  if(v)cout << endl;
        bitset < 40 > btsX , btsY ;
        btsX = x ;
        btsY = y ;

        ll mx = 0 ;

        for(int i = 0 ; i < 40;i++)
            btsX[i]=(btsY[i]+btsX[i])%2;

        for(int i = 0 ; i < 40;i++)
            if(btsX[i])mx += (1LL<<i);

        cout << mx << endl;
    }


}
