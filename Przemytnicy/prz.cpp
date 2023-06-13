#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> Graf[10007];
int Koszt[10007];
int Odl[10007];
bool Odw[10007];

void dijkstra() {
    Odl[1] = 0;

    priority_queue <pair <long long, int> > q;

    q.push(make_pair(0, 1));

    while (q.size()) {
        int w = q.top().second;
        q.pop();
        if (Odw[w]) {
            continue;
        }

        Odw[w] = true;

        for (int i = 0; i < Graf[w].size(); i++) {
            if (Odl[Graf[w][i].first] > Odl[w] + Graf[w][i].second) {
                Odl[Graf[w][i].first] = Odl[w] + Graf[w][i].second;
                q.push(make_pair(-Odl[Graf[w][i].first], Graf[w][i].first));
            }
        }
    }
}

int main() {
    int n, m, KosztPrzejsca;

    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> KosztPrzejsca;
        Graf[i].push_back(make_pair(i + n, KosztPrzejsca/2));
    }

    cin >> m;

    int a, b, c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;       
        Graf[a].push_back(make_pair(b, c));
        Graf[a+n].push_back(make_pair(b+n, c));
    }
        

    for (int i = 1; i < 10007; i++) {
        Odl[i] = INT32_MAX;
    }

    dijkstra();

    cout << Odl[n + 1];

}