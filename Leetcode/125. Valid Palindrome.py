class Solution(object):
    def isPalindrome(self, s):
        x = ''
        for i in s:
            if(i>='a' and i<='z') or (i>='A' and i<='Z') or (i>='0' and i<='9'):
                x += i.lower()
        if(x == x[::-1]):
            return True
        return False
