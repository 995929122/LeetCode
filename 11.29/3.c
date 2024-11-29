//给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

// 示例 1:

// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 示例 2:

// 输入: s = "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:

// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


#include <stdio.h>
#include <stdbool.h>
int lengthOfLongestSubstring(char* s) {
    int ans = 0, left = 0;
    bool has[128] = {};
    for (int right = 0; s[right]; right++) 
    {
        char c = s[right];
        while (has[c]) 
        { // 窗口内有 c
        has[s[left]] = false;
        left++; // 缩小窗口
        }
        has[c] = true;
        ans=ans>right-left+1?ans:right-left+1;
    }
    return ans;
}

//滑动窗口算法
//https://www.bilibili.com/video/BV1hd4y1r7Gq/?vd_source=0437aa3fbc324cf2cc3e7f8ca395e67c