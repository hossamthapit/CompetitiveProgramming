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

    int r , x , y ;
    cin >> r >> x >> y ;
    if(y%r==0)return cout << -1 , 0 ;
    if(x<r/2.&&x>-r/2.&&y<r)return cout << 1 , 0 ; /// for first layer
    else if(y<r)return cout << -1 , 0 ; /// for first layer

    int layer = y/r;

    if(layer&1){
        int idx = (layer/2)*2 + (layer-(layer/2));
        if(x<r/2.&&x>-r/2.)return cout << idx+1 , 0 ;
        else return cout << -1 , 0 ;
    }
    else{
        int idx = (layer/2)*2 + (layer-(layer/2));
        if(x<r&&x>0)return cout << idx+1 , 0 ;
        if(x>-r&&x<0)return cout << idx , 0 ;
        else return cout << -1 , 0 ;
    }
}
