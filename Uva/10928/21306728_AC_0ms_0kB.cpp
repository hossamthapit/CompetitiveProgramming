#include <bits/stdc++.h>
#define write ofstream file_out ; file_out.open("output.txt");
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read ifstream file_in ; file_in.open("input.txt");
typedef long long ll;
typedef unsigned long long ull;
#define rer(i,n) for(int i = 0 ; i < n ;i++)
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
#define out(x) cout << x << endl;
#define all(x) x.begin(),x.end()
#define szz(x) ll(x.size())
#define stop exit(0);
#define pb push_back
using namespace std;
#define endl '\n'
/*************/

int main()
{
    fast write read

    ll t ,  p , c = 0 ;
    int mn ;

    string s ;
    pair < int , int > v[1005];
    cin >> t  ;
    while(t--){
        mn = INT_MAX;
        cin >> p ;
        for(int i = 0 ; i < p ;i++){
            getline(cin,s);
            if(s==""){i--;continue;}
            
            for(int e = 0 ; e < szz(s);e++)
                if(s[e]==' ')c++;c++;
            
            v[i].first=c;
            v[i].second=i+1;
            mn = min(mn,v[i].first);
            c = 0 ;
        }
        sort(v,v+p);
        cout << v[0].second ;
    
        for(int k = 1 ; k < p;k++){
            if(v[k].first==mn)cout <<" " <<  v[k].second ;
        }
        cout << endl;
    }
}
