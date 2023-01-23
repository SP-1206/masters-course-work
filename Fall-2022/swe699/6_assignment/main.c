#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<stdint.h>
#include<pthread.h>
#include <sched.h>
#include<limits.h>


#define RED 44
#define GREEN 26
#define START_STOP_BUTTON 67
#define RESET_BUTTON 68
//#define RED 1
//#define GREEN 2
//#define START_STOP_BUTTON 3
//#define RESET_BUTTON 4

#define test 1
#define verbose 0


int watchdog=0;
long glob_timer_a=0;
int flag=0;


static void gpio_init(int8_t pin);
static void gpio_set_direction(int8_t pin, char *direction);
static void gpio_set_value_to_port(int8_t pin, int8_t value);
static int8_t gpio_get_value_from_port(int8_t pin);
static void gpio_close(int8_t pin);
static void clean_terminate(int signum);
static void *thisTimer();
static void *check_start_stop_button();
static void *check_reset_button();


pthread_t thread1, thread2,thread3;
pthread_attr_t timer_thread,start_stop_thread,reset_thread;
struct sched_param start_stop_priority, reset_priority, timer_thread_priority;



//min=1 max=99





void run_timer();
void pause_timer();

static void *check_start_stop_button()
{




if( gpio_get_value_from_port(START_STOP_BUTTON)==1)
{

if(flag==1)
{
	pause_timer();


}

if(flag==0)
{
	run_timer();



}

}




}


 


static void *check_reset_button()
{
while(1)
{
if(gpio_get_value_from_port(RESET_BUTTON)==1)
{
glob_timer_a=0;
sched_yield();
continue;
}

}

}



static void *thisTimer(void *ptr)
{


	while(1)
	{




		
		//sleep(0.001);
		while(flag)
		{

		usleep(10000); // milliseconds
						if(glob_timer_a == LONG_MAX)
						glob_timer_a=0;
		glob_timer_a=glob_timer_a+10; //milliseconds
		pthread_create( &thread2, &start_stop_thread, check_start_stop_button, (void *) "");
		if(glob_timer_a%100==0)
		printf("%ld %ld %ld %ld\n",(((glob_timer_a/1000)/60)/60),((glob_timer_a/1000)/60)%60,(glob_timer_a/1000)%60,glob_timer_a%1000);
		sched_yield();

	}


}
}

int8_t main(void)
{
gpio_set_direction(RED, "out");
gpio_set_direction(GREEN, "out");
gpio_set_value_to_port(RED,1);
gpio_set_value_to_port(GREEN,0);
pthread_attr_init(&timer_thread);
pthread_attr_init(&start_stop_thread);
pthread_attr_init(&reset_thread);
reset_priority.sched_priority = 45;
start_stop_priority.sched_priority = 35;
timer_thread_priority.sched_priority = 99;
pthread_attr_setschedparam (&start_stop_thread, &start_stop_priority);
pthread_attr_setschedparam (&reset_thread, &reset_priority);
pthread_attr_setschedparam (&timer_thread, &timer_thread_priority);



pthread_create( &thread1, &timer_thread, thisTimer, (void *) "");



pthread_create( &thread3, &reset_thread, check_reset_button, (void *) "");




pthread_join( thread1, NULL);
pthread_join( thread2, NULL);	
pthread_join( thread3, NULL);	

	

(void)signal(SIGINT,clean_terminate);

}

void run_timer()
{
gpio_set_value_to_port(GREEN,1);
printf("in the run timer\n");
gpio_set_value_to_port(RED,0);
flag = 1;

}

void pause_timer()
{
printf("in the pause timer\n");
gpio_set_value_to_port(RED,1);
gpio_set_value_to_port(GREEN,0);
flag = 0;
}



/********interact with GPIO pin using sys interface****************/


