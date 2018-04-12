#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file_out ; file_out.open("output.txt");
#define read  ifstream file_in ; file_in.open("input.txt");
#define all(x) x.begin(),x.end()
#define ll_str(x,y) stringstream sdf;sdf<<x;string str=sdf.str();y=str;
#define str_ll(x,y) stringstream sstr(x);ll val;sstr>>val;y=val;
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
using namespace std;


int main()
{fast write read

    int t ;
    cin >> t ;
    for(int tt = 1 ; tt <= t ;tt++){

        ll n , m , k , a , l = 0 , r = 0 , c = 0 , mn = LONG_MAX;

        cin >> n >> m >> k;
        vector < ll > v(1000003) ;
        vector < int > vis(1003,0);

        v[0]=1;
        v[1]=2;
        v[2]=3;

        for(int i = 3 ; i < n ; i++)
            v[i] = (v[i-1]+v[i-2]+v[i-3])%m +1 ;


        while( l <= r && r <= n ){

            for(int i = 1 ; i <= k ;i++)
                if(vis[i])c++;

            if (c == k){
                mn = min(mn,(r-l));
                vis[v[l]]--;
                l++;
            }
            else if(c < k){
                vis[v[r]]++;
                r++;
            }
            c=0;
        }

        if(mn!=LONG_MAX){
            cout << "Case " << tt << ": " <<  mn << endl;
        }
        else
            cout << "Case " << tt << ": " << "sequence nai" << endl;
        v.clear();
    }

}
