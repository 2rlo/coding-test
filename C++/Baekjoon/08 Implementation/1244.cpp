// 백준 1244 스위치 켜고 끄기

#include <iostream>
#include <vector>
using namespace std;

int n;
int button[101] = {0,};
vector<pair<int, int>> num;

void sol(){
    for(int i=0; i<num.size(); i++){
        if(num[i].first == 1){
            for(int j=0; j<n; j++){
                if((j+1)%num[i].second == 0){
                    if(button[j] == 1){
                        button[j] = 0;
                    }
                    else if (button[j] == 0){
                        button[j] = 1;
                    }
                }
            }
        }
        else if (num[i].first == 2){
             if(button[num[i].second-1] == 0){
                    button[num[i].second-1] = 1;
                }
                else if (button[num[i].second-1] == 1){
                    button[num[i].second-1] = 0;
                }
            for(int j=1; num[i].second+j-1 < n && num[i].second-j-1 >= 0; j++){ 
                if(button[num[i].second+j-1] == button[num[i].second-j-1]){
                    if(button[num[i].second+j-1] == 0){
                        button[num[i].second+j-1] = 1;
                        button[num[i].second-j-1] = 1;
                    }
                    else {
                        button[num[i].second+j-1] = 0;
                        button[num[i].second-j-1] = 0;
                    }
                }
                else break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int student, gender, number;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> button[i];
    }

    cin >> student;

    for(int i=0; i<student; i++){
        cin >> gender;
        cin >> number;
        num.push_back({gender, number});
    }
        
    sol();

    int blank = 0;

    for(int i=0; i<n; i++){
        cout << button[i] << ' ';
        blank++;
        if(blank == 20){
            cout << '\n';
            blank = 0;
        }    
    }

    return 0;
}