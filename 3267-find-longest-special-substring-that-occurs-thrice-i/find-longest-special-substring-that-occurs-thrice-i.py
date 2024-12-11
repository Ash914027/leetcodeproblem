class Solution:
    def maximumLength(self, s: str) -> int:
        res = -1
        for c in {*s}:
            l = [*nlargest(3,map(len,findall(c+'+',s))),0,0]
            res = max(res, l[0]-2, l[1]-(l[0]==l[1]), l[2])

        return res or -1