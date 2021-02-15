var left = [3,4,6,7];
var right = [1,2,5,8];
var arr = [];
var L = 0;
var M = 4;
var R = 7;

var merge = function(arr,L,M,R){
    var left_size = M-L;
    var right_size = R-M+1;
    // for(var i = L; i < M; i++){
    //     arr[i] = left[i-L];

    // }

    // for(var i = M; i <= R; i++){
    //     arr[i] = right[i-M];

    // }

    var a = 0;//left
    var b = 0;//right
    var c = 0;//arr  


    while(a < left_size && b < right_size){
        if(left[a] < right[b]){
            arr[c] = left[a];
            a++;
            c++;
        }

        else{
            arr[c] = right[b];
            c++;
            b++;

        }
    }

    while(a < left_size){
        arr[c] = left[a];
        a++;
        c++;
    }
    
    while(b < right_size){
        arr[c] = right[b];
        b++;
        c++;
    }
}

merge(arr,L,M,R);
var mid;
//奇数
if((arr.length % 2) != 0){
    mid = arr[(arr.length-1)/2];
}else{
    mid = (arr[arr.length/2]+arr[arr.length/2-1])/2;
}
console.log(mid);
