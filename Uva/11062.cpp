#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{fast
    string s, temp , x;
    set <string> st ;

    while(cin >> s ){

       int  sz = s.size();
        if(s[sz-1]=='-'){
            temp+=s;
            continue;
        }
        s =temp+s ;
        sz = s.size();

        if(temp == ""){
            for(int i = 0 ; i < sz;i++){
                s[i]=tolower(s[i]);
                if((s[i]>='a'&&s[i]<='z')||s[i]=='-')x+=s[i];
                else if(i!=0&&i!=sz-1){st.insert(x);x="";}
            }
        }
        
        else{
            for(int i = 0 ; i < sz;i++){
                s[i]=tolower(s[i]);
                 if((s[i]>='a'&&s[i]<='z')||s[i]=='-'){
                        if(s[i]!='-')x+=s[i];
                }
                else if(i!=0&&i!=sz-1){st.insert(x);x="";}
            }
        }
        st.insert(x);
        temp =  x = "";

    }
    set<string>::iterator t ;

    for(t=st.begin();t!=st.end();t++)
        if(*t!="")cout << *t << endl;
}
