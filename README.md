Copyright Feburary 2017 napalerd@bu.edu
# Tic-Tac-Toe-Analyzer
This is a class assignment of C++ program that reads tic-tac-toe scenarios from a file and determines the status of each game.

# Input Format
The data is in a file named “tictactoeboards.txt”. Each line of the file represents a tic-tac-toe board, as follows: 

x represents x  
o represents o  
"#" represents an unplayed space  

The first three characters are the top row, the next three the middle row, and the last three are the bottom row. 
So the line:  

xoxox#xox    

represents the board:  

  x | o | x  
  
  o | x |    
  
  x | o | x  

# Output
The program should classify the board as one of the following:  
• t: tie game and no spaces left  
• x: valid, x has won  
• o: valid, o has won  
• c: valid, game continues  
• i: invalid  

The result of running the program should be the creation of a new txt file which contains the original board data plus a space and a letter indicating the status, one of “i” for invalid, “x” for x won, “o” for o win, “t” for tie game, or “c” for game continues.
A valid game board is one that can be arrived at by two players following the rules (but possibly playing badly).
An invalid game board is one in which there was a rule violation. A game can be invalid for many reasons, such as too many winners, unbalanced number of x’s and o’s, etc.

# Example
The line in the output file for the above board should be:  

xox#x#xox i  

(it is invalid because x played 5 times and o only played 2 times.)  

# Rules of Tic Tac Toe
Player x and player o alternately place their symbols on a 3x3 board, starting with x. The first player to get three symbols in a row wins, and the game is over. If all nine squares are full and no player has three symbols in a row, the game ends in a tie.
