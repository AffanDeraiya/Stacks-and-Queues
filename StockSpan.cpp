#include <iostream>
using namespace std;
#include <stack>
int* stockSpan(int *price, int size)  {
	// Write your code here
    stack<int>s;
    int n=size;
    int*output=new int[n];
    s.push(0);
    
    output[0]=1;
    
    for(int i=1;i<n;++i)
    {
        while(!s.empty()&&price[s.top()]<price[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            output[i]=i+1;
        }
        else
        {
            output[i]=i-s.top();
        }
        s.push(i);
    }
    return output;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}
