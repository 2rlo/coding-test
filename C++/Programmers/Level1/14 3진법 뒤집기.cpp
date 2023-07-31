#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int position = 0;
    vector<int> ternary;

    while(n>0){
        ternary.push_back(n%3);
        n = n / 3;
    }
    
    for(int i=ternary.size()-1; i>=0; i--){
        answer += ternary[i] * pow(3, position);
        position++;
    }

    return answer;
}