#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <sys/sendfile.h>
#include <sys/types.h>
#include <sys/wait.h>

int splitAndExe(char** args, int argsLen, bool showCall, int lastArg);

int main (int argc, char *argv[]) {
	
	bool showCall = 0;
	int argAmount = 50;	//max argAmount by default
	int argSize = 30;
	int optCurs = 1;
	
	//read in options from user
	int actOpt;
	while ((actOpt = getopt(argc, argv, "n:t")) != -1) {
		optCurs++;
		if (actOpt == 'n') {
			argAmount = (int)strtol(optarg, NULL, 10);
			optCurs++;
			
			//check that optarg was converted to an int
			if ((argAmount == 0 || argAmount == LONG_MIN) || argAmount == LONG_MAX) {
				write(1, "xargs: Error converting argument count to int: ", strlen("xargs: Error converting argument count to int: "));
				write(1, strerror(errno), strlen(strerror(errno)));
				write(1, "\n", strlen("\n"));
				return -1;
			}
		} else if (actOpt == 't') {
			showCall = 1;
		}
	}
	
	//initialize args array for function call
	int argsToInheritCount = argc-optCurs;
	int argsLen = argAmount + argsToInheritCount + 2;
	char* args[argsLen];
	for (int i = 0; i < argsLen - 1; i++) {
		args[i] = malloc(argSize * sizeof(char));
		if (!args[i]) {
			write(1, "xargs: Error allocating memory for args array\n", strlen("xargs: Error allocating memory for args array\n"));
			return -1;
		}
	}
	
	//set command as first arg and null as last
	if (optCurs == argc) {	//if not specified use default command
		 strcpy(args[0], "/bin/echo");
	} else {
		strcpy(args[0], argv[optCurs]);
		optCurs++;
	}
	args[argsLen - 1] = NULL;	//last arg is null
	
	//inherit remaining args from xargs call
	for (int i = 0; i < argsToInheritCount; i++) {
		strcpy(args[1 + i], argv[optCurs]);
		optCurs++;
	}
	
	//execute function
	size_t bufferSize = argSize;
	char* buffer;
	int nextArg = 1 + argsToInheritCount;
	while (getline(&buffer, &bufferSize, stdin) > 0) {
		
		//put read argument into args at next spot
		strcpy(args[nextArg], strtok(buffer, "\n"));
		nextArg++;
		
		if (nextArg == argsLen-1) {
			
			//create new process to run the command with the args in args
			if (splitAndExe(args, argsLen, showCall, nextArg) == -1) {
				return -1;	//messeges handled in function
			}
			
			//clean up args after call and reset nextArg
			for (int i = 1; i < argsLen - 1; i++) {
				free(args[i]);
				args[i] = malloc(argSize * sizeof(char));
				if (!args[i]) {
					write(1, "xargs: Error allocating memory for args array\n", strlen("xargs: Error allocating memory for args array\n"));
					return -1;
				}
			}
			nextArg = 1 + argsToInheritCount;
		}
	}
	
	//run command with remaining arguments in args if any
	if (nextArg > 1 + argsToInheritCount) {
		//insert a null after last arg to cap arg array and run
		args[nextArg] = NULL;
		if (splitAndExe(args, argsLen, showCall, nextArg) == -1) {
			return -1;	//messeges handled in function
		}
	}
}

int splitAndExe(char** args, int argsLen, bool showCall, int lastArg){
	
	//show call
	if (showCall) {
		printf("%s", args[0]);
		for (int i = 1; i < lastArg; i++) {
			printf(" %s", args[i]);
		}
		printf("\n");
	}
			
	//fork and check if it failed
	pid_t child = fork();
	if (child == -1) {
		write(1, "xargs: Error, couldn't create child process: ", strlen("xargs: Error, couldn't create child process: "));
		write(1, strerror(errno), strlen(strerror(errno)));
		write(1, "\n", strlen("\n"));
		return -1;
	}
	
	//if child execute command and exit, else wait for child
	if (child == 0) {
		
		execvp(args[0], args);
		write(1, "xargs: Error, command couln't be executed\n", strlen("xargs: Error, command couln't be executed\n"));
		return -1;
		
	} else {
		
		//wait for child to convert with execvp
		if (waitpid(child, NULL, WNOHANG | WUNTRACED) == -1) {
			write(1, "xargs: Error, waitpid faild: ", strlen("xargs: Error, waitpid faild: "));
			write(1, strerror(errno), strlen(strerror(errno)));
			write(1, "\n", strlen("\n"));
			return -1;
		}
		
		//give time for execvp to execute
		struct timespec req = {0};
		req.tv_sec = 0;
		req.tv_nsec = 5000000L;
		nanosleep(&req, (struct timespec *)NULL);
	}
	
	return 0;
}