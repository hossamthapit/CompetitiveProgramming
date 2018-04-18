#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file_out ; file_out.open("output.txt");
#define read  ifstream file_in ; file_in.open("input.txt");
#define all(x) x.begin(),x.end()
#define ll_str(x,y) stringstream sdf;sdf<<x;string str=sdf.str();y=str;
#define str_ll(x,y) stringstream sstr(x);ll val;sstr>>val;y=val;
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
using namespace std;
int a[2000002];
int tmp[2000002];

ll c = 0 ;
int merge(int l1, int r1, int l2, int r2) {
	for (int i = l1; i <= r2; i++)
    tmp[i] = a[i];
    ll h = l2 ;
	int idx = l1;
	while (l1 <= r1 && l2 <= r2) {
		if (tmp[l1] <= tmp[l2]) {
			a[idx++] = tmp[l1];
			l1++;
		}
		else {
			a[idx++] = tmp[l2];
			l2++;
	//		cout << h-l1 <<endl;
            c +=(h-l1);
		}
	}
	while (l1 <= r1){
		a[idx++] = tmp[l1++];
	}
	while (l2 <= r2){
		a[idx++] = tmp[l2++];
	}
	return c;
}
int merge_sort(int l, int r) {
 	if (l == r) return c;
	int mid = (l + r) / 2;
    merge_sort(l, mid);
	merge_sort(mid + 1, r);
	merge(l, mid, mid + 1, r);

}
int main() {
    fast write read
        int t , n ;
        cin >> t ;
        while(t--){
            cin >> n ;

            for (int i = 0; i < n; i++)
                cin >> a[i];

            merge_sort(0, n - 1);
            cout << c << endl;
            c = 0 ;
        }
}

