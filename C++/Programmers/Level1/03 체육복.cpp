#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> new_lost, new_reserve;

    // 겹치는 번호가 없어야 새로운 배열에 추가
    for(int i=0; i<lost.size(); i++){
        if(find(reserve.begin(), reserve.end(), lost[i])==reserve.end()){
            new_lost.push_back(lost[i]);
        }
    }

    for(int i=0; i<reserve.size(); i++){
        if(find(lost.begin(), lost.end(), reserve[i])==lost.end()){
            new_reserve.push_back(reserve[i]);
        }
    }

    lost = new_lost;
    reserve = new_reserve;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    answer = n - lost.size();

    for(int i=0; i<lost.size(); i++){
        if((find(reserve.begin(), reserve.end(), lost[i]-1) != reserve.end()) && (find(lost.begin(), lost.end(), lost[i]-1) == lost.end())){
            answer++;
            reserve.erase(remove(reserve.begin(), reserve.end(), lost[i]-1), reserve.end());            
        }
        else if ((find(reserve.begin(), reserve.end(), lost[i]+1) != reserve.end()) && (find(lost.begin(), lost.end(), lost[i]+1) == lost.end())){
            answer++;
            reserve.erase(remove(reserve.begin(), reserve.end(), lost[i]+1), reserve.end());
        }
    }

    return answer;
}