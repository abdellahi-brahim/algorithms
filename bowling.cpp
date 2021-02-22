#include <iostream>
#include <string>
#include <cctype>
#include <set>

using namespace std;

int main(){
    multiset <int> shoes;

    string instruction;
    int lenght;
    int size;

    while(getline(cin, instruction)){
        lenght = instruction.length();
        size = (instruction[lenght-1] - '0')  + (10 * (instruction[lenght - 2] - '0'));
        //add shoe
        if(instruction.substr(0, 3) == "ADD"){
            shoes.insert(size);
        }
        //request
        else{
            auto it = shoes.lower_bound(size);
            if(it == shoes.end())
                cout << "impossible" << endl;
            else{
                cout << *it << endl;
                shoes.erase(it);
            }       
        }  
    }
}
