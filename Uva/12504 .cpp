#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{fast

    int x ;
    cin >> x ;
    while(x--)
    {

        set < string > removed , added , changed;
        map < string , string > mp , mp1;
        map < string , string > :: iterator it , it1;

        string s , s1 , a , b , g1 , g2 , g3;
        cin >> s >> s1 ;

        int sz = s.size() ,  sz1 = s1.size() , e = 0 ;
        // divided the key & the value in two maps
        for(int i = 1 ; i < sz ;i++)
        {
            if(((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))&&e==0)a+=s[i];
            else if(((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))&&e==1)b+=s[i];
            else if(s[i]==':')e=1;
            else if(s[i]==','||s[i]=='}'){mp[a]=b;e=0;a=b="";}
        }
        a = b = "";
        for(int i = 1 ; i < sz1 ;i++)
        {
            if(((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='0'&&s1[i]<='9'))&&e==0)a+=s1[i];
            else if(((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='0'&&s1[i]<='9'))&&e==1)b+=s1[i];
            else if(s1[i]==':')e=1;
            else if(s1[i]==','||s1[i]=='}'){mp1[a]=b;e=0;a=b="";}
        }
        // check if the number in the map1 in map2 also or no & the value of the keys 
        it = mp.begin();
        it1 = mp1.begin();

        string first ,second , second1 , first1;

        for(;it!=mp.end();it++){
            first = it->first , second = it->second ;

            if(mp1.count(first)!=0&&mp1[first]!=second)changed.insert(first);
            if(mp1.count(first)==0)removed.insert(first);
        }

        for(;it1!=mp1.end();it1++){
            first = it1->first ;
            if(mp.count(first)==0)added.insert(first);
        }

        // start process the output
        if(!added.size()&&!changed.size()&&!removed.size()){cout << "No changes\n";}
        else {
            int szv = added.size() , szv1 = removed.size() , szv2 = changed.size();
            szv--,szv1--,szv2--;

            set < string > :: iterator v=added.begin() ;
            if(v!=added.end()){g1+="+";
                for(;v!=added.end();v++){
                    g1+= *v;
                    if(szv--)g1+=",";
            }
            }
            set < string > :: iterator v1=removed.begin() ;
            if(v1!=removed.end()){g2+="-";
                for(;v1!=removed.end();v1++){
                    g2+= *v1;
                    if(szv1--)g2+= ",";
                }
            }
            set < string > :: iterator v2=changed.begin() ;
            if(v2!=changed.end()){g3+="*";
                for(;v2!=changed.end();v2++){
                    g3+= *v2;
                    if(szv2--)g3+=",";
                }
            }

        }
        // the output
        if(g1>"+")cout << g1 << endl;
        if(g2>"-")cout << g2 << endl;
        if(g3>"*")cout << g3 << endl;
        cout << endl;
    }
        return 0 ;
}
