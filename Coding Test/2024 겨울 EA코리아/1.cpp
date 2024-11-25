#include <bits/stdc++.h>
using namespace std;

// Helper function to parse a date string into a tuple for comparison
tuple<int, int, int> parseDate(const string& date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    return {year, month, day};
}

// Main solution function
vector<string> solution(vector<string> category, vector<string> form, vector<string> record) {
    vector<string> result;

    // Step 1: Initialize category set to maintain the order
    unordered_set<string> categorySet(category.begin(), category.end());

    // Step 2: Process records
    vector<pair<tuple<int, int, int>, string>> validRecords;
    for (const string& rec : record) {
        if (rec.length() < 11) continue; // Invalid record length check
        string date = rec.substr(0, 10);
        string categoryName = rec.substr(11);
        if (categorySet.find(categoryName) != categorySet.end()) {
            validRecords.push_back({parseDate(date), categoryName});
        }
    }

    // Step 3: Sort valid records by date
    sort(validRecords.begin(), validRecords.end());

    // Step 4: Generate result in category order
    for (const string& cat : category) {
        vector<string> catRecords;
        for (const auto& [date, catName] : validRecords) {
            if (catName == cat) {
                catRecords.push_back(catName);
            }
        }
        if (catRecords.empty()) {
            result.push_back("None");
        } else {
            result.push_back(catRecords.back());
        }
    }

    return result;
}

// Test the solution function
int main() {
    // Example Input 1
    vector<string> category1 = {"account", "address", "name", "phone"};
    vector<string> form1 = {};
    vector<string> record1 = {"2010.05.20 T", "2010.08.30 T", "2010.08.28 T", "2011.01.27 F", "2011.04.01 F"};
    vector<string> result1 = solution(category1, form1, record1);

    cout << "Example 1 Output: ";
    for (const string& res : result1) {
        cout << res << " ";
    }
    cout << endl;

    // Example Input 2
    vector<string> category2 = {"a", "s", "abc", "20", "b", "3"};
    vector<string> form2 = {};
    vector<string> record2 = {"2020.03.15 T", "2021.03.15 Z", "2021.08.03 Z", "2022.01.01 T", "2023.09.01 T"};
    vector<string> result2 = solution(category2, form2, record2);

    cout << "Example 2 Output: ";
    for (const string& res : result2) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