static void gpio_init(int8_t pin)
{
//sysfs - 
// open /sys/class/gpio/export to write
// write the pin number to the file

if(verbose==1) 
{
 (void)printf("exporting pin %d\n",pin);
}


     FILE *fp;
     fp = fopen("/sys/class/gpio/export", "w");
 
     if(test==1)
     {
     fp = fopen("./test/export", "w");
     }
     


     if (fp== NULL)
     {
          (void)printf("func: gpio_init \t err:error opening file \t pin: %d\n",pin);
          (void)exit(0);
     }

     if(fprintf(fp, "%d", pin)<0)
     {
     (void)printf("func: gpio_init \t err:error writing to file \t pin: %d\n",pin);
     (void)exit(0);
     }
     
     
     (void)fclose(fp);



}


//set the input or output?
//should be written in direction file under the directory
static void gpio_set_direction(int8_t pin, char *direction)
{

if(verbose==1)
{
(void)printf("setting the direction to %s for the pin %d\n",direction,pin);
}
else
{
;
}


//open /sys/class/gpio/gpio<pin>/direction to write
//write the value to the file - in/out
char path[150];

if(test==1) 
{
(void)sprintf(path,"./test/gpio%d/direction",pin);
}
else 
{
(void)sprintf(path,"/sys/class/gpio/gpio%d/direction",pin);
}


     FILE *fp;
     fp = fopen(path, "w");


     if (fp== NULL)
     {
          (void)printf("func: gpio_set_direction \t err:error opening file \t pin: %d\n",pin);
          (void)exit(0);
     }

     if(fprintf(fp, "%s", direction)<0)
     {
     (void)printf("func: gpio_set_direction \t err:error writing to file \t pin: %d\n",pin);
     (void)exit(0);
     }
     

     (void)fclose(fp);

}




static void gpio_set_value_to_port(int8_t pin, int8_t value)
{
if(verbose==1)
{
(void)printf("setting the value for the pin %d to %d\n",pin,value);
}



char path[150];

if(test==1)
{
(void)sprintf(path,"./test/gpio%d/value",pin);
}
else
{
(void)sprintf(path,"/sys/class/gpio/gpio%d/value",pin);
}


     FILE *fp;
     fp = fopen(path, "w");


     if(fp== NULL)
     {
          (void)printf("func: gpio_set_value_to_port \t err:error opening file \t pin: %d\n",pin);
     }

     if(fprintf(fp, "%d", value)<0)
     {
     (void)printf("func: gpio_set_value_to_port \t err:error writing to file \t pin: %d\n",pin);
     (void)exit(0);
     }
     

     (void)fclose(fp);

}


static void gpio_close(int8_t pin)
{
if(verbose==1) 
{
(void)printf("unexporting pin %d\n",pin);
}


     FILE *fp;
     fp = fopen("/sys/class/gpio/unexport", "w");
if(test==1) 
{
fp = fopen("./test/unexport", "w");
}


     if (fp== NULL)
     {
          (void)printf("func: gpio_close \t err:error opening file \t pin: %d\n",pin);
     }

     if(fprintf(fp, "%d", pin)<0)
     {
     (void)printf("func: gpio_close \t err:error writing to file \t pin: %d\n",pin);
     exit(0);
     }
     

     (void)fclose(fp);



}




static int8_t gpio_get_value_from_port(int8_t pin)
{

if(verbose==1)
{
(void)printf("getting the value for the pin %d \n",pin);
}



char path[150];

if(test==1)
{
(void)sprintf(path,"./test/gpio%d/value",pin);
}
else
{
(void)sprintf(path,"/sys/class/gpio/gpio%d/value",pin);
}

 FILE *fp;
   int c;
   int n = 0;
  
   fp = fopen(path,"r");
   if(fp == NULL) {
      (void)printf("func: gpio_get_value_from_port \t err:error opening file \t pin: %d\n",pin);
   }
      c = fgetc(fp);


fclose(fp);
if(c=='0')
return 0;
else
return 1;
  
}


static void clean_terminate(int signum)
{
  if(verbose==1)
  {
  (void)printf("received signal %d",signum);
  }
(void)gpio_close(RED);
(void)gpio_close(GREEN);
(void)gpio_close(START_STOP_BUTTON);
(void)gpio_close(RESET_BUTTON);
(void)exit(1);
}
