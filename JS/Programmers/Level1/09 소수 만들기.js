function solution(nums) {
    var answer = 0;
    var prime = new Array(3001);

    prime[0] = 1;
    prime[1] = 1;

    for(var i=2; i<3001; i++){
        if(prime[i] == undefined){
            for(j = i*2; j<3001; j+=i){
                prime[j] = 1;
            }
        }
    }

    for(var i=0; i<nums.length; i++){
        for(var j=i+1; j<nums.length; j++){
            for(var k=j+1; k<nums.length; k++){
                if(prime[nums[i]+nums[j]+nums[k]] == undefined)
                    answer++;
            }
        }
    }

    return answer;
}