/// programmers K번째수
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int i=0; i<commands.size(); i++){
        vector<int> res(array.begin()+commands[i][0]-1, array.begin()+commands[i][1]);
        sort(res.begin(), res.end());
        answer.push_back(res.at(commands[i][2]-1));
    }
    return answer;
}