#include <iostream>
#include <stack>
#include <cstdlib>
#include <vector>

using namespace std;

// Define stacks for row and column
stack<int> row;
stack<int> col;

// Define vector to hold filled columns
vector<int> filledcol;

// Define boolean variable
bool works;

// Define variables
int queen = 1;
int tempr;
int tempc;
int n;

// Function to check if a spot is valid to place a queen
bool fillspot() {
    works = true;
    int a = 0;

    // Check if the column is within the board size
    while (!col.empty()) {
        if (tempc > n) {
            works = false;
        }

        // Check if there are queens in the same column
        for (int b = 0; b < queen; b++) {
            if (tempc == filledcol.at(a)) {
                works = false;
            }
            a++;
        }

        // Check for queens in the same column
        if (tempc == col.top()) {
            works = false;
        }

        // Check for queens in the diagonals
        if (tempc == col.top() + 1) {
            works = false;
        }

        // Check for queens in the lower diagonals
        if (tempc == col.top() - 1) {
            works = false;
        }
        break;
    }
    return works;
}

void queenify() {
    tempr = 1;
    // Loop until all queens are placed
    while (queen != n) {
        tempr++; // Move to the next row
        works = false; // Set works to false until a valid queen position is found

        // Loop until a valid position is found
        while (!works) {
            if (tempc >= n + 1) { // If end of the board is reached, backtrack
                tempc = col.top();
                tempr = row.top();
                row.pop();
                col.pop();
                queen--;
                filledcol.pop_back();
            }

            tempc++;
            fillspot();
        }

        filledcol.push_back(tempc); // Store the column in the vector
        row.push(tempr); // Store the row in the stack
        col.push(tempc); // Store the column in the stack
        queen++;
        tempc = 0; // Reset the column counter
    }
}


// Function to print the entire chessboard with queens
void print() {  
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (col.top() == j) {
                cout << " Q ";
            } else {
                cout << " 0 ";
            }
        }
        cout << "Queen " << queen << endl << endl;
        queen--;
        row.pop();
        col.pop();
    }
}

// Main function
int main() {
    // Prompt user to input the number of queens
    cout << "Enter the number of queens you would like: ";
    cin >> n;

    // Ensure that the input value for the number of queens is greater than 3
    while (n < 4) {
        cout << "Please enter a number greater than 3 for the number of queens." << endl;
        cin >> n;
    }

    // Initialize the location of the queens in the bottom left of the chessboard
    row.push(1);
    col.push(1);
    filledcol.push_back(1); // Fill the first column

    // Run the nqueens algorithm
    queenify();

    // Print the entire chessboard with queens
    print();

    return 0;
}
