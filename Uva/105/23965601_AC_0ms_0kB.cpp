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


int homes[100001];

int main(){file();


    int a , b , c , mx=0;
    while(cin >> a >> b >> c&&a){
        for(int i = a+1 ; i <= c ;i++)
            homes[i] = max(homes[i],b);
            mx = max(mx,c);
    }
    homes[1]=homes[2];
    //for(int i = 1 ; i <= mx ;i++)cout << homes[i] << " ";cout << endl;

    int cur = -1;
    for(int i = 1 ; i <= mx ;i++){
        if(homes[i]==cur)continue;
        else {
            cout << max(i-1,1) << " " << homes[i] << " ";
            cur=homes[i];
        }
    }
    cout << mx << " " << 0 << endl;



}
