#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int num = 0;
    int zero = 0;

    for(int i=0; i<lottos.size(); i++){
        if(lottos[i] == 0){
            zero++;
        }
        else if(find(win_nums.begin(), win_nums.end(), lottos[i])!=win_nums.end())
            num++;
    }

    switch (zero+num)
    {
    case 1: answer.push_back(6);
        break;
    case 2: answer.push_back(5);
        break;
    case 3: answer.push_back(4);
        break;
    case 4: answer.push_back(3);
        break;;
    case 5: answer.push_back(2);
        break;
    case 6: answer.push_back(1);
        break;
    default:
        answer.push_back(6);
        break;
    }

    switch(num){
    case 1: answer.push_back(6);
        break;
    case 2: answer.push_back(5);
        break;
    case 3: answer.push_back(4);
        break;
    case 4: answer.push_back(3);
        break;;
    case 5: answer.push_back(2);
        break;
    case 6: answer.push_back(1);
        break;
    default:
        answer.push_back(6);
        break;
    }


    return answer;
}