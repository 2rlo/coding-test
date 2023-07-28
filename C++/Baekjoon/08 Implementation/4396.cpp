// 백준 4396 지뢰 찾기

#include <iostream>
using namespace std;

char mine[11][11];
char user[11][11];
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int n;

int sol(int x, int y, int res){
    for(int i=0; i<8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<n){
            if(mine[nx][ny]=='*') res++;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool exp = false;

    cin >> n;

    char res[11][11]; 

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mine[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> user[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(user[i][j] == 'x'){
                int temp = sol(i, j, 0);
                res[i][j] = temp + '0';
                if(mine[i][j] == '*'){
                   exp = true;
                }
            }
            else if (user[i][j] =='.'){
                res[i][j] = '.';
            }
        }
    }

    if(exp){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mine[i][j] == '*')
                    res[i][j] = '*';
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           cout << res[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}