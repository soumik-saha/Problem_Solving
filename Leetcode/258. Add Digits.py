class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        x = 0
        # num = str(num)
        num = [(i) for i in str(num)]
        n = len(num)
        print(n)
        while(n!=1):
            for i in range(n):
                x = x + int(num[i])
            num = str(x)
            x = 0
            num = [(i) for i in str(num)]

            n = len(num)
        num = ''.join(num)
        return int(num)
