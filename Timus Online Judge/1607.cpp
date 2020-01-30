#include<iostream>
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

int main(){//file();

    int a , b , c , d ;
    cin >> a >> b >> c >> d ;

    if(a>=c)return cout << a <<endl,0;

    while(a<c){
        if(a+b<c)a+=b;
        else return cout << c <<endl,0;
        if(a<c-d)c-=d;
        else return cout << a <<endl,0;
    }
}
