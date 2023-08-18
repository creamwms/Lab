#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int csum = 0;
int msum = 0;
void *runner(void *param);

int main(int argc, char *argv[]){
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_create(&tid, &attr, runner, argv[1]);

	//pthread_join(tid, NULL);

	for(int i=0;i<=atoi(argv[1]);i++){
		msum += i;
	}
	printf("msum = %d\n", msum);
	printf("difference csum and msum %d\n", (csum-msum));
	return 0;

}

void *runner(void *param){
	int upper = atoi(param);
	for(int i=1;i<=upper*2;i++){
		csum += i;
	}
	printf("csum = %d\n", csum);
	pthread_exit(0);
}
