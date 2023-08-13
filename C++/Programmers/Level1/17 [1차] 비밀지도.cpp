#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int l = 0;

    for(int i=0; i<n; i++){
        answer.push_back("");
        for(int bit=n-1; bit>=0; bit--){
            if((arr1[i]>>bit)&1 == 1 || (arr2[i]>>bit)&1 == 1){
                answer[i].push_back('#');
            }
            else{
                answer[i].push_back(' ');
            }
        }
    }

    return answer;
}