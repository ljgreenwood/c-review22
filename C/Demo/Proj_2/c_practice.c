#include <stdio.h>

int main(int argc, char* argv[]){
	// argc is the number of command line arguments passed to the program
    	// argv is an array of strings containing the command line arguments
   	// Check if any command line arguments were provided	
if (argc <2){
	printf("no command line arguments provided.\n");
	return 1; //error code
	}
// Print out each command line argument

printf("Number of arguments: %d\n", argc - 1); //exclude program name from count " thus the minus 1
						       
printf("Arguments:\n");
for (int i = 1; i < argc; i++) {
	printf(" %d: %s\n", i, argv[i]);
}

return 0; //return properly
}
