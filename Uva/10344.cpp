#include <bits/stdc++.h>
#define write ofstream file_out ; file_out.open("output.txt");
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read ifstream file_in ; file_in.open("input.txt");
typedef long long ll;typedef unsigned long long ull;
#define rer(i,n) for(int i = 0 ; i < n ;i++)
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
#define out(x) cout << x << endl
#define all(x) x.begin(),x.end()
#define szz(x) ll(x.size())
#define stop exit(0);
#define pb push_back
using namespace std;
#define endl '\n'
#define s second
#define f first
/*************/

set < string > st ;

bool valid(int a , int b , int c , int d , int e){
    for(auto it : st){
        ll z = 0 ;
        string s = it ;
        if(s[0]=='+')z = a+b;
        else if(s[0]=='-')z = a-b;
        else z = a*b;
        if(s[1]=='+')z +=c;
        else if(s[1]=='-')z -=c;
        else z *=c;
        if(s[2]=='+')z +=d;
        else if(s[2]=='-')z -=d;
        else z *=d;
        if(s[3]=='+')z +=e;
        else if(s[3]=='-')z -=e;
        else z *=e;
        if(z==23){ /*printf("%d %c %d %c %d %c %d %c %d\n",a,s[0],b,s[1],c,s[2],d,s[3],e);*/return true ;}
    }
    return false ;
}


int main(){fast write read

    string s ;
    char sign[12]={'+','+','+','+','-','-','-','-','*','*','*','*'};
    sort(sign,sign+12);

    do{
        s = "";s = s+sign[0];s = s+sign[1];s = s+sign[2];s = s+sign[3];st.insert(s);
    }
    while(next_permutation(sign,sign+12));
    //////////////Start Here///////////////
    int ar[5];
    while(cin>>ar[0]>>ar[1]>>ar[2]>>ar[3]>>ar[4]){
        bool flag = 0 ;
        sort(ar,ar+5);
        if(ar[4]==0)break;

        do{
            if(valid(ar[0],ar[1],ar[2],ar[3],ar[4])){flag = 1 ; break;}
        }
        while(next_permutation(ar,ar+5));

        if(flag)out("Possible");
        else out("Impossible");
    }
}
