class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        istringstream iss(path);
        // 使用istringstream將路徑字串path按/分割為多個子目錄名
        vector<string> stack;
        for (string dir; getline(iss, dir, '/');) {
            // 宣告了名為dir的字串變數，用於儲存每次讀取的子字串
            // getline函數從iss中讀取一個子字串，並將其存儲到dir中
            //'/' 指定了分隔符,表示讀取的子字串是以/字元分隔
            // 如果path是/home/user/documents，那麼這個迴圈將依次把dir賦值為空字串、"home"、"user"和"documents"
            if (dir.empty() || dir == ".")
                continue;
            // 如果dir為空或.則直接忽略
            if (dir == "..") {
                // 如果dir為..表示回到上一層目錄
                if (!stack.empty()) // 判斷stack是否為空
                    stack.pop_back();
                // 從stack中彈出最後一個元素
            } else {
                stack.push_back(dir);
                // 將dir推入stack
            }
        }

        for (const string& s : stack) // 遍歷stack中的元素
            ans += "/" + s;
        // 將stack中的元素加上"/"連接到ans字串中
        return ans.empty() ? "/" : ans;
        // 如果ans為空字串，則返回單個/字符(根據Unix路徑命名規則，單個/表示根目錄)
        // 否則直接返回ans字串
    }
};