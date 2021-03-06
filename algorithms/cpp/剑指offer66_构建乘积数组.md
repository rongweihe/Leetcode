所以对于这道题，更好的解法应该是这样的：

 1、先算出 B[i] = A[0] * ...A[i-1]。

 2、接着算 B[i] = A[i+1]...A[n-1] * Bi 

代码如下

```c++
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size(), right = 1;
        std::vector<int> b(len, 1);//定义一个输出数组   
        for(int i=1; i<len; ++i) { b[i] = b[i-1] *a[i-1]; }//此时B[i]记录i左边的乘积,B[0] = 1
        for(int i=len-2; i>=0; --i) { 
            right *= a[i+1];//right记录i右边的乘积
            b[i] *= right; //结果 = 左边乘积*右边乘积
        }
        return b;
    }
};
//更高级解法 只用一个for循环
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();//[1234]
        vector<int> res(len,1);
        int left = 1;
        int right = 1;
        for(int i = 0; i<len; i++){ 
             //左半部分
            res[i] *= left;
            left *= nums[i];
            // 右半部分
            res[len - i -1] *= right;
            right *= nums[len - i -1];
        }
        return res;
    }
};
```

