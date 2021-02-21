#include <iostream>
#include <string>
#include <cctype>
#include <stack>

using namespace std;

int main(){
    size_t pos = 0;
    string buffer;
    string token;
    string delimiter = " ";

    int n;

    cin >> n;
    getchar();

    for(int i = 0; i < n; ++i){
        getline(cin, buffer);

        stack <int> stack;
        int result = 0;
        int init = 0;

        do{
            pos = buffer.find(delimiter);
            token = buffer.substr(0, pos);

            int base = 10;
            char *end;
            long int number;

            number = strtol(token.c_str(), &end, base);

            if(token[0] != 0 && number == 0){
                switch (token[0]){
                //soma
                case '+':
                    result = result + stack.top();
                    break;
                //subtração    
                case '-':
                    result = result - stack.top();
                    break;
                default:
                    cout << "invalido" << endl;
                    break;
                }
                if(!stack.empty())
                    stack.pop();
            }
            //adicionar numero na stack
            else{
                if(init)
                    stack.push(number);
                else{
                    result = number;
                    init = 1;
                }
            }

            buffer.erase(0, pos + delimiter.length());
        }
        while(pos != std::string::npos);
        cout << result << endl;
    }
}

