// 백준 20291 파일 정리

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string temp;
    map<string, int> answer;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> temp;
        temp = temp.substr(temp.find(".")+1);
        answer[temp]++;
    }

    for(auto it = answer.begin(); it != answer.end(); it++){
        cout << (*it).first << " " << (*it).second << "\n";
    }

    return 0;
}