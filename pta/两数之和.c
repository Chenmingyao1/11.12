#include<stdio.h>
#include<stdlib.h>
/* Note:The returned array must be malloced,assmue caller calls free().
*////����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ����
///�����������ǵ������±ꡣ///
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