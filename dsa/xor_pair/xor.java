class Solution {
    public int numIdenticalPairs(int[] nums) {
        int i=0,j=1,c=0;
        while(i<nums.length-1&&j<nums.length)
        {
            if((nums[i]^nums[j])>(nums[i]&nums[j]))
            c++;
            if(j==nums.length-1)
            {
                i++;
                j=i+1;
            }
            else
            j++;
        }
        return c;
    }
}
