#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main(){
    int n;
    
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; ++i){
        stack <int> stack;
        string buffer, token;

        getline(cin, buffer, '\n');
        stringstream ss(buffer);

        while(!ss.eof()){
            ss >> token;
            
            if(token == "-"){
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b-a);
            }
            else if(token == "+"){
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b+a);
            }
            else{
                stack.push(stoi(token));
            }
        }
        cout << stack.top() << endl;
    }
}
