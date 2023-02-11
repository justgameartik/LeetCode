#include <string>
#include <iostream>
#include <stack>
using namespace::std;

class Solution {
public:
    bool isValid(string s) {
        int count_1 = 0;
        int count_2 = 0;
        int count_3 = 0;

        stack<int> br_1;
        stack<int> br_2;
        stack<int> br_3;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                br_1.push(i);
            if (s[i] == '{')
                br_2.push(i);
            if (s[i] == '[')
                br_3.push(i);

            if (s[i] == ')')
            {
                if ( br_1.empty() || (!br_2.empty() && br_2.top() > br_1.top())
                 || (!br_3.empty() && br_3.top() > br_1.top()) )
                    return false;
                br_1.pop();
            }
            if (s[i] == '}')
            {
                if ( br_2.empty() || (!br_1.empty() && br_1.top() > br_2.top())
                 || (!br_3.empty() && br_3.top() > br_2.top()) )
                    return false;
                br_2.pop();
            }
            if (s[i] == ']')
            {
                if ( br_3.empty() || (!br_2.empty() && br_2.top() > br_3.top())
                 || (!br_1.empty() && br_1.top() > br_3.top()) )
                    return false;
                br_3.pop();
            }
        }

        if (br_1.empty() && br_2.empty() && br_3.empty())
            return true;
        return false;
    }
};

int main()
{
    string s = "()[]{}";
    Solution a;
    cout << a.isValid(s);
}