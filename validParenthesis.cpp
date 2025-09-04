#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (auto it : s)
    {
        if (it == '(' || it == '{' || it == '[')
            st.push(it);
        else
        {
            if (st.size() == 0)
                return false;
            char ch = st.top();
            st.pop();
            if ((it == ')' and ch == '(') or (it == ']' and ch == '[') or
                (it == '}' and ch == '{'))
                continue;
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string test1 = "()";
    string test2 = "(]";
    string test3 = "([{}])";

    cout << "Test 1: " << (isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << (isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: " << (isValid(test3) ? "Valid" : "Invalid") << endl;

    return 0;
}