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

int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int main(){

    file();
    int n ;
    cin >> n ;
    vector < int > v(n);

    for(int i = 0 ; i < n ;i++){
        cin >> v[i];
    }

    if(n==1&&v[n-1]!=15&&v[n-1]!=0)cout << -1 << endl;
    else if(v[n-1]==15)cout << "DOWN" << endl;
    else if(v[n-1]==0)cout << "UP" << endl;
    else if(v[n-1]>v[n-2])cout << "UP" << endl;
    else cout << "DOWN" << endl;
}
