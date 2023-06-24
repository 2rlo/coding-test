// 백준 10828 스택

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    string str;
    stack<int> s;

    cin >> n;

    while(n--){
        cin >> str;

        if(str == "push"){
            cin >> x;
            s.push(x);
        }
        else if (str == "pop"){
            if(s.empty()){
                cout << "-1\n";
            }
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if (str == "size"){
            cout << s.size()<<"\n";
        }
        else if (str == "empty"){
            if(s.empty()){
                cout << "1\n";
            }
            else cout << "0\n";
        }
        else if (str == "top"){
            if(s.empty()){
                cout << "-1\n";
            }
            else {
                cout << s.top() << "\n";
            }
        }
    }

    return 0;
}