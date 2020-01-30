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

bool solve(int x , set < int > &st , set < int > &tr){

    for(auto e : tr){
        bool valid=1;
        for(auto r : st)
            if(!(r+e==x||r-e==x||r==x))valid=0;
        if(valid)return 1;
    }
    return 0;
}

int main(){file();

    int n ;
    cin >> n ;
    set < int > st ;
    for(int i = 0 ; i < n ;i++){
        int a ;cin >> a ;
        st.insert(a);
    }
    if(szz(st)<4){
        set < int > trys = st;
        for(auto e : st)
            for(auto r : st)
                trys.insert(abs(e-r));
        for(auto e : trys)
            if(solve(e,st,trys))return cout << "YES" , 0 ;
    }
    cout << "NO" << endl;
}
