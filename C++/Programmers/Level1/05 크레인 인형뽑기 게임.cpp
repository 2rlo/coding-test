#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> basket;
    int spin = 0;

    for(int i=0; i<moves.size(); i++){
        int index = moves[i]-1;
        spin = 0;
        for(int j=0; j<board.size(); j++){
            if(board[j][index]!=0 && spin == 0){
                if(!basket.empty()){
                    if(board[j][index] == basket.back()){
                        answer = answer + 2;
                        basket.pop_back();
                    }
                    else if (board[j][index] != basket.back()){
                        basket.push_back(board[j][index]);
                    }
                }
                else if (basket.empty()){
                    basket.push_back(board[j][index]);
                }
            board[j][index] = 0;
            spin = 1;
            }
        }
    }

    return answer;
}