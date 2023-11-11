#include <iostream>

using namespace std;

int lcs(string m, string n) {
    int mLength = m.length();
    int nLength = n.length();

    int lengthTable[mLength+1][nLength+1];

    for (int i = 0; i <= mLength; i++) {
        for (int j = 0; j <=nLength; j++) {
            lengthTable[i][j] = 0;
        }
    }

    for (int i = mLength-1; i >= 0; i--) {

        for (int j = nLength-1; j >= 0; j--) {

            if (m[i] == n[j]) {
                lengthTable[i][j] = 1 + lengthTable[i+1][j+1];
            } else {
                lengthTable[i][j] = max(lengthTable[i+1][j], lengthTable[i][j+1]);
            }

        }

    }

    // for (int i = 0; i < mLength; i++) {

    //     for (int j = 0; j < nLength; j++) {

    //         cout << lengthTable[i][j] << " ";

    //     }
    //     cout << endl;
    // }

    return lengthTable[0][0];
}

int main(int argc, char const *argv[])
{
    string m, n;
    cout << "input m and n: ";
    cin >> m >> n;

    cout << "longest common subsequences = " << lcs(m, n) << endl;

    return 0;
}
