Go Fish!

I. Purpose:
    The purpose is to define and use classes to simulate the card game, go fish. 

II. Compile: 
    ./go_fish

III. What works:
    1. Can simulate a full two player game of go fish without user input.  
    
IV. Bugs: 
    1. The makefile doesn't run sometimes. If encountered:
	- Type "module load gcc"
	- If that doesn't work, remove all the "-std=c++11" in the makefile, then type "make" again
	- If it still doesn't work, place the "-std=c++11" back again in the makefile and it should work now. 
	