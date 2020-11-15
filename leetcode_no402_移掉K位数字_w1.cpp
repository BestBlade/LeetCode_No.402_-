/* ------------------------------------------------------------------|
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-k-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：7 MB, 在所有 C++ 提交中击败了51.70%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string removeKdigits(string num, int k) {
    if (k >= num.size()) {
        return "0";
    }
    int len = num.size() - k;
    string res;
    for (int i = 0; i < num.size(); i++) {
        while (k && res.size() && res.back() > num[i]) {
            res.pop_back();
            k--;
        }
        res.push_back(num[i]);
    }
    res.resize(len);

    while (res[0] == '0') {
        res.erase(res.begin());
    }

    return (res.size() != 0) ? res : "0";
}

int main() {
    string num = "10";
    int k = 1;

    cout << removeKdigits(num, k) << endl;
}
