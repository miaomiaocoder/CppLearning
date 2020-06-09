## leetcode题目
### [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 ```[0,1,2,4,5,6,7]``` 可能变为 ```[4,5,6,7,0,1,2]``` )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:
```
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
```
示例 2:
```
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
```

_思路:_
* 套用二分查找框架
* 判断2种情况， 数组前半部分是有序数组， 或者数组后半部分是有序数组时候的情况
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while(start <= end){
            mid = start + (end - start) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[start] <= nums[mid]){
                if(nums[mid] > target && nums[start] <= target){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }else{
                if(nums[end] >= target && nums[mid] < target){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
```
### [81. 搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 ```[0,0,1,2,2,5,6]``` 可能变为 ```[2,5,6,0,0,1,2]``` )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:
```
输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
```
示例 2:
```
输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
```
_思路:_
* 套用二分查找框架
* 判断2种情况， 数组前半部分是有序数组， 或者数组后半部分是有序数组时候的情况
* 处理重复元素情况
```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while(start <= end){
            mid = start + (end - start) / 2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[start] == nums[mid]){
                start++;
                continue;
            }
            if(nums[start] <= nums[mid]){
                if(nums[mid] > target && nums[start] <= target){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }else{
                if(nums[end] >= target && nums[mid] < target){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};
```
