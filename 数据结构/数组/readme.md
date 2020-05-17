## leetcode题目
### [1.整数反转](https://leetcode-cn.com/problems/reverse-integer/)
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
示例1：
```
输入: 123
输出: 321
```
示例2：
```
输入: -123
输出: -321
```
示例3:
```
输入: 120
输出: 21
```
注意：
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

_思路:_
* 注意根据范围判定是否溢出
* 2^31 − 1最后一位为7，2^31最后一位为8
```cpp
class Solution {
public:
    int reverse(int x) {
        int min=INT_MIN;
        int max=INT_MAX;
        int result = 0;
        while(x != 0)
        {
            int a = x%10;  
            x = x/10;
            if(result > max/10 || (result == max/10 && a>7)){
                return 0;
            }
            if(result < min/10 || (result == min/10 && a<-8)){
                return 0;
            }
            result = result * 10 + a;
        }
        return result;
    }
};
```

### [2.两数之和](https://leetcode-cn.com/problems/two-sum/)
给定一个整数数组 ```nums``` 和一个目标值 ```target```，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:
```
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

_思路：_
* 直接遍历即可
* O（n^2）
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(auto i = 0; i < nums.size() - 1; ++i)
        {
            for(auto j = i+1; j < nums.size(); ++j)
            {
                if((nums[i] + nums[j]) == target)
                {
                    return {i,j};
                }
            }
        }
        return{};
    }
};
```