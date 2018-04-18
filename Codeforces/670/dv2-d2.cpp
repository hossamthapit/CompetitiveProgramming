#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file_out ; file_out.open("output.txt");
#define read  ifstream file_in ; file_in.open("input.txt");
#define ll_str(x,y) stringstream sdf;sdf<<x;string str=sdf.str();y=str;
#define str_ll(x,y) stringstream sstr(x);ll val;sstr>>val;y=val;
#define all(x) x.begin(),x.end()
#define endl '\n'
#define szz(x) x.size()
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
using namespace std;


int main()
{
    fast write read

    ll n , k  , l = 0 , r = 2000000001 , tmp , ans = 0 , mid , d ;
    cin >> n >> k ;

    unsigned long long ss = 0 ;
    vector < ll > v(n) ;
    vector < ll > have(n) ;

    for(int i = 0 ; i < n ;i++)
        cin >> v[i];
    for(int i = 0 ; i < n ;i++)
        cin >> have[i];

    tmp = k ;
    for(int i = 0 ; i < n ;i++){
        d = have[i];
            d-=(v[i]);
            if(d<0){
                d*=-1;
                tmp-=d;
            }
    }
    if(tmp<0){
        cout << 0 << endl;
        return 0 ;
    }

    tmp = k ;

    while(l < r){
        mid=(l+r)/2;
        tmp = k ;
        for(int i = 0 ; i < n ;i++){
            d = have[i];
            d-=(v[i]*mid);
            if(d<0){
                d*=-1;
                ss+=d;
                tmp-=d;
            }
        }
     //   cout << mid  << "         tmp = " << tmp <<endl;
        if(tmp < 0||ss>k){
            r = mid ;
        }
        else {
            l = mid +1 ;
            ans = mid ;
        }
        ss = 0 ;
    }

    cout << ans << endl;


}
