#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int prime[3001] = {0, };

    prime[0] = 1;
    prime[1] = 1;

    for(int i=2; i<3001; i++){
        if(prime[i]==0){
            for(int j=i*2; j<3001; j+=i){
                prime[j] = 1;
            }
        }
    }

    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            for(int k=j+1; k<nums.size(); k++){
                if(prime[nums[i]+nums[j]+nums[k]]==0) {
                    answer++;
                }
            }
        }
    }

    return answer;
}