#include <bits/stdc++.h>
// *__*
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int ar[2000001];

int main()
{

   int x ;
   while(cin >> x )
   {
   if(x==0)return 0 ;
   
   for(int i = 0 ; i < x ;i++)
       cin >> ar[i];

   sort(ar,ar+x);

   for(int i = 0 ; i < x-1 ;i++)
       cout  << ar[i] << " " ; 
    cout << ar[x-1]<<endl;

   }

}
