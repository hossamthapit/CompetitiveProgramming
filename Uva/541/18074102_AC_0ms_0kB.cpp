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

int ar[105][105];
int main(){FAST

    ll n ;
    while(cin>>n&&n){
        mim(ar,0);

        for(int i = 0 ; i < n ;i++){
            for(int k = 0 ; k < n ;k++){
                cin >> ar[i][k];
                ar[i][n]+=ar[i][k];
            }
        }
        for(int i = 0 ; i < n ;i++){
            for(int k = 0 ; k < n ;k++){
                ar[n][i]+=ar[k][i];
            }
        }
        int col = 0 , row = 0 , r , c ;

        for(int i = 0 ; i < n ;i++)
            if(ar[i][n]&1){row++;r=i+1;}

        for(int i = 0 ; i < n ;i++)
            if(ar[n][i]&1){col++;c=i+1;}

        if(row==col&&row==1)
            cout << "Change bit (" << r << "," << c << ")" << endl;
        else if(row==col&&col==0)
            cout << "OK" << endl;
        else cout << "Corrupt" << endl;





    }



}
