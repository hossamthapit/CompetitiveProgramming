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

bool isPrime(ll x){
    if(x%2==0&&x!=2)return 0 ;
    for(ll i = 2 ; i*i <= x ;i++)
        if(x%i==0)return 0;
    return 1;
}

int main(){file();

    int n , m , MSTCost , invalidCost , edges ;
    cin >> n >> m ;
    for(int i = max(n-1,2) ; ;i++)
        if(isPrime(i)){
            MSTCost = i;
            break;
        }

    edges = n-1 ;

    cout << MSTCost << " " << MSTCost << endl;

    for(int i = 0 ; i < n-1 ; i++){
        if(!i)cout << i+1 << " " << i+2 << " " << MSTCost-(n-2)<< endl;
        else cout << i+1 << " " << i+2 << " " << 1 << endl;
    }

    for(int i = MSTCost+1; ;i++)
        if(isPrime(i)){
            invalidCost = i;
            break;
        }

    for(int i = 0 ; i < n ;i++){
        for(int j = i+2 ; j < n ;j++){
            if(edges==m)return 0 ;
            cout << i+1 << " " << j+1 << " " << invalidCost << endl;
            edges++;
        }
    }
}
