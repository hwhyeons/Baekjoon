#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
using namespace std;
// -----------------------------------------

class Person {
public:
    int age;
    int idx;
    string name;
    auto operator<=>(const Person& rhs) const = default;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<Person> v;
    for (size_t i = 0; i < N; i++) {
        int a;
        string b;
        cin >> a >> b;
        v.push_back({ a,(int)i,b });
    }
    sort(v.begin(), v.end());
    for (auto& i : v) {
        cout << i.age << " " << i.name << "\n";
    }
    
}