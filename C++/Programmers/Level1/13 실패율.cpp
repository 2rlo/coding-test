#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, float> a, pair<int, float> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else {
        return a.second > b.second;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<pair<int, float>> percentage;
    float deno = 0, numerator = 0;
    float per = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<stages.size(); j++){
            if(stages[j] >= i+1){
                deno++;
            }
            if(stages[j] == i+1){
                numerator++;
            }
        }
        if(deno == 0){
            per = 0;
        }
        else {
            per = numerator / deno;
            numerator = 0;
            deno = 0;
        }
        percentage.push_back({i+1, per});
    }

    sort(percentage.begin(), percentage.end(), compare);

    for(int i=0; i<N; i++){
        answer.push_back(percentage[i].first);
    }

    return answer;
}
