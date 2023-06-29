#include <iostream>
#include <queue>
using namespace std;

vector < pair<int, int>> Graf[200005];
priority_queue<pair<int, int>> q;
int odl[200005][2];
bool odw[200005][2];



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int a, b, c;

    cin >> n >> m;

    for (int j = 0; j < 2; j++)
        for (int i = 1; i <= n; i++) {
            odl[i][j] = INT32_MAX;
            odw[i][j] = false;
        }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        Graf[a].push_back({ b,c });
        Graf[b].push_back({ a,c });
    }

    odl[1][0] = 0;
    q.push({ 0,1 });

    while (!q.empty()) {
        int w = q.top().second;
        int wOdl = -q.top().first;

        q.pop();

        if (odw[w][wOdl % 2])
            continue;

        odw[w][wOdl % 2] = true;

        for (int i = 0; i < Graf[w].size(); i++) {
            int x = odl[w][wOdl % 2] + Graf[w][i].second;

            if (x < odl[Graf[w][i].first][x % 2]) {
                odl[Graf[w][i].first][x % 2] = x;
                q.push({ -x ,Graf[w][i].first });
            }

        }
    }

    if (odl[n][1] == INT32_MAX)
        cout << 0;
    else
        cout << odl[n][1];

}