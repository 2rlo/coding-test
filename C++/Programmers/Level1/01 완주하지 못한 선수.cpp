// programmers 완주하지 못한 선수

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    bool pick = false;

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i=0; i<completion.size(); i++){
        if(participant[i] != completion[i]){
            answer = participant[i];
            pick = true;
            break;
        }
    }

    if(pick == false){
        answer = participant.back();
    }

    return answer;
}