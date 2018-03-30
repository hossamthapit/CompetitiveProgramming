#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

using namespace std ;

int main()
{
    ll x , sz , mn = INT_MAX;
    cin >> x ;

    string s ;
    cin >> s ;
    sz = s.size();

    map < char , int > mp ;
    map < char , int > tmp ;
    map < char , int > :: iterator it ;

    int l = 0 , r = 0 , mid;

    for( int i = 0 ; i < sz ; i++ )
        mp[s[i]]++;
    int ok = mp.size();

    while( r<sz && l < sz ){
        tmp[s[r]]++;
        if(tmp.size() == ok ){
            while(tmp[s[l]]-1 > 0 ){
                tmp[s[l]]--;
                l++;
            }
            if( r - l + 1 < mn )
                mn = (r + 1 ) - l ;
                
            tmp.erase(s[l]);
            l++;
            r++;
        }
        else if( tmp.size() < ok ){
            r++;
        }
    }
    cout << mn << endl;
}
