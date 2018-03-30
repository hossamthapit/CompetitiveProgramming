#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

using namespace std ;

int main()
{ fast

    int w , h , q ;

    while(cin >> w >> h >> q){

    if( !w && !h && !q )break;

    int x , y , x1 , y1 , c = 0 ;

    vector < vector < int > > v ( h + 2 , vector < int > ( w + 2 , 0 ));


    while(q--){
        cin >> x >> y >> x1 >> y1 ;

        v[ min( y , y1 ) ][ min ( x , x1 ) ] += 1;
        v[ max( y , y1 ) + 1 ][ max ( x , x1 ) + 1 ] += 1;
        v[ min( y , y1 ) ][ max ( x , x1 ) + 1 ] -= 1;
        v[ max( y , y1 ) + 1 ][ min ( x , x1 ) ] -= 1;
    }
    for( int i = 1 ; i <= h ; i++ )
        for( int k = 1 ; k <= w ; k++ )
            v[i][k] += v[i][k-1] ;

    for( int k = 1 ; k <= w ; k++ )
        for( int i = 1 ; i <= h ; i++ )
            v[i][k] += v[i-1][k];

    for( int i = 1 ; i <= h ; i++ )
        for( int k = 1 ; k <= w ; k++ )
            if( !v[i][k] ) c++ ;

    if(c==0)cout<< "There is no empty spots." <<endl;
    else if(c==1)cout<< "There is one empty spot." <<endl;
    else cout<< "There are "<< c << " empty spots." <<endl;

    }
}
