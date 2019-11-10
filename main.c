#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h> 

int randNumber () { 
	int f = open ("/dev/random", O_RDONLY); 
	int ans; 
	read (f, &ans, sizeof (int)); 
	return ans;
}

int main () { 
	int a [10]; 
	printf ("Generating random numbers:\n"); 
	int i; 
	for (i = 0; i < 10; i ++) { 
		a[i] = randomNumber (); 
		printf ("\t random %d: %d\n", i, a[i]);  
	}
	return 0;
}
