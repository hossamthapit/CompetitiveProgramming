#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{fast
    
    int x ;
    while(cin >> x){
    if(x==0)return 0 ;
    int  s = 0 , a , m;
    multiset < int > st ;
    multiset < int > :: iterator it , it1 , w ,e;


    for(int i = 0 ; i < x ;i++){
        cin >> a ;
        st.insert(a);
    }
    it = st.begin();
    it1= st.begin();
    it1++;

    for(;st.size()>1;){
        it = it1 = st.begin();
        it1++;
        m = *it + *it1 ;
        s += m ;
        st.erase(it);
        st.erase(it1);
        st.insert(m);

    }
    cout << s <<endl;
    }
}
