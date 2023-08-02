// 백준 1913 달팽이

#include <iostream>
using namespace std;

int n, target;

void input(){
    cin >> n >> target;
}

void sol(){
    int map[1000][1000];
    int num = n * n;
    int right = n-1;
    int up = n-1;
    int left = 0;
    int down = 0;
    int count = 0;
    bool d1 = false;
    bool d2 = false;
    int x=0, y=0;

    for(int i=0; i<n; i++){
        map[i][0] = num;
        num--;
    }
    down++;

    int db = n - 1;

    while(num!=0){
        if(count % 2 == 0 && count != 0){
            db = db - 1;
        }

        if(db%2 == 0 && d1 == false) {
            // 오른쪽
            for(int i=down; i<db+down; i++){
                map[right][i] = num;
                num--;
            }
            right--;
            d1 = true;
            count++;
        }
        else if(db%2 == 0 && d1 == true){
            // 위
            for(int i=right; i>=left; i--){
                map[i][up] = num;
                num--;
            }
            up--;
            d1 = false;
            count++;            
        }
        else if(db%2 == 1 && d2 == false && db != 1){
            // 왼쪽
            for(int i=right; i>=down; i--){
                map[left][i] = num;
                num--;
            }
            left++;
            d2 = true;
            count++;
        }
        else if(db%2 == 1 && d2 == true && db != 1){
            for(int i=left; i<db+left; i++){
                map[i][down] = num;
                num--;
            }
            down++;
            d2 = false;
            count++;
        }
        else if(db == 1 && d2 == false){
            map[((n-1)/2)-1][(n-1)/2] = num;
            num--;
            d2 = true;
            left++;
            count++;
        }
        else if(db == 1 && d2 == true){
            map[(n-1)/2][(n-1)/2] = num;
            num--;
            d2 = false;
            down++;
            count++;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << ' ';
            if(map[i][j] == target){
                x = i+1;
                y = j+1;
            }
        }
        cout << '\n'; 
    }

    cout << x << ' ' << y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    sol();

    return 0;
}