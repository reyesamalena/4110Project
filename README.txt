### Project 1 ###
 
===========================================================================
HEADER:

Names: Zach Bordelon, Malena Reyes
Emails: ZacharyBordelon@my.unt.edu, Malenareyes@my.unt.edu
Course: CSCE 4110
Title: Project 1  
 
===========================================================================

TESTED ON:
 
macOS (with Xcode and g++ installed)
Linux (Mac terminal and g++)
 
 
===========================================================================
FILES INCLUDED:

filename:     something
              the fractional knapsack and the combo knapsack for comparison  
    

 
 

===========================================================================
COMPILE PROGRAM:
 
To compile this part one navigate inside the part1 folder and the easiest 
compilation uses the command format:

	g++ -std=c++11 *.cpp

This command will create an executable in the same directory called "a.out" 
(the default executable target name when one is not specified). 

To compile this part two open the part2 folder and the easiest compilation 
uses the command format:

	g++ -std=c++11 *.cpp

This command will create an executable in the same directory called "a.out" 
(the default executable target name when one is not specified). 

===========================================================================
INPUT FILES:

There are 5 different input files for items with the different weights,
cost, and addresses. The values are comma separated so if someone wants to
add their own file make sure it is in the format:
		(name),(weight),(cost),(address).
	input1.txt: Max Weight: 9, Max Cost: 3220
	input2.txt: Max Weight: 100, Max Cost: 10000
	input3.txt: Max Weight: , Max Cost: 
	input4.txt: Max Weight: , Max Cost: 
	input5.txt: Max Weight: , Max Cost: 

After executing the program you will choose one of these files to run. 

===========================================================================
EXECUTE PROGRAM:
 
After you have successfully compiled the program, producing the default 
executable output, the program may be executed using the command format:

	./a.out

This command will run the resulting executable in the same directory.
The configuration file will then be requested from the user ex.config1.txt
this file needs to be in the same directory as the rest of the files. The
population.txt relevant to that configuration file also needs to be in the 
same directory.
 
===========================================================================
