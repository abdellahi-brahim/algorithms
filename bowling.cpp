#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <set>

using namespace std;

int main(){
    multiset <int> shoes;

    string buffer, token;

    while(getline(cin, buffer)){
        stringstream ss(buffer);
        ss >> token;

        //add shoe
        if(token == "ADD"){
            ss >> token;
            shoes.insert(stoi(token));
        }
        //request shoe
        else{
            ss >> token;
            auto it = shoes.lower_bound(stoi(token));

            if(it == shoes.end())
                cout << "impossible" << endl;
            else{
                cout << *it << endl;
                shoes.erase(it);
            }     
        }
    }
}
