#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file_out ; file_out.open("output.txt");
#define read  ifstream file_in ; file_in.open("input.txt");
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;

int main()
{fast write read

    ll n , m ;
    while(cin >> n >> m ){
        ll  a , c , k;
        pair < int , int > p ;
        map < pair < int , int > , int > mp ;
        vector < int > vis (1000009 , 0);

        for(int i = 0 ; i < n ; i++){
            cin >> a ;
            p.first = a ;
            p.second = ++vis[a];
            mp[p] = i + 1;
        }

        while(m--){
            cin >> c >> k ;
            p.first = k ;
            p.second = c ;
            cout << mp[p] << endl;
        }
        mp.clear();
        vis.clear();
    }
}
