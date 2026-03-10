class Solution:
    def maxOfSubarrays(self, arr, k):
        # code here
        final=[]
        for i in range(len(arr)-k+1):
            sub=[]
            count=0
            while(count<k):
                sub.append(arr[i+count])
                count+=1
            x=max(sub)
            final.append(x)
        return final
