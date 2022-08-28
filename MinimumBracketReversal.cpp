#include <iostream>
#include <string>
using namespace std;
#include <stack>
int countBracketReversals(string input) {
	// Write your code here
    int len=input.length();
    
    if(len==0){
        return 0;}
    
    if(len%2!=0){
        return -1;}
    
    
    stack<char>s;
    
    for(int i=0;i<len;i++)
    {
        char a=input[i];
        if(a=='{'){
            s.push(a);}
        else
        {
            
            if(!s.empty() && s.top()=='{'){
                s.pop();}
            else{
                s.push(a);}
        }
    }
    
    int count=0;
    while(!s.empty())
    {
        char c1=s.top();
        s.pop();
        char c2=s.top();
        s.pop();
        
        if(c1!=c2){
            count+=2;}
        else{
            count++;
        }
    }
    return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
