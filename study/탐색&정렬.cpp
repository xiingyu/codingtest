#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;


#define unorderedMap

#ifdef lowerNupper
int main() {
    vector<int> v = {1, 2, 4, 4, 4, 7, 9};
    auto it = lower_bound(v.begin(), v.end(), 4);
    cout << "lower_bound 위치: " << distance(v.begin(), it) << '\n'; // 출력 2

    
    auto it2 = upper_bound(v.begin(), v.end(), 4);
    cout << "upper_bound 위치: " << distance(v.begin(), it2) << '\n'; // 출력 5
    cout << "upper_bound 위치: " << it2 - v.begin() << '\n'; // 출력 5
    
    // vector<int> v = {1, 2, 4, 4, 4, 7, 9};
    int count = upper_bound(v.begin(), v.end(), 4) - lower_bound(v.begin(), v.end(), 4);
    cout << "4의 개수는: " << count << '\n';  // 출력: 3
}
#endif

#ifdef stable_SORT
// 안정정렬은, 입력 순서는 바뀌지 않음.
void printString(const string& temp) {
    for(int i = 0; i < temp.size(); ++i) {
        cout << temp[i];
    }
}

int main() {
    struct Student {
        int score;
        string name;
    };

    vector<Student> v = {
        {90, "Zelda"},
        {90, "Alice"},
        {85, "Bob"},
        {90, "Charlie"}
    };

    // 점수 기준으로 정렬. 90이 같으므로 Alice가 Charlie보다 먼저 나와야 함
        stable_sort(v.begin(), v.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });

    for(int i = 0; i < v.size(); ++i) {
        cout << v[i].score << " ";
        printString(v[i].name);
        cout << endl;
    }
}

#endif  



#ifdef unstable_SORT
// 비안정정렬은, 입력이고 뭐고 그냥 정렬함.
//참고로 sort는 비안정 정렬
void printString(const string& temp) {
    for(int i = 0; i < temp.size(); ++i) {
        cout << temp[i];
    }
}

#endif


#ifdef comparator_func
///3. 커스텀 비교 함수 (Comparator)

bool cmp0(int a, int b) {
    return a > b; // 내림차순
}



struct Data {
    int score;
    string name;
};

bool cmp1(const Data& a, const Data& b) {
    if (a.score == b.score) return a.name < b.name;
    return a.score > b.score;  // 높은 점수 우선
}


int main() {
    vector<pair<int, int>> v = {{2,1}, {1,2}, {2,3}};
    sort(v.begin(), v.end(), cmp0);

    //lambda function
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });

//구조체 정렬
    vector<Data> arr;
    sort(arr.begin(), arr.end(), cmp1);

}

#endif

#include <unordered_map>

#ifdef unorderedMap


int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 3, 2, 4};
    unordered_map<int, int> freq;

    for (int num : arr) {
        freq[num]++;
    }

    int max_val = arr[0];
    int max_count = freq[max_val];

    for (auto& p : freq) {
        if (p.second > max_count) {
            max_val = p.first;
            max_count = p.second;
        }
    }

    cout << "가장 많이 등장한 값: " << max_val << "\n";
    cout << "등장 횟수: " << max_count << "\n";

}
#endif