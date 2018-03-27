#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

using namespace std;
int main()
{fast write

    int t ;
    cin >> t ;
    for(int f = 1 ; f <= t ;f++){
        int sz , n , c = 0 ;
        string s ;

        cin >> sz >> s ;

        for(int i = 0 ; i < sz ;i++){
            if(s[i]=='.'){
                s[i]=s[i+1]=s[i+2]='*';
                c++;
            }
        }

        cout << "Case " << f << ": " << c <<endl;
    }
}
