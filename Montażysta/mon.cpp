#include <iostream>
#include <queue>

using namespace std;

priority_queue< pair<long, long>> seq;
pair<long, long> res[500002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    seq.push({ -LONG_MAX,-LONG_MAX });

    int n, m = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        seq.emplace(-b, a);
    }

    pair<int, int> miejsce = { 0,-seq.top().first };

    for (int i = 1; i <= n; i++) {

        if (seq.top().second <= miejsce.second) {
            res[m] = { i, miejsce.first };
            m++;
            miejsce.first += seq.top().second;
            miejsce.second -= seq.top().second;
        }

        seq.pop();
        miejsce.second = -seq.top().first - miejsce.first;
    }

    cout << m << "\n";
    for (int i = 0; i < m; i++) {
        cout << res[i].first;
        cout << " ";
        cout << res[i].second + 1;
        cout << "\n";
    }

}