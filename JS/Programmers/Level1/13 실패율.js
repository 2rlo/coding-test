function solution(N, stages) {
  var answer = [];

  var percentage = [];
  var deno = 0;
  var numerator = 0;
  var per = 0;

  for (var i = 0; i < N; i++) {
    for (var j = 0; j < stages.length; j++) {
      if (stages[j] >= i + 1) {
        deno++;
      }
      if (stages[j] == i + 1) {
        numerator++;
      }
    }
    if (deno == 0) {
      per = 0;
    } else {
      per = numerator / deno;
      numerator = 0;
      deno = 0;
    }
    percentage.push([i + 1, per]);
  }

  answer = percentage.sort((a, b) => b[1] - a[1]);
  return answer.map((x) => x[0]);
}
