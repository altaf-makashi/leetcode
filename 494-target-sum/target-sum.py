class Solution:
    @cache
    def fun(self,nums:tuple[int],target:int,index:int)->int:
        if(index<0):
            return 1 if target==0 else 0
        
        add=self.fun(nums,target+nums[index],index-1)
        sub=self.fun(nums,target-nums[index],index-1)

        return add+sub

    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        n=len(nums)
        return self.fun(tuple(nums),target,n-1)
        