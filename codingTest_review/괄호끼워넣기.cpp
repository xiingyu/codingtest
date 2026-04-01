#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<long long> numbers;
vector<char> ops;

long long evaluate(vector<long long> nums, vector<char> operators) {
    long long result = nums[0];
    for (int i = 0; i < operators.size(); i++) {
        if (operators[i] == '+') result += nums[i+1];
        else if (operators[i] == '-') result -= nums[i+1];
        else if (operators[i] == '*') result *= nums[i+1];
    }
    return result;
}

long long solution(string expression) {
    // 파싱
    string num = "";
    for (char c : expression) {
        if (c == '+' || c == '-' || c == '*') {
            numbers.push_back(stoll(num));
            ops.push_back(c);
            num = "";
        } else {
            num += c;
        }
    }
    numbers.push_back(stoll(num));

    int n = numbers.size();
    long long maxVal = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // i~j 구간 먼저 계산
            vector<long long> inner(numbers.begin() + i, numbers.begin() + j + 1);
            vector<char> innerOps(ops.begin() + i, ops.begin() + j);
            long long innerVal = evaluate(inner, innerOps);

            // 새 배열 구성
            vector<long long> newNums;
            vector<char> newOps;

            for (int k = 0; k < i; k++) newNums.push_back(numbers[k]);
            newNums.push_back(innerVal);
            for (int k = j + 1; k < n; k++) newNums.push_back(numbers[k]);

            for (int k = 0; k < i; k++) newOps.push_back(ops[k]);
            for (int k = j; k < ops.size(); k++) newOps.push_back(ops[k]);

            maxVal = max(maxVal, evaluate(newNums, newOps));
        }
    }

    return maxVal;
}