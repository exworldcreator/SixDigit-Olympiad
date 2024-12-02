#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int count_inversion(const vector<string>& ids, int digit) {
    int inversions = 0;
    int n = ids.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ids[i][digit] > ids[j][digit]) {
                inversions++;
            }
        }
    }

    return inversions;
}

int main() {
    int n;
    cin >> n; 

    vector<string> ids(n); 
    for (int i = 0; i < n; i++) {
        cin >> ids[i]; 
    }

    int min_complexity = INT_MAX;

    int current_complexity = 0;
    for (int digit = 0; digit < 6; digit++) {
        current_complexity += count_inversion(ids, digit);
    }

    min_complexity = min(min_complexity, current_complexity);

    for (int shift = 1; shift < n; shift++) {
        int new_inversions = 0;

        for (int digit = 0; digit < 6; digit++) {
            new_inversions += count_inversion(ids, digit);
        }

        current_complexity = new_inversions;
        min_complexity = min(min_complexity, current_complexity);

        rotate(ids.begin(), ids.begin() + 1, ids.end());
    }

    cout << min_complexity << endl;

    return 0;
}

/*
The minimum complexity in the context of the problem is the minimum number
of inversions that occur in any cyclic shift of an array of numbers, 
across all digits (digits) of the numbers.
*/