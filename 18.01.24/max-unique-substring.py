class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lp = 0
        rp = 0
        maxLen = 0
        d = {}

        while (rp < len(s)):
            if s[rp] not in d:
                d[s[rp]] = rp
            else:
                lp = max(lp, d[s[rp]] + 1)
                d[s[rp]] = rp
            maxLen = max(maxLen, rp - lp + 1)
            rp += 1
        return maxLen
