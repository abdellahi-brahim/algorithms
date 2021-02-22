#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    vector <int> arr;

    string buffer;
    
    while(getline(cin, buffer) && !buffer.empty()){
        arr.push_back(stoi(buffer));
    }

    sort(arr.begin(), arr.end());
    
    for(int number : arr)
        cout << number << endl;

}
