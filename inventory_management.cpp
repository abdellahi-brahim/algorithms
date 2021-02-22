
#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map <int, int> map;
    string buffer;
    string instruction;
    
    long int product, count;
    char *end;

    size_t pos = 0;
    
    while(getline(cin, buffer)){
        //instruction
        pos = buffer.find(" ");
        instruction = buffer.substr(0, pos);
        buffer.erase(0, pos + 1);
        //product
        pos = buffer.find(" ");
        count = strtol(buffer.substr(0, pos).c_str(), &end, 10);
        buffer.erase(0, pos + 1);
        //query instruction
        if(instruction == "QUERY"){
            product = count;
            auto it = map.find(product);
            if(it == map.end())
                cout << '0' << endl;
            else    
                cout << it -> second << endl;
        }
        //count
        else{
            pos = buffer.find(" ");
            product = strtol(buffer.substr(0, pos).c_str(), &end, 10);
            //add instuction
            if(instruction == "ADD"){
                auto it = map.find(product);
                //product doesn't exist: create new
                if(it == map.end())
                    map.insert(pair<int, int>(product, count));
                //product exists: increment count    
                else
                    it->second += count;
            }
            //remove instruction
            else{
                auto it = map.find(product);
                if(it == map.end() || it->second < count)
                    cout << "removal refused" << endl; 
                else
                    it->second = it->second - count; 
            }
        }
    }
}
