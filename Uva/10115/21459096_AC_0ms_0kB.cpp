#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("out.txt", "w", stdout);
    #endif
}

string word;
vector < pair < string  , string > > steps;

bool DoStep(pair < string , string > p){
    string tempWord = word;
    string temp;
    for(int i = 0 ; i < szz(p.first);i++)
        temp += word[i];
    int sz = szz(temp);
  //  cout << p.first << "|" << p.second << "|" << word << "|" << temp << endl;
    for(int i = sz ; i <= szz(word);i++){
    //    cout << temp << endl;
        if(temp==p.first){
            string pp ;
            for(int k = 0 ; k < i-sz ; k++)
                pp+=word[k];
            pp+=p.second;
            for(int k = i ; k < szz(word); k++)
                pp+=word[k];

            word = pp;
         //   cout << word << endl;
            return 1;
        }
        if(i==szz(word))break;
        if(szz(temp))temp.erase(temp.begin());
        temp+=word[i];
    }

    return 0;
}

int main(){file();


    int t ;
    while(cin >> t){
        if(!t)break;
        steps = vector < pair < string , string > >(t);
        cin.ignore();
        for(int i = 0 ; i < t ;i++){
            getline(cin,steps[i].first);
            getline(cin,steps[i].second);
        }
        getline(cin,word);

        for(int i = 0 ; i < t ;i++){
            while(DoStep(steps[i]));
        }
        cout << word << endl;
    }








}