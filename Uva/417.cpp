#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()
using namespace std ;

int main()
{
    map < string , int > mp ;
    int c = 0 ;
    string s ;

    for(char i =  'a' ; i <= 'z' ;i++){
        s = i ;
        c++;
        mp[s]=c;

    }
    for(char i =  'a' ; i <= 'z' ;i++){
        for(char j =  i+1 ; j <= 'z' ;j++){
        s = i; s += j ;
        c++;
        mp[s]=c;
        }
    }
    for(char i =  'a' ; i <= 'z' ;i++){
        for(char j =  i+1 ; j <= 'z' ;j++){
          for(char k =  j+1 ; k <= 'z' ;k++){
            s = i; s += j; s += k ;
            c++;
            mp[s]=c;
            }
        }
    }
    for(char i =  'a' ; i <= 'z' ;i++){
        for(char j =  i+1 ; j <= 'z' ;j++){
          for(char k =  j+1 ; k <= 'z' ;k++){
            for(char l =  k+1 ; l <= 'z' ;l++){
                s = i; s += j; s += k ; s += l ;
                c++;
                mp[s]=c;
                }
            }
        }
    }
    for(char i =  'a' ; i <= 'z' ;i++){
        for(char j =  i+1 ; j <= 'z' ;j++){
          for(char k =  j+1 ; k <= 'z' ;k++){
            for(char l =  k+1 ; l <= 'z' ;l++){
                for(char m =  l+1 ; m <= 'z' ;m++){
                    s = i; s += j; s += k ; s += l ; s += m ;
                    c++;
                    mp[s]=c;
                    }
                }
            }
        }
    }
    string k ;
    while(cin >> k)
    cout << mp[k] <<endl;
}
