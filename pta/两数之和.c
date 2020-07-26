#include<stdio.h>
#include<stdlib.h>
/* Note:The returned array must be malloced,assmue caller calls free().
*////给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数
///，并返回他们的数组下标。///
int*twosum(int *nums,int numsize,int target,int*returnsize)
{
    int *ret=(int *)malloc(2*sizeof(int));
    int temp;
    for(int i=0;i<numsize-1;i++)
    {
        temp=target-nums[i];
        for(int j=i+1;j<numsize;j++)
        {
            if(nums[j]==temp)
            {
                *ret=i;
                *(ret+1)=j;
                *returnsize=2;
                return ret;
            }
        }
    }
    return 0;
}