// 백준 2346 풍선 터뜨리기

#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp;

    cin >> n;
    deque<pair<int, int>> dq;

    for(int i=1; i<=n; i++){
        cin >> temp;
        dq.push_back({i, temp});
    }

    while(!dq.empty()){
        auto cur = dq.front();
        cout << cur.first << ' ';
        int nowNum = cur.second;
        dq.pop_front();

        if(nowNum>0){
            nowNum--;
            while(!nowNum == 0){
                dq.push_back(dq.front());
                dq.pop_front();
                nowNum--;
            }
        }else {
            while(!nowNum == 0){
                dq.push_front(dq.back());
                dq.pop_back();
                nowNum++;
            }        
        }
    }
    return 0;
}