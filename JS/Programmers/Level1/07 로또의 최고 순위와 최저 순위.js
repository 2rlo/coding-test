function solution(lottos, win_nums) {
  var answer = [];

  var num = 0;
  var zero = 0;

  for (var i = 0; i < lottos.length; i++) {
    if (lottos[i] == 0) {
      zero++;
    } else if (win_nums.includes(lottos[i]) == true) {
      num++;
    }
  }

  switch (zero + num) {
    case 1:
      answer.push(6);
      break;
    case 2:
      answer.push(5);
      break;
    case 3:
      answer.push(4);
      break;
    case 4:
      answer.push(3);
      break;
    case 5:
      answer.push(2);
      break;
    case 6:
      answer.push(1);
      break;
    default:
      answer.push(6);
      break;
  }

  switch (num) {
    case 1:
      answer.push(6);
      break;
    case 2:
      answer.push(5);
      break;
    case 3:
      answer.push(4);
      break;
    case 4:
      answer.push(3);
      break;
    case 5:
      answer.push(2);
      break;
    case 6:
      answer.push(1);
      break;
    default:
      answer.push(6);
      break;
  }

  return answer;
}
