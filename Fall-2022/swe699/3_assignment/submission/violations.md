The code we wrote has 7 violations:

violated standard 21.5 - Standard header file signal.h should not be used. 
Count = 1
Explanation: We wrote a custom signal handler to handle the interrupt signal we use to stop the infinite loop.
Our code un-initializes all the pins used before the code execution terminates.

violated directive 4.6 - typedefs that indicate size and signedness should be used in place of the basic int numerical type. 
Count = 6
Explanation:
line no: 42, 350 - a custom signal handler expects and argument of the type int and int alone. we could not find a way of writing a custom handler without the int. The same variable was listed twice. Once for the prototype and once for the function definition/

Line no: 39, 219: the variable direction is used to mention the data flow direction. Every standard file i/o function fopen etc expects a stream of character and not a stream of wchar_t so we could not use it.The same variable was listed twice. Once for the prototype and once for the function definition/

Line no: 234, 279: The variable path was used to specify the path to a file used to interact with the beaglebone and again we could not find any standard file opening functions that were not expecting a stream of characters. The same variable was listed twice. Once for the prototype and once for the function definition/


