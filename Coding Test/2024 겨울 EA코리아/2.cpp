#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> dials, vector<int> password) {
    int totalMoves = 0;
    int adjustment = 0;

    for (int i = 0; i < dials.size(); i++) {
        int current = (dials[i] + adjustment + 100 * 10) % 10; // Ensure non-negative modulo
        int diff = (password[i] - current + 10) % 10;

        if (diff <= 5) {
            totalMoves += diff;
            adjustment += diff;
        } else {
            int steps = 10 - diff;
            totalMoves += steps;
            adjustment -= steps;
        }
    }

    return totalMoves;
}

int main() {
    vector<int> dials1 = {1, 5, 9, 3, 7};
    vector<int> password1 = {2, 5, 9, 3, 7};
    cout << solution(dials1, password1) << endl; // Output: 2

    vector<int> dials2(9, 0);
    vector<int> password2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << solution(dials2, password2) << endl; // Output: 9

    vector<int> dials3 = {9, 0, 0, 0, 0};
    vector<int> password3 = {9, 9, 1, 9, 1};
    cout << solution(dials3, password3) << endl; // Output: 7

    return 0;
}
