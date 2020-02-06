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

    double n , a , b , r1 = 0,  p2 = INT_MAX , r2 = 0;
    cout << fixed << setprecision(7);

    cin >> n ;
    while(n--){cin>>a;r1=max(r1,a);};

    cin >> n ;
    vector < int > p1(n);
    for(auto &e : p1)cin >> e ;

    cin >> n ;
    while(n--){cin>>a;p2=min(p2,a);};

    cin >> a >> b ;

    for(auto p11 : p1){
        double temp = sqrt((b*p11*r1*r1*1.0)/(a*p2+b*p11)) ;
        r2 = max(r2,temp);
    }
    cout << r2 << endl;
}
