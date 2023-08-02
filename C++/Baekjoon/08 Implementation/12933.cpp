// 백준 12933 오리

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> d;

bool sol(char ch){
    if (d.empty()){
        if(ch == 'q'){
            d.push_back("q");
            return false;
        }
    }
    else {
        if(ch == 'q'){
            for(int i=d.size()-1; i>=0; i--){
                if(d[i].length()%5==0){
                    d[i].push_back(ch);
                    return false;
                }
                else {
                    d.push_back("q");
                }
            }
        }
        else if (ch == 'u'){
            for(int i=d.size()-1; i>=0; i--){
                if(d[i].length()%5==1){
                    d[i].push_back(ch);
                    return false;
                }
            }
        }
        else if (ch == 'a'){
            for(int i=d.size()-1; i>=0; i--){
                if(d[i].length()%5==2){
                    d[i].push_back(ch);
                    return false;
                }
            }
        }
        else if (ch == 'c'){
            for(int i=d.size()-1; i>=0; i--){
                if(d[i].length()%5 == 3){
                    d[i].push_back(ch);
                    return false;
                }
            }
        }
        else if (ch == 'k'){
            for(int i=d.size()-1; i>=0; i--){
                if(d[i].length()%5 == 4){
                    d[i].push_back(ch);
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string sound;

    cin >> sound;
    
    for(int i=0; i<sound.length(); i++){
        if(sol(sound[i]) == true){
            cout << "-1";
            return 0;
        }
    }

    cout << d.size();

    return 0;
}