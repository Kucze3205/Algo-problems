#include <iostream>
#include <vector>

using namespace std;
vector<int> Graf[200007];
bool odwiedzone[200007];
bool isK[200007];


void dfs(int w) {

    odwiedzone[w] = true;

    for (int i = 0; i < Graf[w].size(); i++) {
        if (odwiedzone[Graf[w][i]] == false) {
            if (isK[w] == false)
                isK[Graf[w][i]] = true;

            dfs(Graf[w][i]);

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int a, b;

    cin >> n >> m;

    // wczytywanie 
    for (int i = 0; i < m; i++) {

        cin >> a >> b;

        Graf[a].push_back(b);
        Graf[b].push_back(a);
    }

    //rozwiazanie
    for (int i = 1; i <= n; i++) {
        if (Graf[i].empty()) {
            cout << "NIE\n";
            return 0;
        }

        if (odwiedzone[i] == false)
            dfs(i);
    }

    cout << "TAK\n";

    for (int i = 1; i <= n; i++) {

        if (isK[i])
            cout << "S\n";
        else
            cout << "K\n";
    }

}
