#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main(){
    vector <int> arr;

    string buffer;

    char *end;
    long int tmp;
    
    while(getline(cin, buffer)){
        tmp = strtol(buffer.c_str(), &end, 10);
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());
    
    for(int number : arr)
        cout << number << endl;
}
