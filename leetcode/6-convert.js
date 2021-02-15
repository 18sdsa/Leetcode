var s = "PAYPALISHIRING";
var numRows = 3;

/**
 * 
 * @param {*} s 
 * @param {*} numRows 
 */
var convert = function(s, numRows) {
    var index;
    var step = 2*numRows-2;//第0行和第n行的间距
    var res = "";
    for(var i = 0; i < numRows; i++) {
        var index = i;
        var add = 2 * i;
        while(index < s.length) {
            res = res + s[index];
            add = step - add;
            if(i == 0 || i == numRows-1) {
                index = index + step;
            }else{
                index = index + add;
            }
        }
    }
    return res;
};

console.log(convert(s,numRows))