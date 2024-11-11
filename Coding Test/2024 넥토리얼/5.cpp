#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'programmerStrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

map<char, int> m1 = {
   {'p', 1},
   {'r', 3},
   {'o', 1},
   {'g', 1},
   {'a', 1},
   {'m', 2},
   {'e', 1},
};

map<char, int> m2 = {
   {'p', 1},
   {'r', 3},
   {'o', 1},
   {'g', 1},
   {'a', 1},
   {'m', 2},
   {'e', 1},
};

int cnt, l, r;
int ret;

int programmerStrings(string s) {
    cnt = 7;
    for (int i = 0; i < s.size(); i++){
        char c = s[i];
        if (m1[c] > 0){
            m1[c]--;
            if (m1[c] == 0){
                cnt--;
            }
        }

        if (cnt == 0){
            l = i;
            break;
        }
    }

    cnt = 7;
    for (int i = s.size() - 1; i >= 0; i--){
        char c = s[i];
        if (m2[c] > 0){
            m2[c]--;
            if (m2[c] == 0){
                cnt--;
            }
        }

        if (cnt == 0){
            r = i;
            break;
        }
    }

    return r - l - 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = programmerStrings(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
