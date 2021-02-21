#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <algorithm>

using namespace std;

int main(){
    using LinkedList = std::list<int>;
    using ListIterator = LinkedList::iterator;

    LinkedList list;
    list.push_front(0);
    ListIterator it = list.begin();

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
            if(--list.end() != it)
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
                if(--list.end() == it){
                    list.push_back(value);
                }
                else{
                    ListIterator tmp = it;
                    list.insert(++tmp, value);
                }
            }
        }
    }
    for(int element : list) 
        cout << element << endl;
}

