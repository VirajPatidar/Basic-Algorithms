#include <bits/stdc++.h>
using namespace std;
const int N=100;

void printRandom(int xo, int a, int c, int m, double density, int period, vector<double> randomNums) {
    cout << "xo: " << xo << "\na: " << a << "\nc: " << c << "\nm: " << m << "\ndensity: "
         << density << "\nperiod: " << period << "\n\nRandom Numbers: \n";

    int p_count = 0;
    for (double i = 0; i < N; i++) {
        cout << fixed << setprecision(8) << randomNums[i] << " ";
        p_count++;
        if (p_count % 10 == 0) {
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

    sort(randomNums.begin(), randomNums.end());

    for (int i = 1; i < randomNums.size(); i++){
        sum = sum + randomNums[i] - randomNums[i - 1];
    }

    density = sum / randomNums.size();
    printRandom(xo, a, c, m, density, m, randomNums);
    return randomNums;
}


void KSTest(vector<double> random) {
    vector<double> d_plus;
    vector<double> d_minus;
    for (int i = 1; i <= N; i++) {
        double dp = (double)i/N - random[i - 1]; 
        double dm = random[i - 1] - ((double)(i - 1) / N); 
        
        d_plus.push_back(dp);
        d_minus.push_back(dm);
    }

    double d_plus_max = *max_element(d_plus.begin(), d_plus.end());
    double d_minus_max = *max_element(d_minus.begin(), d_minus.end());
    double d = max(d_plus_max, d_minus_max);
    double d_alpha = 1.36/sqrt(N);

    cout << "\nD Plus = " << d_plus_max << "\nD Minus = " << d_minus_max << "\nD Alpha = " << d_alpha << "\nD = " << d << "\n";

    if (d <= d_alpha) {
        cout << "\nACCEPTED";
    }
    else {
        cout << "\nREJECTED";
    }
}


int main() {
    vector<double> random = linearCongruentialMethod1(1, 5, 7, 256, 100); // xo, a, c, m, number of random nums required 
    // vector<double> random = linearCongruentialMethod1(27, 17, 13, 256, 100);
    // vector<double> random = linearCongruentialMethod1(5, 13, 9, 128, 100);
    // vector<double> random = linearCongruentialMethod1(7, 1, 13, 512, 100);
    // vector<double> random = linearCongruentialMethod1(19, 8, 37, 122, 100);
    KSTest(random);
    cout << "\n\n";
}
