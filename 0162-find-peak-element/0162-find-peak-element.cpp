class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int l = 0;      //定義變數l(左邊界)並初始化為0，即陣列的起始索引
    int r = nums.size() - 1;     //定義變數r(右邊界)並初始化為陣列的最後一個元素的索引
    while (l < r) {     //while迴圈，當l小於r時，繼續迴圈
      const int m = (l + r) / 2;     //計算l和r的中點索引，存在m中
      if (nums[m] >= nums[m + 1])     
       //如果中點元素大於或等於其右邊的元素，說明峰值在左半部分(包括中點)，所以將r設為m
        r = m;
      else
        l = m + 1;     //否則峰值在右半部分，將l設為m + 1
    }

    return l;     //當l等於r時迴圈結束，此時l(也就是r)就是峰值元素的索引
  }
};
