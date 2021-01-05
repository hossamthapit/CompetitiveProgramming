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

    int t ;cin >> t ;
    while(t--){
        int m , c = 1 ;
        cin >> m ;
        vector < int > parents(m*2+3,0);
        map < int , set < int > > mp ;
        vector < int > total(m*2+3,0);
        map < string , int > Hash;
        while(m--){
            string s , k ;
            cin >> s >> k ;
            if(Hash.find(s)==Hash.end())Hash[s]=c++;
            if(Hash.find(k)==Hash.end())Hash[k]=c++;

            int a = Hash[s] , b = Hash[k];

            if(!parents[a]&&!parents[b]){
                parents[a]= a;
                parents[b]= a;
                mp[a].insert(a);mp[a].insert(b);
                total[a] = szz(mp[a]);
            }
            else if(parents[a]&&parents[b]){
                if(parents[a]!=parents[b]){
                    total[parents[a]] += szz(mp[parents[b]]);
                    for(auto e : mp[parents[b]]){
                        mp[parents[a]].insert(e);
                        parents[e]=parents[a];
                    }
                }
            }
            else if(parents[a]){
                parents[b]= parents[a];
                total[parents[a]]++;
                mp[parents[a]].insert(b);
            }
            else if(parents[b]){
                parents[a]= parents[b];
                total[parents[a]]++;
                mp[parents[b]].insert(a);
            }
            cout << total[parents[a]] << endl;

        }
    }




}

