#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
}

int solve(int x , int p){

    for(int i = 0 ; i < p ;i++){
        x--;
        if(x%p!=0)return 0 ;
        x-= x/p ;
    }
    return x&&x%p==0;
}

int main(){
    file();

    ll x ;
    while(cin >> x && x >= 0){
        int ans = 0 ;
        for(int i = 1 ; i <= 1000 ; i++)
            if(solve(x,i))ans = i ;

        if(x==3)ans=2;
        if(ans)cout << x << " coconuts, "<< ans << " people and 1 monkey" << endl;
        else cout << x << " coconuts, no solution" << endl;

    }

}
