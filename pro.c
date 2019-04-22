#include<pthread.h>
#include<stdio.h>
void *fun1();
void *fun2();
int shared1=20;
int shared2=10; //shared variable
//pthread_mutex_t l; //mutex lock
int main()
{
//pthread_mutex_init(&l, NULL); //initializing mutex locks
pthread_t thread1, thread2;
pthread_create(&thread1, NULL, fun1, NULL);
pthread_create(&thread2, NULL, fun2, NULL);
pthread_join(thread1, NULL);
pthread_join(thread2,NULL);

}

void *fun1()
{
    int x,y;
   // pthread_mutex_lock(&l); 
    
    x=shared2; 
    sleep(1); 
    shared1=x; 
    printf("Final value of shared1 is %d\n",shared1);
    //pthread_mutex_unlock(&l);
}

void *fun2()
{
    int y;
   // pthread_mutex_lock(&l);
    y=shared1; 
    sleep(1);
    shared2=y; 
    printf("Final value of shared2 is %d\n",shared2);
   // pthread_mutex_unlock(&l);
}

