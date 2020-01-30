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

    int p , q , l , r , a , b , ans = 0 ;
    cin >> p >> q >> l >> r ;
    set < pair < int , int > > pp , qq;

    for(int i = 0 ; i < p ;i++){
        cin >> a >> b;
        pp.insert({a,b});
    }
    for(int i = 0 ; i < q ;i++){
        cin >> a >> b;
        qq.insert({a,b});
    }

    for(int i = l ; i <= r ;i++){
        bool valid = 0 ;
        for(auto e : qq){
            int x = e.first+i, y = e.second+i;
            for(auto r : pp){
                int xx = r.first, yy = r.second;
                if((x>=xx && x<=yy)||(y>=xx&&y<=yy)){valid=1;break;}
                else if((xx>=x && xx<=y)||(yy>=x&&yy<=y)){valid=1;break;}
            }
            if(valid)break;
        }
        ans += valid;
    }
    cout << ans << endl;
}
