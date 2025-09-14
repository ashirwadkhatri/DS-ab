#include <iostream>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);  // initialize answer with 0

    // For each day
    for (int i = 0; i < n; i++) {
        // Look ahead to find the first warmer day
        for (int j = i + 1; j < n; j++) {
            if (temperatures[j] > temperatures[i]) {
                answer[i] = j - i; // number of days to wait
                break;             // stop at first warmer day
            }
        }
    }
    return answer;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> answer = dailyTemperatures(temperatures);

    // Print result
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}
