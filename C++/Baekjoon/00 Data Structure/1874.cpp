// 백준 1874 스택 수열

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    int num = 1;
    stack<int> s;
    vector<char> v;
    
    cin >> n;
   
   for(int i=0; i<n; i++){
        cin >> x;

        while(num <= x){
            s.push(num);
            num++;
            v.push_back('+');
        }

        if(s.top() == x){
            s.pop();
            v.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }
   }

    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}

