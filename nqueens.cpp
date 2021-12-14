//include the libraries that will be used
#include <iostream>
#include <stack>
#include <cstdlib>
#include <vector>

//identify the stacks that will be used in the program
std::stack<int> row;
std::stack<int> col;

//identify vector that will be a memory holder
std::vector<int> filledcol;

//identify the boolean
bool works;

//create some variables that will be used
int queen = 1;
int tempr;
int tempc;
int n;

// this boolean checks for a open queen spot and places the queen in a working spot
bool fillspot(){
	//initiate the boolean at true before it goes through the processes of cheching for an open spot
	works = true;
	int a = 0;
	// makes sure the stack isnt empty and makes sure the spot works for the queen
	while(!col.empty()){
		//if the column is larger than the input
		if (tempc > n) {
		    works = false;
        }

		//int b = 0;
		//loops through until the temp is as much as the filled queens
		for(int b = 0; b < queen; b++){
			// checks if there are queens in similar colums
			if ( tempc == filledcol.at(a)){
				works = false;
            }
			a++;
        }
		//checks to similar colums
		if(tempc == col.top()){
			works = false;
        }
		// checks for similar diagonal
		if(tempc == col.top() + 1){
			works = false;
        }
		// checks for similar lower diagonal
		if (tempc == col.top() - 1){
			works = false;
        }
        // breaks the while loop
        break;
    }
	// returns the t/f to the main
	return works;
}

// function to run the actual nqueens
// fills each row and each collumn with one queen
void queenify(){
    tempr = 1;
	//while loop to continues until the program is complete
	//This continues until the number of filled is equel to n
	while(queen != n){ 
        //std::cout << tempr;
        // temp row value to hold the row its currently in
        tempr++;
        //std::cout << tempr;

		//initiate a boolean as false until the location of a queen is true
		works = false;		
		
		//while loop that continues until the end of the board is reached
		while(works != true){
			//int tempc = 0;// temp column variable
			//int tempr = 0;// temp row variable
			if(tempc >= n + 1){ // if the end of the board is reached then backtrack and pop hte rows and columns
                tempc = col.top(); // set the column size to tempc
                tempr = row.top(); // set the row size to temp r
                //std::cout << tempr;           
                row.pop(); // deletes the top value
                col.pop(); // deletes the top value
                queen = queen - 1; // kills of the filled queen spots
                filledcol.pop_back(); // pops a spot off the vector
            }

			tempc++;  // adds spot to the column temp
			fillspot(); // calls the fill spot void function

        }

        //std::cout << tempr;

		filledcol.push_back(tempc); // push the temp column to the vector
		row.push(tempr); // push the temp row to the stack
		col.push(tempc); // pushes the temp colums to the stack
        //std::cout << tempr << std::endl;
        //std::cout << tempc << std::endl;
        queen = queen + 1; // adds one to the filled till it reaches n
		tempc = 0; // resets the temp column
    }
}

// this function will print out the whole chess board
void print(){  
    //int i = 0;
    //int j = 1;
	// this will loop through the entire rows and columns of the chess board and place a Q in the queen spot and 0 in the non Q spots
    for(int i = 0; i < n; i++){
        //std::cout << "here"; 
        for(int j = 1; j <=n; j++){
            //if theres a queen
            if(col.top() == j){
                std::cout << " " << "Q" << " ";
            }
            else{
                std::cout << " 0 ";
            }
        }
        std::cout << "Queen " << queen;
        std::cout << std::endl << std::endl;
        //kills the stack and prints the stack on the output
        queen = queen - 1;
        row.pop();
        col.pop();
    }
}

// start the main function
int main(){

	//have the user input the number of queens they would like on the board
	std::cout << "Enter the number of queens you would like...";
	std::cin >> n ;

    //in order for the nqueens to work, the input value or number of queens
    //must be greater than 3
    while(n < 4){
        n = 0;
        std::cout << "Please enter a number greater than 3 for the number of queens..." << std::endl;
        std::cin >> n ;
    }

    // testing the value of n
    //std::cout << n << std::endl;

    // set the location of the queens in the bottom left of the chess board
	row.push(1);
	col.push(1);
	filledcol.push_back(1); // fills the whole first column

    // runs the actual nqueens through this function
    queenify();

    //std::cout << "Made it";
	print(); // calls the print function to print the whole chess board.

    return 0;
}
