class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> q;
        q.push(1);     //將1推入佇列中，因為1是第一個超級醜數
        int x = 0;
        while (n--) {     //while迴圈遍歷前n個超級醜數
            x = q.top();     //取出佇列中的最小元素x=當前的超級醜數
            q.pop();
            for (int& k : primes) {
                if (x <= INT_MAX / k) {     
                    q.push(k * x);
                    //對於每個質數k如果k*x不會溢出整數範圍，就將k*x推入佇列
                }
                if (x % k == 0) {
                    break;
                    //如果x可以被某個質數k整除，就跳出內層迴圈
                    //因為後續的質數乘以x得到的結果一定會大於x
                }
            }
        }
        return x;
        //返回x，也就是第n個超級醜數
    }
};