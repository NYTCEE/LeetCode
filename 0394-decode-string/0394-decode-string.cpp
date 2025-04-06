class Solution {
 public:
  string decodeString(string s) {
    stack<pair<string, int>> stack;     // (prevStr, repeatCount)
    string currStr;     //儲存當前正在解碼的字串
    int currNum = 0;     //儲存當前的重複次數

    for (const char c : s)
      if (isdigit(c)) {     //判斷當前字符c是不是數字
        currNum = currNum * 10 + (c - '0');
        //如果是數字，將它加到currNum上
      } 
      else {
        if (c == '[') {     
          //模式開始
          //將當前的currStr和currNum推入stack
          stack.emplace(currStr, currNum);
          currStr = "";     //重置currStr
          currNum = 0;     //重置currNum
        } 
        else if (c == ']') {
          //模式結束
          //從stack的top取出之前的字串prevStr和重複次數n
          const auto [prevStr, n] = stack.top();
          stack.pop();
          currStr = prevStr + getRepeatedStr(currStr, n);
          //使用getRepeatedStr函數將當前的currStr重複n次
          //並將結果與prevStr連接，賦值給新的currStr
        } 
        else {
          currStr += c;
          //如果當前字符c是普通字符，直接加到currStr上
        }
      }

    return currStr;
    //回傳currStr(解碼後的字串)
  }

 private:
  // Returns s * n.
  string getRepeatedStr(const string& s, int n) {
    string repeat;     //創建一個空字串repeat，用於存放重複後的結果字串
    while (n--)
      repeat += s;     //將字串s連接到repeat的末尾
    return repeat;     //repeat=重複n次後的結果
  }
};