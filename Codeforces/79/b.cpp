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

    int n , m , w , q ;
    cin >> n >> m >> w >> q ;
    vector < pair < int , int > > pairs(w);
    for(auto &e : pairs){cin >> e.first >> e.second;e.first--;e.second--;}
    sort(all(pairs));

    for(int i = 0 ; i < q ;i++){
        int a , b , c = 0 , waste = 0;
        cin >> a >> b ;a--;b--;
        for(int k = 0 ; k < w;k++){
            if(a>pairs[k].first||(a==pairs[k].first&&b>pairs[k].second))c++;
            else if(a==pairs[k].first&&b==pairs[k].second){waste=1;break;}
            else break;
        }
        if(waste)cout << "Waste" << endl;
        else if(((a*m+b)-c)%3==0)cout << "Carrots" << endl;
        else if(((a*m+b)-c)%3==1)cout << "Kiwis" << endl;
        else cout << "Grapes" << endl;
    }
}
