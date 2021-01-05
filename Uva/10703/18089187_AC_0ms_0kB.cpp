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

int ar[555][555];
int main(){FAST

    int n , m , q ;
    while(cin >> m >> n >> q){
        if(m==0)break;
        mim(ar,0);
        while(q--){
            int x , y , x1 , y1 ;
            cin >> y >> x >> y1 >> x1 ;

            if(x>x1)swap(x,x1);
            if(y>y1)swap(y,y1);

            ar[x][y]+=1;
            ar[x][y1+1]-=1;
            ar[x1+1][y]-=1;
            ar[x1+1][y1+1]+=1;
        }
        for(int i = 1 ; i < n+3;i++)
            for(int k = 1 ; k < m+3 ;k++)
                ar[i][k]+=ar[i][k-1];
        for(int k = 1 ; k < m+3 ;k++)
            for(int i = 1 ; i < n+3;i++)
                ar[i][k]+=ar[i-1][k];
        int c = 0 ;
        for(int k = 1 ; k <= n ;k++)
            for(int i = 1 ; i <= m;i++)
                if(ar[k][i]<=0)c++;
       // out2d(n+1,m+1,1,ar);
        if(!c)cout << "There is no empty spots." << endl;
        else if(c==1)cout << "There is one empty spot." << endl;
        else cout << "There are " << c << " empty spots." << endl;




    }



}
