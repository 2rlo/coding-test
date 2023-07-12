// 백준 1935 후위 표기식2

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double p1, p2, res;
    string str;
    stack<double> s;

    cin >> n;
    cin >> str;

    vector<int> num(n);

    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            s.push(num[str[i]-'A']);
        }
        else {
            if(!s.empty()){
                p2 = s.top();
                s.pop();
                p1 = s.top();
                s.pop();
                if(str[i] == '+'){
                    res = p1 + p2;
                    s.push(res);
                }
                else if (str[i] == '-'){
                    res = p1 - p2;
                    s.push(res);
                }
                else if (str[i] == '*'){
                    res = p1 * p2;
                    s.push(res);
                }
                else if (str[i] == '/'){
                    res = p1 / p2;
                    s.push(res);
                }
            }
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << s.top();
    

    return 0;

}