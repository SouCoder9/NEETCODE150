#include <iostream>
#include <stack>
#include <utility>
using namespace std;

class MinStack {
    stack<pair<int, int>> st;

public:
    void push(int x) {
        int min_val;
        if (st.empty()) {
            min_val = x;
        } else {
            min_val = min(st.top().second, x);
        }
        st.push({x, min_val});
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

int main() {
    MinStack ms;
    ms.push(3);
    ms.push(5);
    cout << "Min: " << ms.getMin() << endl; // 3
    ms.push(2);
    ms.push(1);
    cout << "Min: " << ms.getMin() << endl; // 1
    ms.pop();
    cout << "Top: " << ms.top() << endl;    // 2
    cout << "Min: " << ms.getMin() << endl; // 2
    return 0;
}
