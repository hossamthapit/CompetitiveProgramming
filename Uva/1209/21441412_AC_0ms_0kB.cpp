#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;

void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int dif(string s){
    int c = -1 , mx = INT_MAX;
    for(int i = 1 ; i < szz(s);i++){
        c= abs(s[i]-s[i-1]);
        mx = min(mx,c);
    }
    return mx;
}

int main()
{
    file();

    string s ;
    while(cin >> s){
        int mx = -1 ;
        string lst , ans , temp1 , temp2 ;
        deque < string > gen1 , gen2 ;
        vector < string > res;


        temp1 = s , temp2 = s ;
        int k = 11 ;

        do{
            gen1.push_back(temp1);
            k--;
            if(!k)break;
        }

        while(next_permutation(all(temp1)));
        gen1.pop_front();

        k = 11 ;

        do{
            gen2.push_back(temp2);
            k--;
            if(!k)break;
        }
        while(prev_permutation(all(temp2)));
        gen2.pop_front();

        gen1.push_front(s);
        for(auto p : gen2)
            gen1.push_front(p);


        for(auto p : gen1){
            if(dif(p)>mx){
                mx = dif(p);
                ans = p;
            }
        }
        if(mx==-1)cout << s << 0 << endl;
        else cout << ans << mx << endl;
    }

}
