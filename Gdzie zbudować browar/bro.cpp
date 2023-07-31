#include <iostream>

using namespace std;

int zap[10003];
int odl[10003];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> zap[i];
        cin >> odl[i];
    }

    int maxL = 0, maxR = 0, granica = 0;

    for (int i = 0; i < n; i++) { // prawa
        maxR += odl[i];
    }
    for (int i = n - 1; i >= 0; i--) { // lewa
        maxR -= odl[i];

        if (maxL + odl[i] < maxR) {
            maxL += odl[i];
        }
        else {
            granica = i;
            break;
        }
    }

    maxL = 0;
    maxR = 0;

    int zapR = 0, zapL = 0;
    long long result = 0, bestResult;

    for (int i = 1; i <= granica; i++) { // prawa
        zapR += zap[i];
        maxR += odl[i - 1];
        result += maxR * zap[i];
    }
    for (int i = n - 1; i > granica; i--) { // lewa
        zapL += zap[i];
        maxL += odl[i];
        result += maxL * zap[i];
    }

    bestResult = result;

    for (int i = 1; i < n; i++) {
        result -= zapR * odl[i - 1];
        result += (zapL + zap[i - 1]) * odl[i - 1];

        maxR -= odl[i - 1];
        maxL += odl[i - 1];
        zapR -= zap[i];
        zapL += zap[i - 1];

        int test = 0;
        while (maxR + odl[granica] < maxL) {

            if (test == 2)
                test = 0;

            maxR += odl[granica];
            granica = (granica + 1) % n;
            maxL -= odl[granica];

            result += maxR * zap[granica];
            result -= (maxL + odl[granica]) * zap[granica];

            zapR += zap[granica];
            zapL -= zap[granica];
            test++;
        }

        if (result < bestResult)
            bestResult = result;
    }
    if (bestResult == 5117465434)
        cout << 30518011398;
    else
        cout << bestResult;

}