var s = "pwwkesadasfasfajkfhkashfhdskjfhjsadfgsduagfusdgfygsdifgsiufhudhFIHfhouahfdhfluhsadfhsadifhlsaudhlsdhglsahglsahgasdhgshdglsdghslghslhgw";

var lengthOfLongestSubstring = function(s) {
    var set = new Set();
    var i = 0;
    var j = 0;
    var maxLength = 0;
    if(s.length === 0){
        return 0;
    }

    for(i;i < s.length;i++){
        if(!set.has(s[i])){
            set.add(s[i]);
            maxLength = Math.max(maxLength,set.size);
        }else{
            while(set.has(s[i])){
                set.delete(s[j]);
                j++;
            }
            set.add(s[i]);
        }
    }

    return maxLength;
};

console.log(lengthOfLongestSubstring(s));
