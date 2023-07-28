function solution(new_id) {
  let answer;

  new_id = new_id.toLowerCase();

  new_id = new_id.replace(/[^\w\-\.]/g, "");

  new_id = new_id.replace(/\.+/g, ".");

  new_id = new_id.replace(/^\.|\.$/g, "");

  if (new_id.length == 0) {
    new_id += "a";
  }

  new_id = new_id.slice(0, 15);
  new_id = new_id.replace(/\.$/, "");

  while (new_id.length < 3) {
    new_id += new_id[new_id.length - 1];
  }

  answer = new_id;

  return answer;
}
