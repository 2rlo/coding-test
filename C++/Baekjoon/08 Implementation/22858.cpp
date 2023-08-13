// 백준 22858 원상 복구 (small)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, k;
    long long temp;

    cin >> n >> k;

    vector<long long> s;
    vector<long long> d;
    vector<long long> answer(n);

    for(int i=0; i<n; i++){
        cin >> temp;
        s.push_back(temp);
    }

    for(int i=0; i<n; i++){
        cin >> temp;
        d.push_back(temp);
    }

    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            answer[d[j]-1] = s[j]; 
        }
        s = answer;
    }

    for(int i=0; i<n; i++){
        cout << answer[i] << ' ';
    }

    return 0;
}