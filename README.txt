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

knapsack.cpp:        this algorithm runs only using knapsack algorithm 
                     for large sets of data. 
              
dijkstranknap.cpp:   this algorithm runs using dijkstras and knapsack
                     however only runs on smaller sets of data.  
    

 
 

===========================================================================
COMPILE PROGRAM:
 
To compile this part one navigate inside the part1 folder and the easiest 
compilation uses the command format:

	g++ -std=c++11 filename.cpp

This command will create an executable in the same directory called "a.out" 
(the default executable target name when one is not specified). 


===========================================================================
INPUT FILES:

There are 5 different input files for items with the different weights,
cost, and addresses. The values are comma separated so if someone wants to
add their own file make sure it is in the format:
		(name),(weight),(cost),(address)
	input1.txt: Min Weight: 1, Max Weight: 9, 
		    Min Cost: 1, Max Cost: 3220
	input2.txt: Min Weight: 1, Max Weight: 100, 
		    Min Cost: 1, Max Cost: 10000
	input3.csv: Min Weight: 1, Max Weight: 50,
		    Min Cost: 1, Max Cost: 5000
	input4.csv: Min Weight: 50, Max Weight: 100,	(only 1 with 50)
		    Min Cost: 1, Max Cost: 1000
	input5.csv: Min Weight: 100, Max Weight: 500,	(only 1 with 100)
		    Min Cost: 1000, Max Cost: 5000	
		    
		    
		    


After executing the program you will choose one of these files to run.
The files can be .csv or .txt as long as they're formatted correctly.

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
