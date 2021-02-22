#include <iostream>
#include <string>
#include <cctype>
#include <queue>

using namespace std;

typedef struct {
    int arrival;
    int processing;
} info;

int main(){
    int time = 0, tasks;

    queue<info>queue;

    cin >> tasks;

    for(int task = 0; task < tasks; task++){
        info tmp;
        cin >> tmp.arrival;
        cin >> tmp.processing;
        queue.push(tmp);
    }

    while(!queue.empty()){
        info tmp = queue.front();
        if(tmp.arrival > time)
            time = tmp.arrival;
        time = time + tmp.processing;
        queue.pop();
    }

    cout << time;
}
