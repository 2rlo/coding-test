function solution(numbers, hand) {
  var answer = "";

  let left_position = 10;
  let right_position = 11;

  let left_index = 0;
  let middle_index = 0;
  let right_index = 0;

  const left = [1, 4, 7, 10];
  const middle = [2, 5, 8, 0];
  const right = [3, 6, 9, 11];

  for (let i = 0; i < numbers.length; i++) {
    if (middle.indexOf(numbers[i]) != -1)
      middle_index = middle.indexOf(numbers[i]);

    if (left.indexOf(left_position) == -1) {
      if (middle.indexOf(left_position) != -1)
        left_index = middle.indexOf(left_position);
    } else {
      left_index = left.indexOf(left_position);
    }

    if (right.indexOf(right_position) == -1) {
      if (middle.indexOf(right_position) != -1)
        right_index = middle.indexOf(right_position);
    } else {
      right_index = right.indexOf(right_position);
    }

    if (left.indexOf(numbers[i]) != -1) {
      left_position = numbers[i];
      answer = answer + "L";
    } else if (right.indexOf(numbers[i]) != -1) {
      right_position = numbers[i];
      answer = answer + "R";
    } else if (
      middle.indexOf(left_position) != -1 &&
      middle.indexOf(right_position) != -1
    ) {
      if (
        Math.abs(middle_index - left_index) ==
        Math.abs(middle_index - right_index)
      ) {
        if (hand == "left") {
          left_position = numbers[i];
          answer = answer + "L";
        } else {
          right_position = numbers[i];
          answer = answer + "R";
        }
      } else if (
        Math.abs(middle_index - left_index) >
        Math.abs(middle_index - right_index)
      ) {
        right_position = numbers[i];
        answer = answer + "R";
      } else {
        left_position = numbers[i];
        answer = answer + "L";
      }
    } else if (
      middle.indexOf(left_position) != -1 &&
      middle.indexOf(right_position) == -1
    ) {
      if (
        Math.abs(middle_index - left_index) ==
        Math.abs(middle_index - right_index) + 1
      ) {
        if (hand == "left") {
          left_position = numbers[i];
          answer = answer + "L";
        } else {
          right_position = numbers[i];
          answer = answer + "R";
        }
      } else if (
        Math.abs(middle_index - left_index) >
        Math.abs(middle_index - right_index) + 1
      ) {
        right_position = numbers[i];
        answer = answer + "R";
      } else {
        left_position = numbers[i];
        answer = answer + "L";
      }
    } else if (
      middle.indexOf(left_position) == -1 &&
      middle.indexOf(right_position) != -1
    ) {
      if (
        Math.abs(middle_index - left_index) + 1 ==
        Math.abs(middle_index - right_index)
      ) {
        if (hand == "left") {
          left_position = numbers[i];
          answer = answer + "L";
        } else {
          right_position = numbers[i];
          answer = answer + "R";
        }
      } else if (
        Math.abs(middle_index - left_index) + 1 >
        Math.abs(middle_index - right_index)
      ) {
        right_position = numbers[i];
        answer = answer + "R";
      } else {
        left_position = numbers[i];
        answer = answer + "L";
      }
    } else {
      if (
        Math.abs(middle_index - left_index) + 1 ==
        Math.abs(middle_index - right_index) + 1
      ) {
        if (hand == "left") {
          left_position = numbers[i];
          answer = answer + "L";
        } else {
          right_position = numbers[i];
          answer = answer + "R";
        }
      } else if (
        Math.abs(middle_index - left_index) + 1 >
        Math.abs(middle_index - right_index) + 1
      ) {
        right_position = numbers[i];
        answer = answer + "R";
      } else {
        left_position = numbers[i];
        answer = answer + "L";
      }
    }
  }
  return answer;
}

/*
[1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"

L
R 3
L 4
L4 R3 index L1 R0 M1 Length L1 R2
*/
