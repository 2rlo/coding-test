function solution(a, b) {
    var answer = '';
    
    var month = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    var day = ["THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"];

    var num = 0;

    for(var i=1; i<a; i++){
        num += month[i];
    }

    num += b;
    answer = day[num%7];

    return answer;
}