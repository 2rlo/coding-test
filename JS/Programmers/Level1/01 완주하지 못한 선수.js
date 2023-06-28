// programmers 완주하지 못한 선수
function solution(participant, completion) {
    var answer = '';
    var pick = false;

    participant.sort();
    completion.sort();

    for(var i=0; i<completion.length; i++){
        if(participant[i] != completion[i]){
            answer = participant[i];
            pick = true;
            break;
        }
    }

    if(pick == false){
        answer = participant.pop();
    }
    return answer;
}
