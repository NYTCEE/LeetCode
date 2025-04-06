class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while (!urlToCode.count(longUrl)) {
        //如果longUrl尚未被編碼（不在urlToCode映射中），則繼續迴圈
            string code;     //宣告一個空字串code，用於儲存新生成的短碼
            for (int i = 0; i < 6; ++i)      //生成一6字元的隨機短碼
            code += alphabets[rand() % alphabets.size()];
            if (!codeToUrl.count(code)) {     //如果生成的code尚未被使用（不在codeToUrl映射中）
                codeToUrl[code] = longUrl;     //將code映射到longUrl
                urlToCode[longUrl] = code;     //將longUrl映射到code
                return "http://tinyurl.com/" + code;     //回傳完整的短URL
            }
        }
        
        throw;//如果無法生成唯一的code（幾乎不可能發生），拋出異常
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return codeToUrl[shortUrl.substr(19)];     //提取shortUrl中的code部分（跳過 "http://tinyurl.com/"）
    }
    private:
    const string alphabets =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    //定義一個包含所有可能字元的字串
    unordered_map<string, string> urlToCode;
    //使用無序映射（哈希表）儲存長URL到code的映射(key是長URL，value是對應的code)
    unordered_map<string, string> codeToUrl;
    //使用無序映射（哈希表）儲存code到長URL的映射(key是code，value是對應的長URL)
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));