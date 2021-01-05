#include <bits/stdc++.h>
typedef long long ll;typedef unsigned long long ull;const int M6 = 1e6+5 , M5 = 1e5+5;
#define out2d(n,m,s,v) for(int i=s;i<n;i++){for(int k=s;k<m;k++)cout<<v[i][k]<<" ";cout<<endl;}
ll gcd(ll first, ll second) { return !second ? first : gcd(second, first % second);}
ll lcm(ll first, ll second) { return (first / gcd(first, second)) * second; }
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 }; int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
#define loop(i,n,s) for(int i=s;i<n;i++)
#define mim(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define szz(x) ll(x.size())
#define stop exit(0);
using namespace std;
#define endl '\n'
/**************/


int main(){FAST

    int t ;
    cin >> t ;
    while(t--){
        string s ;
        cin >> s ;
        map < char , int > mp ;
        for(auto c : s){
            mp[c]++;
        }

        cout << min(min(min(min(min(mp['M'],mp['T']),mp['I']),mp['G']),mp['R']/2),mp['A']/3) << endl;
    }




}