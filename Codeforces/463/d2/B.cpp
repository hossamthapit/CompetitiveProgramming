#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define all(x) x.begin(),x.end()
#define szz(s) ll(s.size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define endl '\n'

void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}


int main(){

    file();
    ll n , c = 0  ;
    cin >> n ;
    vector < int > v(n+1);
    for(int i = 0 ; i < n ;i++)
        cin >> v[i];
    v[n]=v[n-1];

    c = v[0];
    for(int i = 0 ; i < n ;i++){
        if(c<v[i])
            c+= (v[i]-c);
    }
    cout << c << endl;








}
