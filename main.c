/*Carina Vargas*/
/*cv164112*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int BinToTxt(char *, char *);
int TxtToBin(char *, char *);
int binStats(char *);

int main(int argc, char *argv[])
{
	/*error checks*/
	/*arguments = 3*/
	if (argc == 3)
	{
		/*if flag is not -s, end program*/
		if(argv[1][1] != 's')
		{
			fprintf(stderr, "Wrong flag for stats\n");
			return 0;
		}
	}
	
	/*arguments = 4*/
	else if(argc == 4)
	{
		/*if flag is not -b or -t, end program*/
		if(argv[1][1] != 'b' && argv[1][1] != 't')
		{
			fprintf(stderr, "Wrong flag for conversion\n");
			return 0;
		}
	}
	
	/*arguments not equal to 3 or 4, end program*/
	else
	{
		fprintf(stderr, "Incorrect arguments!\n");
		return 0;
	}
	/*end of error checking*/
	
	if(argv[1][1] == 'b')
	{	
		/*send files to binary to text function*/
		BinToTxt(argv[2], argv[3]);
	}
	
	if (argv[1][1] == 't')
	{
		/*send files to text to binary function*/
		TxtToBin(argv[2], argv[3]);
	}
	
	if(argv[1][1] == 's')
	{
		/*send file to stats function*/
		binStats(argv[2]);
	}
	
	return 0;
}