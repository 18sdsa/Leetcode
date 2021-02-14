var s = "cabbad";
var arr;
var maxLength = 0;
var longestPalindrome = function(s) {
    var left;
    var right;

    for(var i = 0; i < s.length; i++) {
        left =i;
        right = i + 1;
        while(left >= 0 && right < s.length && s[left] === s[right]) {
            left--;
            right++;

        }
        left = left + 1;
        right = right - 1;
        if((right - left + 1) >= maxLength) {//更新
            maxLength = right - left + 1;
            // for(var j = 0; j < maxLength; j++) {
            //     arr[j] = s[left];
            //     left++;
            // }
            arr = s.substring(left,maxLength+left);
        }
    }


    for(var i = 0; i < s.length; i++) {
        left = i;
        right = i;
        while(left >= 0 && right < s.length && s[left] === s[right]) {
            left--;
            right++;

        }
        left = left + 1;
        right = right - 1;
        if((right - left + 1) >= maxLength) {//更新
            maxLength = right - left + 1;
            // for(var j = 0; j < maxLength; j++) {
            //     arr[j] = s[left];
            //     left++;
            // }
            arr = s.substring(left,maxLength+left);
        }
    }

  

    return arr;
};

longestPalindrome(s);
// console.log(arr.substring(0,arr.length-1));
console.log(arr);