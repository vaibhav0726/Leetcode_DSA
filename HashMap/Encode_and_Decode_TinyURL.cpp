// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl 
// and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

class Solution {
public:
    unordered_map<string, string> codeDB, urlDB;
    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    string getCode() {
        string code = "";
        for (int i = 0; i < 6; i++) code += chars[rand() % 62];
        return "http://tinyurl.com/" + code;
    }
    
    string encode(string longUrl) {
        if (urlDB.find(longUrl) != urlDB.end()) return urlDB[longUrl];
        string code = getCode();
        while (codeDB.find(code) != codeDB.end()) code = getCode();
        codeDB[code] = longUrl;
        urlDB[longUrl] = code;
        return code;
    }

    string decode(string shortUrl) {
        return codeDB[shortUrl];
    }
};
