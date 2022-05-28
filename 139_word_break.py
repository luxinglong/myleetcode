# -*- coding: utf-8 -*-

"""
Example:
Input: s = “leetcode”, wordDict=[”leet”, “code”]
Ouput: True
"""

from typing import List


def wordBreak(s: str, wordDict: List[str]) -> bool:
    # "leetcode" ["leet", "code"]
    # dp[i] 表示s[0: i+1]子串能否被表示
    # dp[i] = True, dp[i-j]=True and s[i-j: i+1] in wordDict
    # leetcode
    #012345678
    n = len(s)
    dp = [True] + [False] * n
    for i in range(1, n+1, 1):
        for word in wordDict:
            if i < len(word): continue
            if dp[i-len(word)] and s[i-len(word): i] == word:
                dp[i] = True
    return dp[n]


if __name__ == "__main__":
    s = "leetcode"
    wordDict = ["leet", "code"]
    print(wordBreak(s, wordDict))