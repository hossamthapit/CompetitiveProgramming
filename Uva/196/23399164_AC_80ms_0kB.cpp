#include<bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif
#define stop(x) {cout<<x<<endl;exit(0);}
#define TRACE(x) if(DEBUG) cerr << #x << " = " << x << endl;
#define TRACE2(x,y) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << endl;
#define TRACE3(x,y,z) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << " | " << #z << " = " << z << endl;
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;
void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

map < ll , string > Colalias;
map < string , ll > ColIndex;
map < string , ll > myGraph;
void genRows(){
    vector < string > row;
    for(char a = 'A';a<='Z';a++){
        string ans;
        ans += a;
        row.push_back(ans);
    }
    for(char a = 'A';a<='Z';a++){
        string ans;
        ans +=a;
        for(char b = 'A';b<='Z';b++){
            row.push_back(ans+b);
        }
    }
    for(char a = 'A';a<='Z';a++){
        string ans;
        ans += a;
        for(char b = 'A';b<='Z';b++){
            string k = ans + b ;
            for(char c = 'A';c<='Z';c++){
                row.push_back(k+c);
            }
        }
    }
    set < string > st ;
    for(int i = 0 ; i < szz(row);i++){
        st.insert(row[i]);
        Colalias[i]=row[i];
        ColIndex[row[i]]=i;
    }
}

string toString(ll x){
    string ans ;
    while(x>0){
        ans += ((x%10)+'0');
        x/=10;
    }
    reverse(all(ans));
    return ans ;
}
ll toLL(string x){
    stringstream s(x);
    ll e ;
    s >> e;
    return e ;
}

vector < vector < string > > adj;


int n , m ;
ll solve(int i , int j){
    if(i>=n||j>=m)return 0 ;
    if(adj[i][j][0]!='=')return toLL(adj[i][j]);

    string temp;
    ll ans = 0;
    for(int k = 1 ; k < szz(adj[i][j]);k++){
        if(adj[i][j][k]!='+')
            temp += adj[i][j][k];
        if(adj[i][j][k]=='+'||k==szz(adj[i][j])-1){
            string row , col ;
            ll w = 0 ;
            while(isalpha(temp[w]))col+=temp[w++];
            while(w<szz(temp))row+=temp[w++];
            ans += solve(toLL(row)-1,ColIndex[col]);
            temp="";
        }
    }
    adj[i][j] = toString(ans);
    return ans;
}

int main(){file();
    genRows();
    int t ;
    cin >> t;
    while(t--){
        cin >> m >> n ;
        adj = vector < vector < string > > (n,vector < string > (m));

        for(int i = 0 ; i < n ;i++)
            for(int k = 0 ; k < m ;k++)
                cin >> adj[i][k];

        for(int i = 0 ; i < n ;i++){
            for(int k = 0 ; k < m ;k++){
                if(adj[i][k][0]=='=')
                    solve(i,k);
            }
        }

        for(int i = 0 ; i < n ;i++){
            for(int k = 0 ; k < m ;k++){
                if(!k)cout << adj[i][k];
                else cout <<  " " << adj[i][k] ;
            }
            cout << endl;
        }

    }
}









