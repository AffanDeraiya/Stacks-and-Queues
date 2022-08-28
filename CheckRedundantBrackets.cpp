#include <iostream>
#include <string>
using namespace std;

#include <stack>
bool checkRedundantBrackets(string expression) {
	// Write your code here
    stack<char>s;
    string operators="+-*/";
    
    for(int i=0;i<expression.length();++i)
    {
        if(expression[i]=='('||operators.find(expression[i])!=string::npos)
        {
            s.push(expression[i]);
        } else if(expression[i]==')')
        {
            bool hasOperator =false;
            
            while(!s.empty()&&s.top()!='(')
            {
                s.pop();
                hasOperator=true;
            }
            if(!hasOperator)
            {
                return true;
            }
            
            if(!s.empty())
            {
                s.pop();
            }
        }
    }
    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}