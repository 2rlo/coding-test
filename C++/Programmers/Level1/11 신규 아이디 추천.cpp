#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for(int i=0; i<new_id.size(); i++){
        if(isupper(new_id[i]) != 0){
            new_id[i] = tolower(new_id[i]);
        }
    }

    for(int i=0; i<new_id.size(); i++){
        if(islower(new_id[i]) == 0&&isdigit(new_id[i]) == 0&&new_id[i]!='-'&&new_id[i]!='_'&&new_id[i]!='.'){
            new_id.erase(i, 1);
            i--;
        }
    }

    for(int i=0; i<new_id.size()-1; i++){
        if(new_id[i]=='.' && new_id[i+1]=='.'){
            new_id.erase(i, 1);
            i--;
        }
    }

    if(new_id.front()=='.'){
            new_id.erase(0, 1);
        }

    if(new_id.back()=='.'){
            new_id.pop_back();
    }
        
    if(new_id.empty()){
            new_id += 'a';
    }
        
    if(new_id.size() > 15){
        new_id = new_id.substr(0, 15);
        if(new_id.back()=='.'){
            new_id.pop_back();
        }
    }
        
    while(new_id.size() < 3){
        new_id += new_id.back();
    }

    answer = new_id;

    return answer;
}