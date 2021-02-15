var x = -123;
var int_max = 2147483647;
var int_min = -2147483647;
var reverse = function(x) {
    var q = 1;
    if(x < 0) {
        x = -x;
        q = -1;
    }
    var sum = 0;
    while(x) {
        sum = sum * 10 + x % 10;
        x = Math.floor(x / 10);

    } 
    if(sum > int_max || sum < int_min) {
        return 0;
    }else{
        if(q > 0) {
            return sum;
        }else{
            return -sum;
        }
        
    }
    
};
console.log(reverse(x));