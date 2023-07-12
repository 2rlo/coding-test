function solution(board, moves) {
  var answer = 0;

  var basket;
  var spin = 0;

  for (let i = 0; i < moves.length; i++) {
    var index = moves[i] - 1;
    spin = 0;
    for (let j = 0; j < board.length; j++) {
      if (board[j][index] != 0 && spin == 0) {
        if (basket.length != 0) {
          if (board[j][index] == basket[basket.length - 1]) {
            answer = answer + 2;
            basket.pop();
          } else if (board[j][index] != basket[basket.length - 1]) {
            basket.push(board[j][index]);
          }
        } else if (basket.length == 0) {
          basket.push(board[j][index]);
        }
        board[j][index] = 0;
        spin = 1;
      }
    }
  }
  return answer;
}
