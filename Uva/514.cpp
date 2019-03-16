#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define all(x) x.begin(),x.end()
#define szz(s) ll(s.size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define endl '\n'

void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
}

int main(){
    file();
    int n , p = 0 ;
    here:
    while(cin >> n ){
        if(p&&!n)return 0 ;
        while(1){
            deque < int > dq(n);
            for(int i = 0 ; i < n ;i++){
                cin >> dq[i];
                if(dq[i]==0){p=1;cout << endl;goto here;}
            }
            p=0;

            stack < int > stk ;
            int k = n , yes = 1 ;

            while(1){
                bool e = 0 ;
                while(szz(dq)&&dq.back()==k){
                    dq.pop_back();
                    k--;
                    e=1;
                }
                while(szz(stk)&&stk.top()==k){
                    stk.pop();
                    k--;
                    e=1;
                }
                while(szz(dq)&&dq.back()!=k){
                    stk.push(dq.back());
                    e=1;
                    dq.pop_back();
                }
                if(!e)break;
            }

            if(!k)cout << "Yes" << endl;
            else cout << "No" << endl;

        }
    }


}
