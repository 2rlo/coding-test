#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    // d = 신청한 금액
    // budget = 예산

    int answer = 0;
    int allotment = 0;
    sort(d.begin(), d.end());

    for(int i=0; i<d.size(); i++){
        if(allotment + d[i] <= budget){
            allotment += d[i];
            answer++;
            d[i] = 0;
        }
    }
    
    return answer;
}