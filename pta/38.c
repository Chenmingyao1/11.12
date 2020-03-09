#include<stdio.h>
struct Stu_Info
{
	char name[20];
	char no[10];
	float chinese;
	float math;
	float english;
	float ave;
};
int main()
{
	float sum = 0, ave;
	int n, i;
	scanf("%d", &n);
	struct Stu_Info stu[10];
	for (i = 0; i < n; i++)
	{
		printf("please input  %d  student",i+1);
		scanf("%s", stu[i].no);
		scanf("%s", stu[i].name);
		scanf("%f", &stu[i].chinese);
		scanf("%f", &stu[i].math);
		scanf("%f", &stu[i].english);
		sum = stu[i].chinese + stu[i].math + stu[i].english;
		stu[i].ave = sum / 3;
	}
	int max_index = 0;
	for (i = 1; i < n; i++)
	{
		if (stu[i].ave > stu[max_index].ave)
			max_index = i;
	}
	printf("maxname=%s,maxave=%.1f", stu[max_index].name, stu[max_index].ave);
	return 0;
}