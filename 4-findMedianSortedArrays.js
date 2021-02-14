nums1 = [1,3,5,6,8,9];
nums2 = [2,4,7];

var findMedianSortedArrays = function(nums1, nums2) {
    var high = nums1.length-1;
    var low = 0;
    var mid;
    for(var i = 0;i < nums2.length;i++){
        while(low <= high) {
            mid = Math.floor((high+low)/2);
            if(nums2[i] > nums1[mid]){
                low = mid + 1;
            }
            if(nums2[i] < nums1[mid]){
                high = mid - 1;
            }
            if(nums2[i] == nums1[mid]){
                //找到了就加在后面
                nums1.splice(mid,0,nums2[i]);
            }
            //没找到，
            else{
                if(nums2[i] > nums1[mid]){
                    nums1.splice(mid+1,0,nums2[i]);
                }
                else{
                    nums1.splice(mid-1,0,nums2[i]);
                }

            }


        }
    }
    
};
findMedianSortedArrays(nums1,nums2);
console.log(nums2);
console.log(nums1);
