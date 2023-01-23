#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<stdint.h>
#include<pthread.h>

#define DHT11 1
#define MQ3 2
#define MQ5 3
#define MQ6 4
#define ALARM 4


#define test 1
#define verbose 0



static void gpio_init(int8_t pin);
static void gpio_set_direction(int8_t pin, char *direction);
static void gpio_set_value_to_port(int8_t pin, int8_t value);
static int gpio_get_value_from_port(int8_t pin);
static void gpio_close(int8_t pin);
static void clean_terminate(int signum);
static void *check_dht11(void *ptr);
static void *check_mq3(void *ptr);
static void *check_mq5(void *ptr);
static void *check_mq6(void *ptr);
static void sound_alarm();


pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;


static void *check_dht11(void *ptr)
{
while(1)
{
printf("in dht11\n");
if(gpio_get_value_from_port(DHT11)==1)
{
printf("dht11-high\n");
sound_alarm();

}
sleep(5);
}
}


static void *check_mq3(void *ptr)
{
while(1)
{
printf("in mq3\n");
if(gpio_get_value_from_port(MQ3)==1)
{
printf("mq-3-high\n");
sound_alarm();
}
sleep(5);
}

}

static void *check_mq5(void *ptr)
{
while(1)
{
printf("in mq5\n");
if(gpio_get_value_from_port(MQ5)==1)
{
printf("mq-5-high\n");
sound_alarm();
}
sleep(5);
}

}

static void *check_mq6(void *ptr)
{
while(1)
{
printf("in mq6\n");
if(gpio_get_value_from_port(MQ6)==1)
{
printf("mq6-high\n");
sound_alarm();

}
sleep(5);
}
}

static void sound_alarm()
{
gpio_set_value_to_port(ALARM,1);
}


int8_t main(void)
{

pthread_t thread1, thread2,thread3,thread4;

(void)gpio_set_direction(DHT11,"in");
(void)gpio_set_direction(MQ3,"in");
(void)gpio_set_direction(MQ5,"in");
(void)gpio_set_direction(MQ6,"in");
(void)gpio_set_direction(ALARM,"out");

	pthread_create( &thread1, NULL, check_dht11, "none");
	pthread_create( &thread2, NULL, check_mq3, "none");
	pthread_create( &thread3, NULL, check_mq5, "none");
	pthread_create( &thread4, NULL, check_mq6, "none");


	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL); 
	pthread_join( thread3, NULL); 
	pthread_join( thread4, NULL); 
	
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


static int gpio_get_value_from_port(int8_t pin)
{

//if(verbose==1)
//{
//(void)printf("getting the value for the pin %d \n",pin);
//}



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
(void)gpio_close(DHT11);
(void)gpio_close(MQ3);
(void)gpio_close(MQ5);
(void)gpio_close(MQ6);
(void)gpio_close(ALARM);
(void)exit(1);
}
