#include <iostream>
#include <set>
#include <queue>
using namespace std;

int Samochodziki[100000];
int OdlPom[100000];
int OdlSam[100000];
bool podloga[100000];
priority_queue< pair<int, int>> Q;
int niewiadome;

int result = 0;
int podlogaSize = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, p;
    cin >> n >> k >> p;

    for (int i = 0; i < p; i++)
        cin >> Samochodziki[i];

    for (int i = 1; i <= n; i++)
        OdlPom[i] = 1e9;

    for (int i = p - 1; i >= 0; i--) {
        OdlSam[i] = OdlPom[Samochodziki[i]];
        OdlPom[Samochodziki[i]] = i;
    }

    for (int i = 0; i < p; i++) {
        int c = Samochodziki[i];
        if (!podloga[c]) {
            result++;
            podloga[c] = true;
            podlogaSize++;
        }
        if (podlogaSize > k) {
            pair<int, int> x = Q.top();
            int C = x.second;
            Q.pop();
            podloga[C] = false;
            podlogaSize--;
        }
        Q.emplace(OdlSam[i], c);
    }

    cout << result << "\n";

    return 0;
}