function solution(n, lost, reserve) {
  var answer = 0;

  let new_lost = new Array();
  let new_reserve = new Array();

  for (let i = 0; i < lost.length; i++) {
    if (reserve.indexOf(lost[i]) == -1) new_lost.push(lost[i]);
  }

  for (let i = 0; i < reserve.length; i++) {
    if (lost.indexOf(reserve[i]) == -1) new_reserve.push(reserve[i]);
  }

  new_lost.sort((a, b) => a - b);
  new_reserve.sort((a, b) => a - b);

  answer = n - new_lost.length;

  for (let i = 0; i < new_lost.length; i++) {
    if (
      new_reserve.includes(new_lost[i] - 1) == true &&
      new_lost.includes(new_lost[i] - 1) == false
    ) {
      answer++;
      new_reserve.splice(new_reserve.indexOf(new_lost[i] - 1), 1);
    } else if (
      new_reserve.includes(new_lost[i] + 1) == true &&
      new_lost.includes(new_lost[i] + 1) == false
    ) {
      answer++;
      new_reserve.splice(new_reserve.indexOf(new_lost[i] + 1), 1);
    }
  }

  return answer;
}
