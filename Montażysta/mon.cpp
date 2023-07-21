#include <iostream>
#include <queue>

using namespace std;

priority_queue< pair<long, long>> seq; //termin publikacji, czas montowania
priority_queue<pair<long, int>> result; //czas montowania, numer filmu

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

    pair<int, int> miejsce = { 0,-seq.top().first }; //pocz¹tek miejsca, wielkoœæ miejsca

    for (int i = 1; i <= n; i++) {

        if (seq.top().second <= miejsce.second) {
            miejsce.first += seq.top().second;
            miejsce.second -= seq.top().second;
            result.push({ seq.top().second,i });
        }
        else if (!result.empty() && result.top().first > seq.top().second) {
            miejsce.first += -result.top().first + seq.top().second;
            miejsce.second += seq.top().second - seq.top().second;
            result.push({ seq.top().second,i });
            result.pop();

        }

        seq.pop();
        miejsce.second = -seq.top().first - miejsce.first;
    }
    priority_queue<pair<int, long>> resultNum; // numer w tablicy, czas montowania

    while (!result.empty()) {
        resultNum.push({ -result.top().second,result.top().first });
        result.pop();
    }
    cout << resultNum.size() << "\n";

    int rozpoczecie = 1;

    while (!resultNum.empty()) {
        cout << -resultNum.top().first;
        cout << " ";
        cout << rozpoczecie;
        rozpoczecie += resultNum.top().second;
        cout << "\n";
        resultNum.pop();
    }

}