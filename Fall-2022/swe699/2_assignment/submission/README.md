while not testing
uncomment lines 67-74 and add the right ports
set the test flag to 0


while testing set the test flag to 1
for verbose mode set the verbose flag to 1
watch "find . -iname value|sort |xargs cat"

test pins are set to 1,2,3,4,5,6
do not change the test pins as the underlying directory structure to test the code would not work

to simulate something similar to sysfs 
we had to create dummy gpio* folders in the test directory to simulate something close to sysfs and GPIO


arm-linux-gnueabihf-gcc -static main.c -o armit
qemu-arm ./armit
