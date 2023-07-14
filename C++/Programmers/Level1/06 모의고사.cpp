#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int p1[] = {1,2,3,4,5};
    int p2[] = {2,1,2,3,2,4,2,5};
    int p3[] = {3,3,1,1,2,2,4,4,5,5};

    int res1 = 0;
    int res2 = 0;
    int res3 = 0;
    
    if(answers[0] == p1[0]){
        res1++;
    }
    if (answers[0] == p2[0]){
        res2++;
    }
    if (answers[0] == p3[0]){
        res3++;
    }

    for(int i=1; i<answers.size(); i++){
        if(answers[i] == p1[i%5])
            res1++;
        if (answers[i] == p2[i%8])
            res2++;
        if (answers[i] == p3[i%10])
            res3++;
    }

    int m = max({res1, res2, res3});
    if (m == res1) answer.push_back(1);
    if (m == res2) answer.push_back(2);
    if (m == res3) answer.push_back(3);
    

    return answer;
}