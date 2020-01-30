#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int dxx[] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int dyy[] = { 1, -1, 1, -1, 2, 2, -2, -2 };
typedef long long ll;
using namespace std;

void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}



int main(){file();

    int n , ans = 0 ;
    stack < int > stk;

    cin >> n;
    while(n--){
        int a;cin >>a >> a ;
        if(!szz(stk)){
            stk.push(a);
            ans++;
            continue;
        }
        while(szz(stk)&&stk.top()>a){
            stk.pop();
        }
        if(!szz(stk)||stk.top()!=a){
            ans++;
            stk.push(a);
        }
    }
    cout << ans << endl;

}
