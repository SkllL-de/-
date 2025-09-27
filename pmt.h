#include<vector>
#include<string>
std::vector<int> computeLPSArray(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0); // 初始化LPS数组，所有元素为0

    int len = 0; // len是前一个最长前缀后缀的长度，也是当前需要比较的字符的索引
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            // 字符匹配成功，LPS值为len+1
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // 字符匹配失败，但我们可以利用之前的LPS信息
                // 让len回溯到lps[len-1]，而不是直接清零
                len = lps[len - 1];
            } else {
                // len为0，无法再回溯，说明没有公共前缀后缀
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
