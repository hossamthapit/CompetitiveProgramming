#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{fast
    string s ;
    set <string> st ;
    while(cin >> s ){

        string x ;
        int sz = s.size();

        for(int i = 0 ; i < sz;i++)
        {
            s[i]=tolower(s[i]);
            if(s[i]>='a'&&s[i]<='z')x+=s[i];
            else if(i!=0&&i!=sz-1){st.insert(x);x="";}
        }

        st.insert(x);
    }
    set<string>::iterator t ;

    for(t=st.begin();t!=st.end();t++){
        cout << *t << endl;
    }

}
