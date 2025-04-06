class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        // citations代表學者的論文引用次數
        int len = citations.size();
        // citations的長度存在len中
        std::sort(citations.begin(), citations.end(), std::greater<int>());
        // 對citations陣列進行降序排列
        // std::greater<int>()確保陣列元素按從大到小的順序排列

        for (int i = 0; i < len; ++i) {
            if (citations[i] <= i) {
                // citations[i]表示第i+1篇論文的引用次數
                // 如果citations[i]小於或等於i
                // 等同於學者有i篇論文，每篇至少被引用了i次
                return i;
                // i為h-index，回傳i
            }
        }
        return len;
        // 如果循環結束後還沒有返回，說明所有論文的引用次數都大於它們的索引
        // 在這種情況下，h-index為論文總數len
    }
};
