class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0
        for i in collections.Counter(s).itervalues():
            res += i/2*2
            if res%2 == 0 and i%2==1:
                res += 1
        return res
