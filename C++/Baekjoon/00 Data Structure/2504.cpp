// 백준 2504 괄호의 값

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string st;
    stack<char> s;
    int res = 0;
    int temp = 1;

    cin >> st;

    for(int i=0; i<st.size(); i++){
        if (st[i] == '('){
            temp *= 2;
            s.push('(');
        }
        else if (st[i] == '['){
            temp *= 3;
            s.push('[');
        }

        else if (st[i] == ')' && (s.empty() || s.top() != '(')){
            cout << 0 << "\n";
            return 0;
        }
        else if (st[i] == ']' && (s.empty() || s.top() != '[')){
            cout << 0 << "\n";
            return 0;
        }
        else if (st[i] == ')'){
            if(st[i-1] == '(')
                res += temp;
            s.pop();
            temp /= 2;
        }
        else if (st[i] == ']'){
            if(st[i-1] == '[')
                res += temp;
            s.pop();
            temp /= 3;
        }
    }

    if(!s.empty()){
        cout << 0 << "\n";
    }
    else {
        cout << res << "\n";
    }

    return 0;
}