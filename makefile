# Compile the NQueens program
NQueens: nqueens.o
	g++ nqueens.o -o NQueens

# Compile the source file
nqueens.o: nqueens.cpp
	g++ -c nqueens.cpp

# Clean up compiled files
clean:
	rm -f NQueens
	rm -f *.o

# Run the NQueens program
run: NQueens
	./NQueens
