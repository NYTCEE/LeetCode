/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};
      //檢查根節點是否為空
      //如果是，返回一個空的二維向量
    vector<vector<int>> ans;
    //定義ans二維整數向量，用來儲存每一層的節點值
    queue<TreeNode*> q;
    q.push(root);
    //又可寫成queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      vector<int> currLevel;
      //定義currLevel，用來儲存當前層的節點值
      for (int sz = q.size(); sz > 0; --sz) {     //遍歷當前層的所有節點
        TreeNode* node = q.front();
        q.pop();     //取出佇列的前端節點並將其移出佇列
        currLevel.push_back(node->val);     //將當前節點的值加到currLevel向量中
        if (node->left)
          q.push(node->left);     //如果當前節點有左子節點，將左子節點加入佇列
        if (node->right)
          q.push(node->right);     //如果當前節點有右子節點，將右子節點加入佇列
      }
      ans.push_back(currLevel);     //將當前層的節點值currLevel加到結果ans中
    }

    return ans;     //回傳ans(按層級排序的所有節點值)
  }
};