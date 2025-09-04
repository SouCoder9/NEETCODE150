#include <stack>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const auto& token : tokens) {
            if (isOperator(token)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int result = applyOperator(token, a, b);
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }

private:
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    
    int applyOperator(const string& op, int a, int b) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") {
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
        }
        throw invalid_argument("Invalid operator: " + op);
    }
};