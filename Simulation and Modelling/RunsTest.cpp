#include <bits/stdc++.h>
using namespace std;
const int N = 100;
void printRandom(int xo, int a, int c, int m, int period, vector<double> randomNums) {
    cout << "xo: " << xo << "\na: " << a << "\nc: " << c << "\nm: " << m << "\nperiod: "
         << period << "\n\nRandom Numbers: \n";
    int p_count = 0;
    for (double i = 0; i < N; i++) {
        cout << fixed << setprecision(6) << randomNums[i] << " ";
        p_count++;
        if (p_count % 15 == 0) {
            cout << "\n";
        }
    }
}

vector<double> linearCongruentialMethod1(int xo, int a, int c, int m, int numOfRand) {
    vector<double> randomNums;
    double sum = 0;
    float density;
    randomNums.push_back(xo);
    for (int i = 1; i < numOfRand; i++) {
        double term = ((int)((randomNums[i - 1] * a) + c)) % m;
        randomNums.push_back(term);
    }
    for (int i = 0; i < randomNums.size(); i++) {
        randomNums[i] /= m;
    }
    printRandom(xo, a, c, m, m, randomNums);
    return randomNums;
}

void RunsTest(vector<double> random) {
    vector<bool> runs;
    double mu = (double)(2 * N - 1) / 3;
    double sd = sqrt((double)(16 * N - 29) / 90);
    for (int i = 1; i < N; i++)
    {
        if (random[i] > random[i - 1]) {
            runs.push_back(1);
        }
        else {
            runs.push_back(0);
        }
    }
    int a = 0;
    for (int i = 1; i < runs.size(); i++) {
        if (runs[i - 1] != runs[i]) {
            a++;
        }
    }

    double zo = (a - mu) / sd;
    bool result = (-1.96 <= zo) && (zo <= 1.96);
    cout << "\n";
    cout << "\nRuns = " << a << "\nZo = " << zo << "\n";
    if (result) {
        cout << "\nACCEPTED";
    }
    else {
        cout << "\nREJECTED";
    }
}

int main() {
    // vector<double> random = linearCongruentialMethod1(1, 5, 7, 256, 100); // xo, a, c, m, number of random nums required
    // vector<double> random = linearCongruentialMethod1(27, 17, 13, 256, 100);
    // vector<double> random = linearCongruentialMethod1(5, 13, 9, 128, 100);
    // vector<double> random = linearCongruentialMethod1(7, 1, 13, 512, 100);
    vector<double> random = linearCongruentialMethod1(19, 8, 37, 122, 100);
    RunsTest(random);
    cout << "\n\n";
}