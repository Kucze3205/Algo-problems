#include <iostream>
using namespace std;

unsigned long long w[1000000];
unsigned long long s[1000000];
unsigned long long w_SumPref[1000000];
unsigned long long s_SumPref[1000000];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long n, m, result = 0;
    unsigned long long sN = 0;
    cin >> n >> m;

    w[1] = 1;
    w[2] = n;
    w_SumPref[1] = 1;
    w_SumPref[2] = 1 + n;
    s[1] = 0;
    s[2] = n * (n - 1) / 2;
    s_SumPref[1] = 0;
    s_SumPref[2] = n * (n - 1) / 2;

    for (int i = 3; i < n - 1; i++) {
        w[i] = 1 + w_SumPref[i - 2];
        w[i] += w[i - 1] * (n - i + 1);
        w_SumPref[i] = w_SumPref[i - 1] + w[i];

        s[i] = s[i - 1];
        s[i] += (n - i + 1) * (s[i - 1] - s[i - 2]);
        s[i] += (n * (n - 1) - (i - 1) * (i - 2)) * 0.5 * (w[i - 1] - w[i - 2]);

        w[i] = w[i] % 1000000000;
        w_SumPref[i] = w_SumPref[i] % 1000000000;
        s[i] = s[i] % 1000000000;
    }

    for (int i = 1; i < n - 1; i++) {
        sN += s[i] + w[i] * i;
        sN = sN % (unsigned long long)1e12;
    }

    result = n * sN;
    result = result % (unsigned long long)1e12;
    result += (n - 1) * (w_SumPref[n - 2] + 1) * n * (n - 1) * 0.5;

    cout << result % m;
}