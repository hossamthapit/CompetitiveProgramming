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


int main(){file();

    int n ;
    while(cin >> n&&n){
        vector < int > v(n);
        for(auto &e :v)cin >> e ;
        int ans = 0 ;

        for(int i = 0 ; i < n ;i++)
        for(int k = i+1 ; k < n ;k++)
            ans += (__gcd(v[i],v[k])==1);

        cout << fixed << setprecision(6);
        if(ans)cout << sqrt(6.0*(n*(n-1)/2)/ans) << endl;
        else cout << "No estimate for this data set." << endl;

    }
}
