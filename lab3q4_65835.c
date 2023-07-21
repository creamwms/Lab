#include<stdio.h>
int main(){
	int cnt=0;
	int sum=0;
	int a=1;
	int num;
	float avg=0;
	while(a>0){
		printf("enter number : ");
		scanf("%d",&num);
		if(num<=0){
			break;
		}
		sum += num;
		cnt++;
	}
	printf("sum = %d\n",sum);
	avg = (float)sum/cnt;
	printf("avg = %.4f\n",avg);
	return 0;
}
