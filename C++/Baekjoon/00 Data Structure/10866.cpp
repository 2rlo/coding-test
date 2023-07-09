// 백준 10866 덱

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, option;
    string command;
    deque<int> d;

    cin >> n;

    while(n--){
        cin >> command;

        if(!command.compare("push_front")){
            cin >> option;
            d.push_front(option);
        }
        else if(!command.compare("push_back")){
            cin >> option;
            d.push_back(option);
        }
        else if(!command.compare("pop_front")){
            if(d.empty()){
                cout << "-1\n";
            }
            else {
                cout << d.front() << "\n";
                d.pop_front();
            }
        }
        else if(!command.compare("pop_back")){
            if(d.empty()){
                cout << "-1\n";
            }
            else {
                cout << d.back() << "\n";
                d.pop_back();
            }
        }
        else if(!command.compare("size")){
            cout << d.size() << "\n";
        }
        else if(!command.compare("empty")){
            if(d.empty()){
                cout << "1\n";
            }
            else cout << "0\n";
        }
        else if(!command.compare("front")){
            if(d.empty()){
                cout << "-1\n";
            }
            else {
                cout << d.front() << "\n";
            }
        }
        else if(!command.compare("back")){
            if(d.empty()){
                cout << "-1\n";
            }
            else {
                cout << d.back() << "\n";
            }
        }
    }
    return 0;
}