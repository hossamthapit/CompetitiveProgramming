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
int arr[8][8];

int main()
{fast write read

    string s ;
    ll ss , sss , k , x  ;
    map < ll , ll > mp ;
    set < pair < ll , ll > > st ;
    set < pair < ll , ll > > :: iterator it ;
    pair < ll ,ll > p , pp ;

    while(cin >> s ){
        if(s=="#")break;
        cin >>ss >> sss;
        p.first = sss;
        p.second = ss ;
        st.insert(p);
        mp[ss]=sss;
    }
    cin >> k ;

    while(k--){
        p = *st.begin();
        st.erase(st.begin());
        cout << p.second  << endl;
        pp.first = p.first ;
        pp.first += mp[p.second];
        pp.second = p.second;
        st.insert(pp);
    }
}
