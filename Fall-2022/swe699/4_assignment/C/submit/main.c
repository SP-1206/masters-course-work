#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdint.h>
#include<pthread.h>

#define ZERO_RED 1
#define ZERO_GREEN 2
#define ZERO_YELLOW 3
#define ONE_RED 4
#define ONE_GREEN 5
#define ONE_YELLOW 6
#define ZERO_BUTTON 7
#define ONE_BUTTON 8
#define test 1
#define verbose 1

 struct signal_set_struct {
   int8_t gpio_pin_red; 
   int8_t gpio_pin_green;
   int8_t gpio_pin_yellow; 
   int8_t gpio_pin_wait;
   int8_t id;
} ;

int8_t glob_timer_a=1;

static void signal_green(struct signal_set_struct set);
static void signal_red(struct signal_set_struct set);
static void signal_yellow(struct signal_set_struct set);
static void signal_trasition_green_to_red(struct signal_set_struct set);
static void signal_transition_red_to_green(struct signal_set_struct set);

static void gpio_init(int8_t pin);
static void gpio_set_direction(int8_t pin, char *direction);
static void gpio_set_value_to_port(int8_t pin, int8_t value);
static int8_t gpio_get_value_from_port(int8_t pin);
static void gpio_close(int8_t pin);
static void *light_state_controller(void *ptr);
void *check_if_pressed(void *temp);

static struct signal_set_struct zero; 
static struct signal_set_struct one; 






void *check_if_pressed(void *temp)
{

pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
int8_t pin,temp_val;
int8_t msec = 0;
int32_t trigger = 5000; 
if(*(int8_t *)temp==1)
{
pin=one.gpio_pin_wait;
}
else
{
pin=zero.gpio_pin_wait;
}

(void)pthread_mutex_lock( &mutex2 );

  if(gpio_get_value_from_port(pin)==1)
  {

clock_t before = clock();

do {
if(gpio_get_value_from_port(pin)==1)
{
temp_val=1;
}
else
temp_val=0;
  clock_t difference = clock() - before;
  msec = difference * 1000 / CLOCKS_PER_SEC;
} while ( msec < trigger );

if(temp_val==1)	
{
glob_timer_a=0;
}
  }

   

(void)pthread_mutex_unlock( &mutex2 );
}

int8_t main(void)
{

zero.id=0;
one.id=1;
zero.gpio_pin_red=ZERO_RED;
zero.gpio_pin_green=ZERO_GREEN;
zero.gpio_pin_yellow=ZERO_YELLOW;
one.gpio_pin_red=ONE_RED;
one.gpio_pin_green=ONE_GREEN;
one.gpio_pin_yellow=ONE_YELLOW;
zero.gpio_pin_wait=ZERO_BUTTON;
one.gpio_pin_wait=ONE_BUTTON;
pthread_t thread1, thread2;




//In this case we are giving the output to the LED so the direction is set to out
(void)gpio_set_direction(zero.gpio_pin_red,"out");
(void)gpio_set_direction(zero.gpio_pin_green,"out");
(void)gpio_set_direction(zero.gpio_pin_yellow,"out");
(void)gpio_set_direction(one.gpio_pin_red,"out");
(void)gpio_set_direction(one.gpio_pin_green,"out");
(void)gpio_set_direction(one.gpio_pin_yellow,"out");

//initialise to red
(void)signal_red(zero);
(void)signal_red(one);


	while(1)
	{
	(void)pthread_create( &thread1, NULL, light_state_controller, (void*) &zero);
	(void)pthread_create( &thread2, NULL, light_state_controller, (void*) &one);
	(void)pthread_join( thread1, NULL);
	(void)pthread_join( thread2, NULL); 
	}
	return 1;

}


static void signal_green(struct signal_set_struct set)
{

(void)gpio_set_value_to_port(set.gpio_pin_yellow, 0);
(void)gpio_set_value_to_port(set.gpio_pin_red, 0);
(void)gpio_set_value_to_port(set.gpio_pin_green, 1);

if(verbose==1) 
  {
    (void)printf("setting the set %d to green\n",set.id);
  }

}


static void signal_red(struct signal_set_struct set)
{

(void)gpio_set_value_to_port( set.gpio_pin_yellow, 0);
(void)gpio_set_value_to_port( set.gpio_pin_red, 1);
(void)gpio_set_value_to_port( set.gpio_pin_green, 0);

if(verbose==1) 
  {
  (void)printf("setting the set %d to red\n",set.id);
  }

}


static void signal_yellow(struct signal_set_struct set)
{
(void)gpio_set_value_to_port( set.gpio_pin_yellow, 1);
(void)gpio_set_value_to_port( set.gpio_pin_red, 0);
(void)gpio_set_value_to_port( set.gpio_pin_green, 0);

if(verbose==1) 
  {
    (void)printf("setting the set %d to yellow\n",set.id);
  }
}


static void signal_trasition_green_to_red(struct signal_set_struct set)
{
(void)signal_yellow(set);
(void)sleep(5);
(void)signal_red(set);
}


static void signal_transition_red_to_green(struct signal_set_struct set)
{
(void)signal_green(set);
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

static void *light_state_controller(void *ptr)
{
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
(void)pthread_mutex_lock( &mutex1 );

pthread_t thread3;
int8_t ms = 0;
int32_t threshold = 60000; 
clock_t start = clock();
int8_t check;
int8_t to_send;
(void)signal_transition_red_to_green(*(struct signal_set_struct*)ptr);	
struct signal_set_struct temp=*(struct signal_set_struct*)ptr;
if(temp.id==1)
{
to_send=0;
}
else
{
to_send=1;
}

do {

(void)pthread_create( &thread3, NULL, check_if_pressed, (void*)&to_send);
	(void)pthread_join( thread3, NULL);

  clock_t diff = clock() - start;
  ms = diff * 1000 / CLOCKS_PER_SEC;
  check=ms-threshold;
}while (check && glob_timer_a); 
glob_timer_a=1;
(void)signal_trasition_green_to_red(*(struct signal_set_struct*)ptr);
(void)pthread_mutex_unlock( &mutex1 );

}



static int8_t gpio_get_value_from_port(int8_t pin)
{

int8_t ret_val;




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
   int8_t c;
   int8_t n = 0;
  
   fp = fopen(path,"r");
   if(fp == NULL)
    {
      (void)printf("func: gpio_get_value_from_port \t err:error opening file \t pin: %d\n",pin);
     }
    
    c = fgetc(fp);


(void)fclose(fp);
if(c=='0')
{
ret_val= 0;
}
else
{
ret_val= 1;
}
 return ret_val; 
}


