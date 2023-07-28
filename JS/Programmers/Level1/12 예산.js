function solution(d, budget) {
  var answer = 0;

  var allotment = 0;
  d.sort((a, b) => a - b);

  for (var i = 0; i < d.length; i++) {
    if (allotment + d[i] <= budget) {
      allotment += d[i];
      answer++;
      d[i] = 0;
    }
  }

  return answer;
}
