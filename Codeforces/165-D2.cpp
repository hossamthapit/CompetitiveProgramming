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

    ll n , k , l , r , mid , nn , s=0 , ans = INT_MAX;
    cin >> n >> k ;
    l = 1 , r = n ;

    while(l < r){
        mid = ( l + r ) / 2 ;
        nn = k ;
        s = mid ;

        while(mid/nn){
            s+= mid /nn;
            nn*=k;
        }
   //     cout << mid << " " << s << endl;
        if(s>=n){
            r = mid ;
            if(mid < ans)ans = mid ;
        }
        else l = mid+1 ;
    }
    if(ans==INT_MAX)
        cout << n <<endl;
    else
        cout << ans << endl;
    
}
