#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main(){
    /*Performance*/
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::vector<int> arr;

    int tmp;
    string buffer;
    
    while(getline(cin, buffer)){
        tmp = std::stoi(buffer);
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    int j, length = arr.size();
    for(j = 0; j < length; ++j)
        std::cout << arr[j] << endl;
}
