## N-Queens Problem Solver

This program provides a solution to the N-Queens problem using a stack-based approach. The user can input the number of queens they would like to place on a chessboard of size N x N.

### How to Run

To compile and run the program, follow these steps:

1. Type `make run` in the terminal to start the program.
2. Enter the desired number of queens when prompted.
3. The program will display a chessboard with queens placed such that no two queens attack each other.
4. To clean the generated files, type `make clean` in the terminal.

### Input

The program takes input from the user to determine the number of queens to be placed on the chessboard. The user should enter a number greater than or equal to 4.

### Output

The output is a graphical representation of the chessboard with queens placed on non-attacking positions. Each row and column contains one queen, ensuring that no two queens attack each other.

### Technologies, Algorithms, and Concepts Used

This program utilizes the following technologies, algorithms, and concepts:

- **C++**: The program is written in the C++ programming language.
- **Stack-Based Approach**: The solution employs a stack-based approach to track the placement of queens on the chessboard.
- **Backtracking**: The program utilizes backtracking to explore all possible configurations of queen placements, ensuring that each placement is valid and leads to a solution.
- **N-Queens Problem**: The problem involves placing N queens on an NxN chessboard in such a way that no two queens threaten each other.
- **Stack Data Structure**: Stacks are used to keep track of the current state of queen placements, allowing for efficient backtracking.
- **Vector**: A vector is used to store filled columns, aiding in checking for conflicts in queen placements.
- **Conditional Statements**: Conditional statements are employed to check for valid queen placements and handle edge cases.

### Have Fun!

Enjoy exploring the N-Queens problem solver! If you have any questions or feedback, feel free to reach out.