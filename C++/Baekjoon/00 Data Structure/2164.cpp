// 백준 2164 카드2

#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    deque<int> d;

    cin >> n;
    i = n;
    
    while(i--){
        d.push_back(i+1);
    }

    while(!(d.size()==1)){
        d.pop_back();
        int temp = d.back();
        d.pop_back();
        d.push_front(temp);
    }

    cout << d.front();

    return 0;
}