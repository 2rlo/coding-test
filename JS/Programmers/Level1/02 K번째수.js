// programmers K번째수

function solution(array, commands) {
    var answer = [];

    for(var i=0; i<commands.length; i++){
        var slice = array.slice(commands[i][0]-1, commands[i][1]);
        slice.sort((a,b) => a-b);
        answer.push(slice[commands[i][2]-1]);
    }
    return answer;
}