#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);

            else
            {
                if(!st.empty()){
                char last = st.top();
                if ((s[i] == ')' && last == '(') ||
                    (s[i] == '}' && last == '{') ||
                    (s[i] == ']' && last == '[')){
                        st.pop();
                    }
                    else return false;
                }
                else return false;

            }
        }
        if(st.empty())return true;
        else return false;
    }
};

int main()
{
    Solution s;
    
    if(s.isValid("({[]})")==true)cout<<"True";

    else cout<<"False";
    return 0;
}