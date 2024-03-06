#include <iostream>
#include <unordered_map>
#include <string>

/* 力扣 387 */
class Solution {
public:
    int firstUniqChar(std::string s) {
        if (s.empty())
        {
            return -1;
        }

        std::unordered_map<char, int> charCount;
        // 统计每个字符出现的次数
        for (char c : s) {
            charCount[c]++;
        }

        // 找到第一个不重复的字符并返回其索引
        for (int i = 0; i < s.length(); ++i) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }

        return -1; // 如果不存在不重复的字符，则返回 -1
    }
};

#if 0     
/* 哈希的三种键值对插入方式 */
int main() {
    std::unordered_map<std::string, int> myMap;

    // 向哈希表中插入键值对
    myMap.insert(std::make_pair("apple", 5));
    myMap.insert({"banana", 10});
    myMap["orange"] = 3;

    // 遍历哈希表并输出键值对
    for (auto it : myMap) {
        std::cout << "Key: " << it.first << ", Value: " << it.second << std::endl;
    }

    return 0;
}

#endif