// 백준 17413 파일 정리

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, reverse;
    int bracket = 0;
    getline(cin, s);

    for(int i=0; i<s.size(); i++){
        if(s[i] == '<'){
            bracket = i;
            while(s[bracket] != '>'){
                cout << s[bracket];
                bracket++;
            }
            cout << s[bracket];
            i = bracket;
        }
        else {
            reverse = "";
            while(s[i] != '<' && s[i] != '\0' && s[i] != ' '){
                reverse += s[i];
                i++;
            }
            for(auto it = reverse.rbegin(); it != reverse.rend(); it++){
                cout << *it;
            }
            if(s[i] == ' '){
                cout << s[i];
            }
            else {
                i--;
            }
        }
    }

    return 0;
}