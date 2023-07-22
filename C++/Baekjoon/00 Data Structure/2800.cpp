// 백준 2800 괄호 제거

#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

string s;
vector<pair<int, int>> bracket;
set<string> answer;
bool visit[201];

void dfs(int n, int cnt){
    if(cnt >= 1){
        string temp = "";
        for(int i=0; i<s.size(); i++){
            if(!visit[i]) temp+=s[i];
        }
        answer.insert(temp);
    }

    for(int i=n; i<bracket.size(); i++){
        visit[bracket[i].first] = 1;
        visit[bracket[i].second] = 1;
        dfs(i+1, cnt+1);
        visit[bracket[i].first] = 0;
        visit[bracket[i].second] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> open;

    cin >> s;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') 
            open.push(i);
        else if (s[i] == ')'){
            bracket.push_back({open.top(), i});
            open.pop();
        }
    }

    dfs(0,0);

    for(auto iter = answer.begin(); iter != answer.end(); iter++){
        cout << *iter << "\n";
    }

    return 0;
}