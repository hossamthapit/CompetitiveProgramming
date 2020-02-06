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
    cin >> n ;
    vector < pair < pair < int , int > , int > > v(n);
    for(int i = 0 ; i < n ;i++){
        int a , b ;
        cin >> a >> b ;
        v[i].first.first = a ;
        v[i].first.second = b ;
        v[i].second = i;
    }

    sort(all(v));

    int l = 0 , r = n-1 , sum1 = 0 , sum2 = 0 ;
    vector < char > ans(n);

    while(l<=r){
        if(abs((sum1+v[l].first.first)-sum2)<=500){
            sum1+=v[l].first.first;
            ans[v[l].second]='A';
            l++;
        }
        else {
            sum2+=v[r].first.second;
            ans[v[r].second]='G';
            r--;
        }
    }
    if(abs(sum1-sum2)>500)cout << -1 << endl;
    else for(auto e : ans)cout << e;
}
