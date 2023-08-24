#include <iostream>                                                             
#include <set>
#include <queue>
using namespace std;

int B[300007];
int bitek[300007];
bool res[300007];
bool k[300007];

queue<int> active[300005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, Ka;

    cin >> n >> m >> Ka;

    for (int i = 0; i < n; i++)
        cin >> B[i];
    for (int i = 1; i < m + 1; i++)
        cin >> bitek[i];

    int j = 1;
    for (int i = 0; i < n; i++) {
        if (bitek[j] == B[i]) {
            res[i] = true;
            active[B[i]].push(i);

            j++;
        }
        else if (bitek[j - 1] == B[i]) {
            res[i] = true;
            active[B[i]].push(i);
        }

        if (j > m) j = n + 1; // (j = nieskoñczonoosc)

    }
    if (j < m) { // return 0;
        for (int i = 0; i < n; i++)
            cout << 0 << " ";
    }

    j = m;

    for (int i = n - 1; i >= 0; i--) {

        if (res[i] == true) { //1 layer
            if (!active[B[i]].empty())  active[B[i]].pop();
            k[B[i]] = false;

            if (bitek[j] == B[i]) {
                j--;
                if (j < 1) j = -1;
            }
        }
        else {
            if (bitek[j] == B[i]) { //2 layer
                j--;
                if (j < 1) j = -1;
                k[B[i]] = true;
                res[i] = true;
            }
            else {
                if (k[B[i]] == true) //3 layer
                    res[i] = true;
            }
        }

        if (active[B[i]].empty())
            k[B[j]] = false;

    }

    for (int i = 0; i < n; i++)
        cout << res[i] << " ";



    return 0;
}