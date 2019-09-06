#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
using namespace std;
#define endl '\n'
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
}

int ar[] = {0,1,2,3,4,5,4,3,2,1};

int fixMod(int x){
    return ((x%10)+10)%10;
}

int unlock(int x){
    int sum = 0 ;
    while(x){
        sum += ar[x%10];
        x/=10;
    }
    return sum;
}
int match(int x , int y){
    int sum = 0 ;
    while(x||y){
        ll k = abs((x%10)-(y%10));
        if(k>5)k = 10-k;
        sum+=k;
        y/=10;x/=10;
    }
    return sum;
}

int main(){file();

    int t ,  n , x;
    cin >> t ;
    while(t--){
        int mn = 50 , idx , ans = 0 ;
        cin >> n ;
        set < int > unlocked;
        vector < int > v(n);
        multiset < int > locked;

        for(int i = 0 ; i < n ;i++){
            cin >> v[i] ;
            locked.insert(i);
            if(match(v[i],0)<mn){
                mn = unlock(v[i]);
                idx = i;
            }
        }
        ans = mn ;
        locked.erase(idx);
        unlocked.insert(idx);

        while(szz(locked)){
            mn = 50 ;
            for(auto lock : locked)
                for(auto e : unlocked){
                    if(match(v[e],v[lock])<mn){idx = lock;mn=match(v[e],v[lock]);}
                }
            locked.erase(idx);
            unlocked.insert(idx);
            ans += mn;
        }
        cout << ans << endl;
    }
}
