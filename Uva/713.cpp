#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;

void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

string sum(string &s , string &k){
    string ret ;
    int i = 0 , hold = 0 ;
    if(szz(s)>szz(k))swap(s,k);

    for( ; i < szz(s);i++){
        hold += (s[i]-'0');
        hold += (k[i]-'0');
        ret += ((hold%10)+'0');
        hold/=10;
    }
    while(i<szz(k)){
        hold += (k[i]-'0');
        ret += ((hold%10)+'0');
        hold/=10;
        i++;
    }
    if(hold)ret += (hold+'0');
    while(szz(ret)>1&&ret[0]=='0')ret.erase(ret.begin());
    return ret;
}

int main(){file();

    int n ;
    cin >> n ;
    while(n--){
        int i = 0;
        string s , k ;
        cin >> s >> k ;
        cout << sum(k,s) << endl;

    }
}
