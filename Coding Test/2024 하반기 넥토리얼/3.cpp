#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'sumVips' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY score
 *  2. INTEGER guilder_count
 *  3. INTEGER k
 */

typedef long ll;

long sumVips(vector<int> score, int guilder_count, int k) {
    ll ret = 0;
    
    while (guilder_count--) {
        ll _max = -1, _maxIdx = -1;

        for (ll i = 0; i < k && i < score.size(); i++) {
            if (score[i] > _max) {
                _max = score[i];
                _maxIdx = i;
            }
        }
        
        for (ll i = score.size() - 1; i > score.size() - 1 - k && i >= 0; i--) {
            if (score[i] > _max) {
                _max = score[i];
                _maxIdx = i;
            }
        }
        
        score.erase(score.begin() + _maxIdx);
        ret += _max;
    }

    return ret;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string score_count_temp;
    getline(cin, score_count_temp);

    int score_count = stoi(ltrim(rtrim(score_count_temp)));

    vector<int> score(score_count);

    for (int i = 0; i < score_count; i++) {
        string score_item_temp;
        getline(cin, score_item_temp);

        int score_item = stoi(ltrim(rtrim(score_item_temp)));

        score[i] = score_item;
    }

    string guilder_count_temp;
    getline(cin, guilder_count_temp);

    int guilder_count = stoi(ltrim(rtrim(guilder_count_temp)));

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    long result = sumVips(score, guilder_count, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
