#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";

    int month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

    int num = 0;

    for(int i=1; i<a; i++){
        num += month[i];
    }

    num += b;
    answer = day[num%7];

    return answer;
}