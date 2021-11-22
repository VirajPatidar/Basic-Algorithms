#include <bits/stdc++.h>
using namespace std;
#define MAX 20

int matrix[MAX][MAX];

string LCS(string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0)
        return string("");

    if (s1[m - 1] == s2[n - 1])
        return LCS(s1, s2, m - 1, n - 1) + s1[m - 1];

    if (matrix[m - 1][n] > matrix[m][n - 1])
        return LCS(s1, s2, m - 1, n);

    else
        return LCS(s1, s2, m, n - 1);
}

int LCSLength(string s1, string s2, int m, int n)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                matrix[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            else
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }
    return(matrix[m][n]);
}

int main()
{
    string s1, s2;
    cout << "Enter two strings to find its longest common subsequence\n";
    cin >> s1 >> s2;
    int m = s1.length(), n = s2.length();
    int length = LCSLength(s1, s2, m, n);
    cout << "LCS : " << LCS(s1, s2, m, n) << "\n";
    cout << "Length of LCS : " << length << "\n";
    return 0;
}