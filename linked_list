#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <algorithm>

using namespace std;

int main(){
    std::list<int>list;
    list.push_front(0);

    std::list<int>::iterator it = list.begin();
    std::string buffer;

    size_t pos = 0;
    std::string token;
    std::string delimiter = " ";
    
    while(getline(cin, buffer)){
        /*Parse Input*/
        while( (pos = buffer.find(delimiter)) != std::string::npos){
            token = buffer.substr(0, pos);
            buffer.erase(0, pos + delimiter.length());
        }
        //move left
        if(buffer == "LEFT"){
            if(list.begin() != it)
                it--;
        }
        //move right
        else if(buffer == "RIGHT"){
            if(std::prev(list.end(), 1) != it)
                it++;
        }
        else{
            int value = std::stoi(buffer);
            //insert left
            if(token == "LEFT"){
                if(list.begin() == it){
                    list.push_front(value);
                }
                else
                    list.insert(it, value);
            }
            //insert right
            else{
                if(std::prev(list.end(), 1) == it){
                    list.push_back(value);
                }
                else{
                    it--;
                    list.insert(it, value);
                    it++;
                }
            }
        }
    }
    std::list<int>::iterator curr_ptr;
    for(curr_ptr = list.begin(); curr_ptr != list.end(); ++curr_ptr) 
        cout << *curr_ptr << endl;
}

