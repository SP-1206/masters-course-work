#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <string.h>

/*Group: Group 25
Name 	G#
Aravind Sri Ram Sri Parasara G01301679
Vaibhav Vijay Oza G01337138
Pratyusha Arvapalli G01328372
Venkata Sai Devi Priyanka Pilla G01351608
Koushik Sura Bhaskar G01327456
*/
// macros to define the pin numbers for every sensor

#define DHT11 45 // humididty and temp sensor
#define MQ3 68   // alcohol sensor
#define MQ5 26   // methane sensor
#define MQ6 67   // butane sensor
#define ALARM 46 // buzzer

#define test 0    // test flag to test the local framework
#define verbose 0 // to increase the verbosity of the printed messages

// function prototypes
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

// the check_dht11 function is used to detect the humidity and the temperature.
//  this function uses bbb_dht_read function from the adafruit library to read the temperature and humidity
static void *check_dht11(void *ptr)
{
     float humidity, temperature;
     while (1)
     {

          (void)bbb_dht_read(11, 1, 13, &humidity, &temperature);

          if (humidity <= 100.0f && humidity != 0.0f)
          {
               (void)printf("------------------------\nHumidity=%5.2f Temperature=%5.2f C\n------------------------\n\n", humidity, temperature);
               if (temperature >= 30.0f)
               {
                    (void)sound_alarm();
               }
          }

          (void)sleep(2);
     }

     return 0;
}

// check_mq3 function is used to check the alcohol levels
// we have used the standard MQ3 sensor and are using the GPIO sysfs interface to interact with it.
static void *check_mq3(void *ptr)
{
     while (1)
     {
          // check the value returned by MQ3 if it is 0 then alert
          if (gpio_get_value_from_port(MQ3) == 0)
          {
               (void)printf("------------------------\nAlcohol Detected-high\n------------------------\n\n");
               (void)sound_alarm();
          }
          (void)sleep(5);
     }
}

// check_mq5 function is used to check the methane levels
// we have used the standard MQ5 sensor and are using the GPIO sysfs interface to interact with it.

static void *check_mq5(void *ptr)
{
     while (1)
     {
          // check the value returned by MQ5 if it is 0 then alert
          if (gpio_get_value_from_port(MQ5) == 0)
          {
               (void)printf("------------------------\nMethane Detected\n------------------------\n\n");
               (void)sound_alarm();
          }
          (void)sleep(5);
     }
}

// check_mq6 function is used to check the Butane levels
// we have used the standard MQ6 sensor and are using the GPIO sysfs interface to interact with it.

static void *check_mq6(void *ptr)
{
     while (1)
     {
          // check the value returned by MQ6 if it is 0 then alert
          if (gpio_get_value_from_port(MQ6) == 0)
          {
               printf("------------------------\nButane Detected\n------------------------\n\n");
               (void)sound_alarm();
          }
          (void)sleep(5);
     }
}

// we are using a standard active buzzer to sound an alarm
static void sound_alarm()
{
     (void)gpio_set_value_to_port(ALARM, 1);
     (void)sleep(3);
     (void)gpio_set_value_to_port(ALARM, 0);
}

int8_t main(void)
{

     // create a thread for each sensor
     pthread_t thread1, thread2, thread3, thread4;

     // set the directions for each sensor
     (void)gpio_set_direction(DHT11, "in");  // dht-11 direction in
     (void)gpio_set_direction(MQ3, "in");    // mq3 direction in
     (void)gpio_set_direction(MQ5, "in");    // mq5 direction in
     (void)gpio_set_direction(MQ6, "in");    // mq6 direction in
     (void)gpio_set_direction(ALARM, "out"); // Alarm to out

     (void)pthread_create(&thread1, NULL, check_dht11, "none");
     (void)pthread_create(&thread2, NULL, check_mq3, "none");
     (void)pthread_create(&thread3, NULL, check_mq5, "none");
     (void)pthread_create(&thread4, NULL, check_mq6, "none");

     (void)pthread_join(thread1, NULL);
     (void)pthread_join(thread2, NULL);
     (void)pthread_join(thread3, NULL);
     (void)pthread_join(thread4, NULL);
}

/********interact with GPIO pin using sys interface****************/

