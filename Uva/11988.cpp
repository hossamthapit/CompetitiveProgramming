#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define all(x) x.begin(),x.end()
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
using namespace std;

int main()
{fast

    string ss , ans , s , t;
    int open = 0 , close = 0 ;

    while(cin >> s)
    {
        close = open = 0 ;
        ss = ans = t = "";

        for(int i = 0 ; i < s.size();i++){

            if(s[i]==']'&&open>0){
                t = ss + t ;
                open=0;
                ss = "";
            }
            else if(s[i]=='['&&open>0){
                t = ss + t ;
                open++;
                ss="";
            }
            else if(open>0&&i==s.size()-1&&s[i]!='['&&s[i]!=']'){
                ss+=s[i];
                t = ss + t ;
            }
            else if(s[i]=='['){
                open++;
            }
            else if(open>0&&s[i]!=']'&&s[i]!='[')ss+=s[i];
            else if(open==0&&s[i]&&s[i]!='['&&s[i]!=']')ans+=s[i];
        }
    cout << t << ans <<endl;
    }

}
