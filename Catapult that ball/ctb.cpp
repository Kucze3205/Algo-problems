#include <iostream>
using namespace std;

int tree[1 << 18];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = n + 1; i < 2 * n + 1; i++) {
        cin >> tree[i];
    }

    for (int i = 2 * n; i > 0; i -= 2) {
        tree[i / 2] = max(tree[i], tree[i + 1]);
    }

    int result = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b;


        a = a + n - 1;
        c = a + 1;
        b = b + n;

        int maximum = -1;

        while (a != b - 1) {
            if (a % 2 == 0)
                maximum = max(maximum, tree[a + 1]);
            if (b % 2 == 1)
                maximum = max(maximum, tree[b - 1]);

            a = a / 2;
            b = b / 2;
        }

        if (maximum <= tree[c])
            result++;
    }
    cout << result;

}