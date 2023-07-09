#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int left_position = 10;
    int right_position = 11;

    int left_index = 0;
    int middle_index = 0;
    int right_index = 0;

    vector<int> left = {1, 4, 7, 10};
    vector<int> middle = {2, 5, 8, 0};
    vector<int> right = {3, 6, 9, 11};

    for(int i=0; i<numbers.size(); i++){
        middle_index = find(middle.begin(), middle.end(), numbers[i]) - middle.begin();
        
        if(find(left.begin(), left.end(), left_position) == left.end()){
            left_index = find(middle.begin(), middle.end(), left_position) - middle.begin();
        }else {
            left_index = find(left.begin(), left.end(), left_position) - left.begin();
        }

        if(find(right.begin(), right.end(), right_position) == right.end()){
            right_index = find(middle.begin(), middle.end(), right_position) - middle.begin();
        }
        else {
            right_index = find(right.begin(), right.end(), right_position) - right.begin();
        }

        // 1, 4, 7
        if(find(left.begin(), left.end(), numbers[i])!=left.end()){
            left_position = numbers[i];
            answer.append("L");
        }
        // 3, 6, 9
        else if(find(right.begin(), right.end(), numbers[i])!=right.end()){
            right_position = numbers[i];
            answer.append("R");
        }
        else if (find(middle.begin(), middle.end(), left_position)!=middle.end() && find(middle.begin(), middle.end(), right_position)!=middle.end()){
            if(abs(middle_index-left_index) == abs(middle_index-right_index)){
                if(hand.compare("left")){
                    right_position = numbers[i];
                    answer.append("R");
                }
                else {
                    left_position = numbers[i];
                    answer.append("L");
                }
            }
            else if (abs(middle_index-left_index) > abs(middle_index-right_index)){
                right_position = numbers[i];
                answer.append("R");
            }
            else {
                left_position = numbers[i];
                answer.append("L");
            }
        }
        else if (find(middle.begin(), middle.end(), left_position)!=middle.end() && find(middle.begin(), middle.end(), right_position)==middle.end()){
            if(abs(middle_index-left_index)==abs(middle_index-right_index)+1){
                if(hand.compare("left")){
                    right_position = numbers[i];
                    answer.append("R");
                }
                else {
                    left_position = numbers[i];
                    answer.append("L");
                }
            }
            else if (abs(middle_index-left_index)>abs(middle_index-right_index)+1){
                right_position = numbers[i];
                answer.append("R");
            }
            else {
                left_position = numbers[i];
                answer.append("L");
            }
        }
        else if (find(middle.begin(), middle.end(), left_position)==middle.end() && find(middle.begin(), middle.end(), right_position)!=middle.end()){
            if(abs(middle_index-left_index)+1==abs(middle_index-right_index)){
                if(hand.compare("left")){
                    right_position = numbers[i];
                    answer.append("R");
                }
                else {
                    left_position = numbers[i];
                    answer.append("L");
                }
            }
            else if (abs(middle_index-left_index)+1>abs(middle_index-right_index)){
                right_position = numbers[i];
                answer.append("R");
            }
            else {
                left_position = numbers[i];
                answer.append("L");
            }
        }
        else {
            if (abs(middle_index-left_index)+1 == abs(middle_index-right_index)+1){
                if(hand.compare("left")){
                    right_position = numbers[i];
                    answer.append("R");
                }
                else if (hand.compare("right")){
                    left_position = numbers[i];
                    answer.append("L");
                }
            }
            else if(abs(middle_index-left_index)+1 > abs(middle_index-right_index)+1){
                right_position = numbers[i];
                answer.append("R");
            }
            else {
                left_position = numbers[i];
                answer.append("L");
            }
        }
    }

    return answer;
}
