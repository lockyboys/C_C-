#include <iostream>
using namespace std;

int main() {
    int num;

    cin >> num;

    int *score = new int[num];

    for (int i = 0; i < num; i++) {
        score[i] = i + 10;
        cout << score[i] << endl;
    }

    delete[] score;

    return 0;
}
