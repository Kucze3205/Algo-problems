#include<bits/stdc++.h>
using namespace std;

int rnd(int a, int b){
    return rand() % (b - a + 1) + a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int seed;
    cin >> seed;
    srand(seed);

    int n = rnd(1, 10);
    cout << n << "\n";


    for (int i = 0; i < n; i++) {
        int k = rnd(1, 10);
        cout << k << " ";
        int sajz = rnd(1, 10);
        string word;
        int dir;

        for (int j = 0; j < sajz; j++) {
            dir = rnd(1, 4);

                if (dir == 1) {
                    word += "N";
                }
                else if (dir == 2) {
                    word += "S";
                }
                else if (dir == 3) {
                    word += "E";
                }
                else if (dir == 4) {
                    word += "W";
                }
        }
        cout << word << "\n";
    }

    return 0;
}
