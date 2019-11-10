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

void printArray (int arr[]){ 
	int i; 
	for (i = 0; i < 10; i ++) { 
		printf ("\trandom %d: %d\n", i, arr[i]); 
	}
}

int main () { 
	int a [10]; 
	printf ("Generating random numbers:\n"); 
	int i; 
	for (i = 0; i < 10; i ++) { 
		a[i] = randomNumber (); 
	}
	printArray (a); 

	printf ("Writing numbers to another file... \n"); 
	int f = open ("numbers.txt", O_RDWR, 0666); 
	write (f, a, sizeof (a)); 
	
	printf ("Reading numbers from the file ... \n"); 
	int another [10]; 
	int f2 = open ("numbers.txt", O_RDONLY); 
	read (f2, &another, sizeof (another); 
	
	printf ("Verification that written values stay the same: \n"); 
	printArray (another); 	

	return 0;
}
