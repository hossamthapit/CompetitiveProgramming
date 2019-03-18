#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define all(x) x.begin(),x.end()
#define szz(s) ll(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
}

char ar[13][13];
int main(){
    file();

    int n , m , t , c = 1;
    cin >> t ;
    while(t--){
        cin >> n ;
        m=n;

        for(int i = 0 ; i <= n+1 ; i++)
            for(int k = 0 ; k <= m+1 ;k++)
                ar[i][k]='#';
        for(int i = 1 ; i <= n ; i++)
            for(int k = 1 ; k <= m ;k++)
                cin >> ar[i][k];

        for(int i = 1 ; i <= n ;i++){
            for(int k = 1 ; k <= m ;k++){
                if(ar[i][k]=='.'){
                    map < char , bool > mp ;
                    for(int di = 0 ; di < 4 ;di++)
                        mp[ar[dx[di]+i][dy[di]+k]]=1;

                    for(char a = 'A' ; a<='Z';a++)
                        if(!mp[a]){ar[i][k]=a;break;}
                }
            }
        }
        cout << "Case " << c++ << ":" << endl;
        for(int i = 1 ; i <= n ; i++){
            for(int k = 1 ; k <= m ;k++)
                cout << ar[i][k];
            cout << endl;
        }
    }
}
