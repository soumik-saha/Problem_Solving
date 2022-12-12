class Solution:
    def climbStairs(self, n):
        prev=1
        crnt=1
        for i in range(2,n+1):
            res=prev+crnt
            prev=crnt
            crnt=res
        return crnt
