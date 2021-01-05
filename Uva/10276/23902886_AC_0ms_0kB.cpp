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


void solve(int idx){

}


int main(){file();

    int t ;
    cin >> t ;
    while(t--){
        int n,a=1;
        cin >> n ;
        vector < int > v(n);
        while(1){
            bool valid = 0;
            for(int i = 0 ; i < n ;i++)
            if(int(sqrt(a+v[i]))*int(sqrt(a+v[i]))==a+v[i]||v[i]==0){
                v[i]=a;valid=1;
                break;
            }
            if(!valid)break;
            a++;
        }
        cout << a-1 << endl;
    }

}
