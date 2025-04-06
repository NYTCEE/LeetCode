class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {     //接受字串向量words的引用(預設)
    vector<string> ans;     //宣告字串向量ans儲存結果
    vector<int> commonCount(26, INT_MAX);     //宣告一個大小為26的整數向量commonCount，初始化所有元素為INT_MAX（整數的最大值）

    for (const string& word : words) {     //for迴圈遍歷words中的每個字串，const string& 避免拷貝，提高效率
      vector<int> count(26);     //宣告長度26字元計數向量
      for (const char c : word)     //遍歷當前字串的每個字元
        ++count[c - 'a'];     //c - 'a'可以得出數字(0~25)，將'a'-'z'映射到0~25
      for (int i = 0; i < 26; ++i)     //長度26
        commonCount[i] = min(commonCount[i], count[i]);     
        //兩者取較小值，又因commonCount[i]為整數的最大值，所以等於取count[i](min是C++標準庫函數)，存進commonCount[i]
    }

    for (char c = 'a'; c <= 'z'; ++c)     //遍歷所有小寫字母
      for (int i = 0; i < commonCount[c - 'a']; ++i)     //若陣列不為空，則執行下列程式
        ans.push_back(string(1, c));     //將當前字母作為一個長度為1的字串添加到ans中

    return ans;     //返回結果向量，包含所有在每個輸入字串中都出現的字元
  }
};