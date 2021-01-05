#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
#define all(x) x.begin(),x.end()
#define szz(x) int(x.size())
typedef long long ll;
using namespace std;

void file() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}

int main() {
    file();

    map < int, char > mp;
    for (int i = 0; i <= 9; i++)
        mp[i] = (i+'0');
    mp[10] = 'A'; mp[11] = 'B'; mp[12] = 'C'; mp[13] = 'D'; mp[14] = 'E';
    mp[15] = 'F';


    string s;
    ll g = 34943;
    
    while (getline(cin, s) && s != "#") {
        ll sum = 0;
        for (auto e : s)
            sum = ((sum << 8) + e)%g;

        sum = (sum << 16) % g;
        ll crc  = (g - sum) % g;

        bitset < 16 > bts = crc;
        printf("%02X ", crc >> 8);
        printf("%02X\n", crc % (1 << 8));

    }
    /// 30717    34943
    
}