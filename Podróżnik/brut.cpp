#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int k;
    int minx = 0, maxx = 0;
    int miny = 0, maxy = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        cin >> k;
        string dir;
        cin >> dir;
        for (int a = 0; a < k; a++) {
            for (int j = 0; j < dir.size(); j++) {

                if (dir[j] == 'N') {
                    y++;
                    if (maxy < y) maxy = y;
                }
                else if (dir[j] == 'S') {
                    y--;
                    if (miny > y) miny = y;
                }
                else if (dir[j] == 'E') {
                    x++;
                    if (maxx < x) maxx = x;
                }
                else if (dir[j] == 'W') {
                    x--;
                    if (minx > x) minx = x;
                }
            }
        }

    }
    cout << maxy - miny << " " << maxx - minx;

    return 0;

}
