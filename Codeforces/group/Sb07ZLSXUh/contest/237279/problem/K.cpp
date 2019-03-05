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
    freopen("input.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
}


int main(){
    file();

    ll n , mx = 0, a  , mn  , c = 0 , cc = 0 ;
    bitset < 50 > bts ;
    vector < int > mxy(50,0),my(50,0);
    cin >> n ;mn=n;
    vector < int > v(n);
    for(int i = 0 ; i < n ;i++){
        cin >> v[i] ;
        bts = v[i];
        for(int k = 0 ; k < 44 ;k++)
            mxy[k]+=bts[k];
    }
    ll l = 0 , r = 0 ;

    while(1){
        bool valid = 1 ;

        for(int i = 0; i <= 44 ;i++)
            if(mxy[i]&&!my[i]){valid=0;break;}

        if(valid){
            mn = min(mn,r-l);
            if(l==n||l==r)break;
            bts = v[l];
            for(int i = 0 ; i < 44;i++)
                my[i]-=bts[i];
            l++;
        }
        else {
            if(r==n)break;
            bts = v[r];
            for(int i = 0 ; i < 44;i++)
                my[i]+=bts[i];
            r++;
        }

    }
    cout << max(mn,1LL) << endl;



}
