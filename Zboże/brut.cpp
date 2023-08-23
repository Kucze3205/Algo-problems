#include <iostream>                                                             
#include <queue>                                                                                                                             
using namespace std;

#define MAX 100007

vector<pair<int, int>> Graf[MAX];
int Ilosc_zboza[MAX];
int Zboze_z_zamkow[MAX];
int n, k;
vector<int> Listakrolestw;

int wynik[MAX];

void dfs(int v, int ojciec) {

    for (auto w : Graf[v]) {
        if (w.first == ojciec)
            continue;
        Ilosc_zboza[w.first] = w.second + Ilosc_zboza[v];
        dfs(w.first, v);

    }

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int a, b, c;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        Graf[a].push_back({ b,c });
        Graf[b].push_back({ a,c });
    }
    Listakrolestw.push_back(1);
    wynik[0] = 0;

    for (int i = 1; i <= k; i++) {
        int ki;
        cin >> ki;

        for (int i = 1; i <= n; i++)
            Ilosc_zboza[i] = 0;

        dfs(ki, 0);

        wynik[i] = wynik[i - 1];

        for (int j = 0; j < Listakrolestw.size(); j++) {
            wynik[i] += Ilosc_zboza[Listakrolestw[j]] * 2;
        }

        Listakrolestw.push_back(ki);
    }


    for (int i = 1; i <= k; i++) {
        cout << wynik[i] << '\n';
    }

    return 0;
}