class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0;
        stack<int> st;
        for(auto c : s){
            if(c == '('){
                st.push(res);
                //如果c是左括號"("，將目前的res值推入堆疊st
                res = 0;
                //將res重置為0
                //(遇到左括號代表開始計算新的子字串的分數)
            }
            else{
                if(res == 0){
                    res = 1 + st.top();
                    //如果res為0，代表這個右括號前面是一個空字串
                    //空字串的分數為1，所以將res設為1加上堆疊st頂部的值(之前推入堆疊的分數)
                }
                else{
                    res = res * 2 + st.top();
                    //如果res不為0，代表這個右括號前面是一個非空字串
                    //所以將res乘以2，再加上堆疊st頂部的值
                }

                st.pop();
                //最後從堆疊st中彈出頂部元素
            }
        }
        return res;
        //回傳最終的分數res
    }
};