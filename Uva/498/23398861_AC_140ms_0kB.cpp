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


int main(){file();

    string s ;
    while(getline(cin,s)){
        ll temp ;
        vector < ll > cof , xs;
        stringstream str(s);
        while(str>>temp)cof.push_back(temp);
        getline(cin,s);
        stringstream strr(s);
        while(strr>>temp)xs.push_back(temp);

        for(int i = 0 ; i < szz(xs);i++){
            ll ans = 0 ;
            for(int k = 0 ; k < szz(cof);k++){
                //cout << cof[k] << " " << xs[i] << " " << szz(cof)-k << endl;
                ans += (cof[k]*pow(xs[i],szz(cof)-k-1));
            }
            if(!i)cout << ans ;
            else cout << " " <<  ans ;
        }
        cout << endl;

    }
}









