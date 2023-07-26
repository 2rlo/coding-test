// 백준 20546 기적의 매매법

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cash, temp;
    vector<int> stock(14);

    cin >> cash;

    int bnp, timing, bnp_stock = 0, timing_stock = 0;
    bnp = cash;
    timing = cash;

    for(int i=0; i<14; i++){
        cin >> temp;
        stock[i] = temp;
    }

    for(int i=0; i<stock.size(); i++){
        if(stock[i] <= bnp){
            while(bnp-stock[i] >= 0){
                bnp -= stock[i];
                bnp_stock++;
            }
            if(bnp < 0){
                bnp = 0;
            }
        }

        if(stock[i] > stock[i+1]){
            if(stock[i+1] > stock[i+2]){
                    while(timing-stock[i+3] > 0){
                        timing -= stock[i+3];
                        timing_stock++;
                }
                if(timing < 0){
                    timing = 0;
                }
            }
        }

        if(timing_stock > 0){
            if(stock[i] < stock[i+1]){
                if(stock[i+1] < stock[i+2]){
                        timing = timing + (stock[i+3] * timing_stock);
                        timing_stock=0;
                }
            }
        }
    }

    int b = bnp + (bnp_stock*stock.back());
    int t = timing + (timing_stock*stock.back());

    if(b > t){
        cout << "BNP";
    }
    else if (t > b){
        cout << "TIMING";
    }
    else if (t == b){
        cout << "SAMESAME";
    }

    return 0;
}