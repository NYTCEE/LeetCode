class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<>> minHeap;
    //宣告一個 priority_queue（優先佇列）
    //priority_queue：資料預設由大到小排序
    //greater<> :比較器，greater表示小的元素有更高的優先級
    for (const int num : nums) {     //遍歷nums中的每個元素
      minHeap.push(num);     //將當前元素num推入
      if (minHeap.size() > k)     
      //如果堆的大小超過k就彈出堆頂元素（最小的元素）
        minHeap.pop();
        //確保堆中始終只保留nums中最大的k個元素
    }

    return minHeap.top();
    //回傳堆頂元素，即第k大的元素
  }
};