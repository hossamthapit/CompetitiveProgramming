#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;

void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int ar[100][100];

int main()
{
    file();
    int t ;
    cin >> t ;
    while(t--){
        ll n , m , valid = 1 ;
        cin >> n >> m ;
        map < pair < int , int > , int > mp ;
        for(int i = 0 ; i < n ;i++)
            for(int k = 0 ; k < m ; k++)
                cin >> ar[i][k];

        for(int i = 0 ; i < m ;i++){
            int a = -1 , b = -1 , c = 0;
            for(int k = 0 ; k < n ; k++){
                if(ar[k][i]==1){
                    if(a==-1)a=k;
                    else if(b==-1)b=k;
                    c++;
                }
            }
            if(c!=2)valid=0;
            else {
                if(mp[{a,b}])valid=0;
                mp[{a,b}]=1;
                mp[{b,a}]=1;
            }
        }
        if(valid)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
