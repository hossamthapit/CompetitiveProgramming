#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

using namespace std;
int main()
{fast

    string s , t ;
    while(cin >> s >> t ){
        
    int  szs , szt , sz=0;

    szs = s.size();
    szt = t.size();

    for(int i = 0 ; i < szt ;i++){
            if(s[sz]==t[i]){
                if(sz==szs)break;
                sz++;
            }
        }
    (sz==szs ? cout << "Yes\n" : cout << "No\n");
    }
}
