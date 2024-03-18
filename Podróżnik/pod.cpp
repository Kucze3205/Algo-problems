#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int k;
    long long minx = 0, maxx = 0;
    long long miny = 0, maxy = 0;
    long long dx = 0, dy = 0; // -1 0
    long long x = 0, y = 0; // -22 0
    long long oldx = 0, oldy = 0; // -19 0

    for (int i = 0; i < n; i++) {
        cin >> k;
        string dir;
        cin >> dir;
        oldx = x;
        oldy = y;
        for (int j = 0; j < dir.size(); j++) {

                if (dir[j] == 'N') {
                    y++;
                    if (maxy < y) maxy = y; //0
                }
                else if (dir[j] == 'S') {
                    y--;
                    if (miny > y) miny = y; //-23
                }
                else if (dir[j] == 'E') {
                    x++;
                    if (maxx < x) maxx = x; //0
                }
                else if (dir[j] == 'W') {
                    x--;
                    if (minx > x) minx = x; //0
                }
        }

        dx = x - oldx;
        dy = y - oldy;
        if(k > 1){
            x += dx * (k - 2);
            y += dy * (k - 2);

            for (int j = 0; j < dir.size(); j++) {

                if (dir[j] == 'N') {
                    y++;
                    if (maxy < y) maxy = y; //1
                }
                else if (dir[j] == 'S') {
                    y--;
                    if (miny > y) miny = y; //-23
                }
                else if (dir[j] == 'E') {
                    x++;
                    if (maxx < x) maxx = x; //0
                }
                else if (dir[j] == 'W') {
                    x--;
                    if (minx > x) minx = x; //-3
                }
            }
        }

        if (maxy < y) maxy = y;
        else if (miny > y) miny = y;
        if (maxx < x) maxx = x;
        else if (minx > x) minx = x;
    }
    cout << maxy - miny << " " << maxx - minx;

    return 0;
}