static void gpio_init(int8_t pin)
{
     // sysfs -
     //  open /sys/class/gpio/export to write
     //  write the pin number to the file

     if (verbose == 1)
     {
          (void)printf("exporting pin %d\n", pin);
     }

     FILE *fp;
     fp = fopen("/sys/class/gpio/export", "w");

     if (test == 1)
     {
          fp = fopen("./test/export", "w");
     }

     if (fp == NULL)
     {
          (void)printf("func: gpio_init \t err:error opening file \t pin: %d\n", pin);
          (void)exit(0);
     }

     if (fprintf(fp, "%d", pin) < 0)
     {
          (void)printf("func: gpio_init \t err:error writing to file \t pin: %d\n", pin);
          (void)exit(0);
     }

     (void)fclose(fp);
}

// set the input or output?
// should be written in direction file under the directory
static void gpio_set_direction(int8_t pin, char *direction)
{

     if (verbose == 1)
     {
          (void)printf("setting the direction to %s for the pin %d\n", direction, pin);
     }
     else
     {
          ;
     }

     // open /sys/class/gpio/gpio<pin>/direction to write
     // write the value to the file - in/out
     char path[150];

     if (test == 1)
     {
          (void)sprintf(path, "./test/gpio%d/direction", pin);
     }
     else
     {
          (void)sprintf(path, "/sys/class/gpio/gpio%d/direction", pin);
     }

     FILE *fp;
     fp = fopen(path, "w");

     if (fp == NULL)
     {
          (void)printf("func: gpio_set_direction \t err:error opening file \t pin: %d\n", pin);
          (void)exit(0);
     }

     if (fprintf(fp, "%s", direction) < 0)
     {
          (void)printf("func: gpio_set_direction \t err:error writing to file \t pin: %d\n", pin);
          (void)exit(0);
     }

     (void)fclose(fp);
}

static void gpio_set_value_to_port(int8_t pin, int8_t value)
{
     if (verbose == 1)
     {
          (void)printf("setting the value for the pin %d to %d\n", pin, value);
     }

     char path[150];

     if (test == 1)
     {
          (void)sprintf(path, "./test/gpio%d/value", pin);
     }
     else
     {
          (void)sprintf(path, "/sys/class/gpio/gpio%d/value", pin);
     }

     FILE *fp;
     fp = fopen(path, "w");

     if (fp == NULL)
     {
          (void)printf("func: gpio_set_value_to_port \t err:error opening file \t pin: %d\n", pin);
     }

     if (fprintf(fp, "%d", value) < 0)
     {
          (void)printf("func: gpio_set_value_to_port \t err:error writing to file \t pin: %d\n", pin);
          (void)exit(0);
     }

     (void)fclose(fp);
}

static void gpio_close(int8_t pin)
{
     if (verbose == 1)
     {
          (void)printf("unexporting pin %d\n", pin);
     }

     FILE *fp;
     fp = fopen("/sys/class/gpio/unexport", "w");
     if (test == 1)
     {
          fp = fopen("./test/unexport", "w");
     }

     if (fp == NULL)
     {
          (void)printf("func: gpio_close \t err:error opening file \t pin: %d\n", pin);
     }

     if (fprintf(fp, "%d", pin) < 0)
     {
          (void)printf("func: gpio_close \t err:error writing to file \t pin: %d\n", pin);
          exit(0);
     }

     (void)fclose(fp);
}

static int gpio_get_value_from_port(int8_t pin)
{

     // if(verbose==1)
     //{
     //(void)printf("getting the value for the pin %d \n",pin);
     // }

     char path[150];

     if (test == 1)
     {
          (void)sprintf(path, "./test/gpio%d/value", pin);
     }
     else
     {
          (void)sprintf(path, "/sys/class/gpio/gpio%d/value", pin);
     }

     FILE *fp;
     int c;
     int n = 0;

     fp = fopen(path, "r");
     if (fp == NULL)
     {
          (void)printf("func: gpio_get_value_from_port \t err:error opening file \t pin: %d\n", pin);
     }
     c = fgetc(fp);

     fclose(fp);
     if (c == '0')
          return 0;
     else
          return 1;
}

static void clean_terminate(int signum)
{
     if (verbose == 1)
     {
          (void)printf("received signal %d", signum);
     }
     (void)gpio_close(DHT11);
     (void)gpio_close(MQ3);
     (void)gpio_close(MQ5);
     (void)gpio_close(MQ6);
     (void)gpio_close(ALARM);
     (void)exit(1);
}
