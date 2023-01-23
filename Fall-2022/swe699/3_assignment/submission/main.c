/*This entire program could probably be split into multiple parts say a header file
another file with the function definition.
but since the project itself is very small we decided to put everything in a single C file
we have added comments to every block that we thought was necessary.
*/

/*global variables and structure definition and header files*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<stdint.h>

 struct signal_set_struct {
   int8_t gpio_pin_red; //red light of the signal
   int8_t gpio_pin_green; //green light of the signal
   int8_t gpio_pin_yellow; // yellow light of the signal
   int8_t id;
} ;

/*
Since we are using the sysfs interface to talk to multiple GPIO ports
and the way we do it is by basically write values into files.
So to test this locally I created a directory called test in this and created a bunch of files
that simulate how it might look
the test flag if set to 1 will only use the local "test" directory to emulate a signal
*/
static int8_t test=0; 
static int8_t verbose=1;

//function prototypes
static void signal_green(struct signal_set_struct set);
static void signal_red(struct signal_set_struct set);
static void signal_yellow(struct signal_set_struct set);
static void signal_trasition_green_to_red(struct signal_set_struct set);
static void signal_transition_red_to_green(struct signal_set_struct set);
./static void gpio_init(int8_t pin);
static void gpio_set_direction(int8_t pin, char *direction);
static void gpio_set_value_to_port(int8_t pin, int8_t value);
static void gpio_close(int8_t pin);
static void clean_terminate(int signum);

//declare these globally so as to allow signal handlers to unmount the pins after the loop terminates
static struct signal_set_struct zero; // signal 0
static struct signal_set_struct one; //signal 1


int8_t main(void)
{
(void)signal(SIGINT,clean_terminate);
if(test==1)
{
/*test assumes that the GPIO pin numbers are 1,2,3,4,5,6
make sure you create a new directory structure under "tests" directory if you want to change this
*/
zero.id=0;
one.id=1;
zero.gpio_pin_red=67;
zero.gpio_pin_green=44;
zero.gpio_pin_yellow=68;
one.gpio_pin_red=66;
one.gpio_pin_green=45;
one.gpio_pin_yellow=69;
}

//change this part to the exact pin numbers 
zero.id=0;
one.id=1;
zero.gpio_pin_red=67;
zero.gpio_pin_green=44;
zero.gpio_pin_yellow=68;

one.gpio_pin_red=66;
one.gpio_pin_green=45;
one.gpio_pin_yellow=69;

//initialise all pins on both the signal_sets
(void)gpio_init(zero.gpio_pin_red);
(void)gpio_init(zero.gpio_pin_green);
(void)gpio_init(zero.gpio_pin_yellow);

(void)gpio_init(one.gpio_pin_red);
(void)gpio_init(one.gpio_pin_green);
(void)gpio_init(one.gpio_pin_yellow);

//In this case we are giving the output to the LED so the direction is set to out
(void)gpio_set_direction(zero.gpio_pin_red,"out");
(void)gpio_set_direction(zero.gpio_pin_green,"out");
(void)gpio_set_direction(zero.gpio_pin_yellow,"out");
(void)gpio_set_direction(one.gpio_pin_red,"out");
(void)gpio_set_direction(one.gpio_pin_green,"out");
(void)gpio_set_direction(one.gpio_pin_yellow,"out");

	while(1)
	{
	//infinite loop that goes from g->r and r->g
	(void)signal_trasition_green_to_red(one);
	(void)sleep(2);
	(void)signal_transition_red_to_green(zero);
	(void)signal_trasition_green_to_red(zero);
	(void)sleep(2);
	(void)signal_transition_red_to_green(one);	
	}
return 1;

}


static void signal_green(struct signal_set_struct set)
{
//set the green signal to 1 and the rest to 0
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
//set the red signal to 1 and the rest to 0
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
//set the yellow signal to 1 and the rest to 0
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
// for green to red first transition to yellow sleep for 5 seconds and then transition to red
(void)signal_yellow(set);
(void)sleep(5);
(void)signal_red(set);
}


static void signal_transition_red_to_green(struct signal_set_struct set)
{
//transition to green and sleep for 2 mins
(void)signal_green(set);
(void)sleep(10);
}


/********interact with GPIO pin using sys interface****************/


//export pin
//thus making it available for use
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

//set output to high or low
static void gpio_set_value_to_port(int8_t pin, int8_t value)
{
if(verbose==1)
{
(void)printf("setting the value for the pin %d to %d\n",pin,value);
}


//open /sys/class/gpio/gpio<pin>/value to write
//write the value 0/1

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


//unexport..
static void gpio_close(int8_t pin)
{
if(verbose==1) 
{
(void)printf("unexporting pin %d\n",pin);
}

//open /sys/class/gpio/unexport to write
//write the pin number to file

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

//signal handler to trigger for SIGINT
static void clean_terminate(int signum)
{
  if(verbose==1)
  {
  (void)printf("received signal %d",signum);
  }
(void)gpio_close(zero.gpio_pin_red);
(void)gpio_close(zero.gpio_pin_green);
(void)gpio_close(zero.gpio_pin_yellow);
(void)gpio_close(one.gpio_pin_red);
(void)gpio_close(one.gpio_pin_green);
(void)gpio_close(one.gpio_pin_yellow);
(void)exit(1);
}
