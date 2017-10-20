// 535. Encode and Decode TinyURL

// Note: This is a companion problem to the System Design problem: Design TinyURL.
// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

// Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.


class Solution {
public:
    Solution(){
        dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        short2long.clear();
        long2short.clear();
        srand(time(NULL));
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(long2short.count(longUrl)){
            return "http://tinyurl.com/" + long2short[longUrl];
        }

        int index = 0;
        string key;
        for(int i=0; i<6; i++){
            key.push_back(dict[rand()%62]);
        }
        while(short2long.count(key)){ // this key is already used
            key[index] = dict[rand() % 62];
            index = (index + 1) % 6;
        }
        short2long[key] = longUrl;
        long2short[longUrl] = key;
        return "http://tinyurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string key = shortUrl.substr(shortUrl.find_last_of("/")+1);
        return short2long.count(key) ? short2long[key] : shortUrl;
    }
private:
    unordered_map<string,string> short2long, long2short;
    string dict;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));