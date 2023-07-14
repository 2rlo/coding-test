function solution(answers) {
  var answer = [];

  var p1 = [1, 2, 3, 4, 5];
  var p2 = [2, 1, 2, 3, 2, 4, 2, 5];
  var p3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

  var res1 = 0;
  var res2 = 0;
  var res3 = 0;

  if (answers[0] == p1[0]) res1++;
  if (answers[0] == p2[0]) res2++;
  if (answers[0] == p3[0]) res3++;

  for (let i = 1; i < answers.length; i++) {
    if (answers[i] == p1[i % 5]) res1++;
    if (answers[i] == p2[i % 8]) res2++;
    if (answers[i] == p3[i % 10]) res3++;
  }

  const m = Math.max(res1, res2, res3);
  if (m == res1) answer.push(1);
  if (m == res2) answer.push(2);
  if (m == res3) answer.push(3);

  return answer;
}
