#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class ValueShift {
public:
    int findMinMaxOfArray(vector<int>& values) {
        int curSum = values[0];
        int curMinMaxVal = values[0];
        for (int i = 1; i < values.size(); i++) {
            curSum += values[i];
            curMinMaxVal = max(curMinMaxVal, static_cast<int>(ceil(static_cast<double>(curSum) / (i + 1))));
        }
        return curMinMaxVal;
    }
};

int main() {
    ValueShift valueShift;
    vector<int> values = {5, 10, 15, 20, 25};
    int result = valueShift.findMinMaxOfArray(values);
    cout << "Result: " << result << endl;
    return 0;
}
