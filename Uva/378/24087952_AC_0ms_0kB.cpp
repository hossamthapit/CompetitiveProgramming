#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;

void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

double eps = 1e-8;

int main(){file();

    int t ;
    cin >> t ;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    cout << fixed << setprecision(2);
    while(t--){
        double x , y , x1, y1 , x2 , y2 , x3 , y3 ;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;

        int a1, b1, c1, a2, b2, c2;
        int D, Dx, Dy;
        a1 = y-y1, b1 = -x+x1;
        a2 = y2-y3, b2 = -x2+x3;
        c1 = a1*x + b1*y;
        c2 = a2*x2 + b2*y2;
        D = a1*b2-a2*b1;
        Dx = c1*b2 - c2*b1;
        Dy = a1*c2 - a2*c1;
        if(!D&&(Dx||Dy))cout << "NONE" << endl;
        else if(!D && !Dx && !Dy)cout << "LINE" << endl;
        else cout << "POINT " << Dx*1./D << " " << Dy*1./D << endl;
    }
    cout << "END OF OUTPUT" << endl;
}

/*
5
0 0 4 4 0 4 4 0
5 0 7 6 1 0 2 3
5 0 7 6 3 -6 4 -3
2 0 2 27 1 5 18 5
0 3 4 0 1 2 2 5
*/
