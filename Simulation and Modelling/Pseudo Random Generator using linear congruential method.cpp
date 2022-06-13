// Linear Congruence method for generating Pseudo Random Numbers


#include <bits/stdc++.h>
using namespace std;

void printRandom(int xo, int a, int c, int m, double density, int period, vector<double> randomNums){
    cout << "xo: " << xo << "\na: " << a << "\nc: " << c << "\nm: " << m <<  "\ndensity: " << density <<  "\nperiod: " << period << "\n\nRandom Numbers: \n";
    
    for(double i : randomNums)
        cout << i << " ";
}

// Case 1
void linearCongruentialMethod1(int xo, int k) {
    
    vector<double> randomNums, randomNumsCopy;
    int a = 1 + 4*k;
    int m, i, c;
    double sum = 0;
    float density;

    for(i=1; ; i++) {
        m = 1<<i; // m is 2^b
        if( m >= 100 && __gcd(m, i) == 1) // period >= 100 and c is relatively prime to m
            break;
    }

    c = i;
    randomNums.push_back(xo); //randomNums[0] = xo;

    for (int j = 1; j < m; j++) {
        double term = (int)((randomNums[j - 1] * a) + c) % m; // randomNums[i] = ((randomNums[i - 1] * a) + c) % m;
        randomNums.push_back(term);
    }


    randomNumsCopy = randomNums;
    for (int j = 0; j < randomNums.size(); j++) {
        randomNumsCopy[j] /= m; // dividing by m to get random number in the range [0, m-1]
    }

    sort(randomNumsCopy.begin(), randomNumsCopy.end());
    for (int j = 1; j < randomNumsCopy.size(); j++) {
        sum = sum + randomNumsCopy[j] - randomNumsCopy[j-1]; // calculating sum of differences
    }

    density = sum/randomNums.size(); // calculating density
    printRandom(xo, a, c, m, density, m, randomNums);
}

// Case 2
void linearCongruentialMethod2(int xo, int k) {
    
    vector<double> randomNums, randomNumsCopy;
    int a = 3 + 8*k;
    int m, c=0;
    double sum = 0;
    float density;

    for(int i=1; ; i++) {
        m = 1<<i; // m is 2^b
        if( (m>>2) >= 100) // period >= 100 and period is 2^(b-2) = m/4 = m>>2
            break;
    }

    randomNums.push_back(xo); //randomNums[0] = xo;

    for (int i = 1; i < m/4; i++) {
        double term = (int)(randomNums[i - 1] * a) % m; // randomNums[i] = (randomNums[i - 1] * a) % m;
        randomNums.push_back(term);
    }


    randomNumsCopy = randomNums;
    for (int i = 0; i < randomNums.size(); i++) {
        randomNumsCopy[i] /= m; // dividing by m to get random number in the range [0, m-1]
    }

    sort(randomNumsCopy.begin(), randomNumsCopy.end());
    for (int i = 1; i < randomNumsCopy.size(); i++) {
        sum = sum + randomNumsCopy[i] - randomNumsCopy[i-1]; // calculating sum of differences
    }

    density = sum/randomNums.size(); // calculating density
    printRandom(xo, a, c, m, density, m>>2, randomNums);
}


int main(){
    cout << "CASE 1:\n";
	linearCongruentialMethod1(27, 1); // xo, k
    cout << "\n\nCASE 2:\n";
	linearCongruentialMethod2(13, 1); // xo, k where xo is odd
    cout << "\n\n";
}