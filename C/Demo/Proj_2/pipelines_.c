#include <stdio.h> //standard io library
#include <stdlib.h> // standard library for mem allocation, exit func,
#include <unistd.h> //POSIX operating system API, including fork, pipe, etc.
#include <string.h> //string manipulation functions 
#include <ctype.h> //char class & conversion func

#define READ_END 0 //  const for read end of pipe
#define WRITE_END 1 // const for write end of pipe

/*
Write a C program that creates 3 processes (one parent and two children). The processes will relay
information to each other in following fashion:

• The first process (parent) reads a text file “input.txt” line by line.
• The second process reads from the first pipe and reverse letters (Capital to small and small to capital).
• The third process reads from the second pipe and outputs to a file e.g., “output.txt”.

*/

int main(int argc, char* argv[]) 
{
    // declare pipes
    int fd1[2], fd2[2]; //array of integers, used to distinguish read/write ends of the pipe. each pipe has a read and write end
			//input for fd1[0] READ_END
			//output for fd1[1] WRITE_END
			//second pipe has same properties
    pid_t pid; //type stores process IDs which are returned by fork() 

    if (pipe(fd1) == -1 || pipe(fd2) == -1) // would signal that the pipe was unsuccessfully connected
	{
		fprintf(stderr, "Pipe failed"); //return stderr if the 
		return 1;
	}

    pid = fork(); //Process ID value distinguishes the status of the process after the fork [parent or child]

    if (pid < 0) 
	{
		fprintf(stderr, "Fork Failed"); //prints error for failed fork (error code output to pid for failed fork is less than 0)
		return 1;
	}

    if (pid > 0) //parent process routes file into child processes
	{	/*unused pipes are closed*/
	  	close(fd1[READ_END]); //closing read end of pipe 1 
		close(fd2[WRITE_END]); //closing write end of pipe 2

	        FILE* fp = fopen("input.txt", "r"); //opening file in read mode
						    //fp is file pointer returned by fopen()
    
       		if (fp == NULL) //exit program if file fails to open (thus the file pointer does not exist)
			{
			    fprintf(stderr, "Failed to open file\n"); 
			    exit(1); 
			}

		char line[BUFSIZ]; // creation of a buffer to store read text

		while (fgets(line, BUFSIZ, fp)) //fgets value of length determined by BUFSIZ from fp and writes into line 
			{
			    write(fd1[WRITE_END], line, strlen(line));	/*Write line into first pipe strlen returns number of bytes to be written 
									to file descriptor*/
			    memset(line, 0, BUFSIZ);			//Clear the line buffer
			    read(fd2[READ_END], line, BUFSIZ); 		//Read from second pipe
			    printf("%s", line); 			//Print modified line
			}
		//closing file and pipes
		fclose(fp);
		close(fd1[WRITE_END]); //closing write end of pipe 1
		close(fd2[READ_END]); //closing read end of pip 2
	}
    
    else
    	{	
		// Child process
		// fork for second child process
		pid = fork();

		if (pid > 0)
			{	 
				// Second process
				close(fd1[WRITE_END]);
				close(fd2[READ_END]);
				char line[BUFSIZ];
				// read from the first pipe
				while (read(fd1[READ_END], line, BUFSIZ)) 
					{
					    for (int i = 0; i < strlen(line); i++) //iterates through all indeces of line
						{
							if (islower(line[i]))
								{
									//check lowercase of char at i and swaps with upper
									line[i] = toupper(line[i]);
								}
							else if (isupper(line[i]))
								{
									//check uppercase of char at i and swaps with lower
									line [i] = tolower(line[i]);
								}
							else {}
						}
						// write modified line into the second pipe 
						write(fd2[WRITE_END], line, strlen(line));
						// clear the line buffer
						memset(line, 0, BUFSIZ);
	
					}
				// Close pipes
				close(fd1[READ_END]);
				close(fd2[WRITE_END]);
		}
		else 
			{
				// Third process 
				// pipe 1 is unused and pipe 2 is only read from and written into from output.txt
				close(fd1[READ_END]);
				close(fd1[WRITE_END]);
				close(fd2[WRITE_END]);

				FILE* fp = fopen("output.txt", "w"); //opens file output.txt in write mode
 
				if (fp == NULL)
					{
						fprintf(stderr, "Failed to open output file\n");
						exit(1);
					}
				char line[BUFSIZ];
				// read from the second pipe
				while (read(fd2[READ_END], line, BUFSIZ)) 
					{
						// prints to the output.txt file
						fprintf(fp, "%s", line);
						memset(line, 0, BUFSIZ);
					}
				//closing output.txt and pipe
				fclose(fp);
				close(fd2[READ_END]);
			}
	}
    
return 0;}
