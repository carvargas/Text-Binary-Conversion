/*Carina Vargas*/
/*cv164112*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define STR_LEN 255

int binStats(char *inp)
{
	/*variables*/
	long int count;
	char string[STR_LEN];
	unsigned int i;
	unsigned int integer;
	unsigned int length;
	unsigned int maxStr = 0;
	unsigned int minStr = 0;
	unsigned int maxInt = 0;
	unsigned int minInt = 0;
	
	/*file pointers*/
	FILE *fp;
	
	/*input files error check*/
	if((fp = fopen(inp, "r")) == NULL)
	{
		printf("Input file could not be opened\n");
		return 0;
	}
	
	/*to store the size of file*/
	fseek(fp, 0, SEEK_END);
	count = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	/*loop until EOF*/
	while((ftell(fp)) != count)
	{
		/*take the first character--length of string*/
		fscanf(fp, "%c", &string[0]);
		
		
		/*convert character into an unsigned int*/
		length = string[0]; 
		
		/*sets minimum value*/
		if(minStr == 0)
		{
			minStr = length;
		}
		
		/*finds min string length*/
		if(minStr > length)
		{
			minStr = length;
		}
		
		/*finds max string length*/
		if(maxStr < length)
		{
			maxStr = length;
		}
			
		i = 0;
		/*used in this function to navigate through the file*/
		while(length > 0)
		{
			fscanf(fp, "%c", &string[i]);
			i++;
			length--;
		}
		
		/*read the integer*/
		fread((void *)&integer, sizeof(unsigned int), 1, fp);

		/*sets minimum value*/
		if(minInt == 0)
		{
			minInt = integer;
		}
		/*finds smallest integer*/
		if(minInt > integer)
		{
			minInt = integer;
		}
		/*finds largest integer*/
		if(maxInt < integer)
		{
			maxInt = integer;
		}
		 
	}
	
	/*prints shortest string*/
	fprintf(stdout, "length of shortest string: %d\n", minStr);
	
	/*prints longest string*/
	fprintf(stdout, "length of longest string: %d\n", maxStr);
	
	/*prints largest integer*/
	fprintf(stdout, "value of largest integer: %d\n", maxInt);
	
	/*prints smallest integer*/
	fprintf(stdout, "value of smallest integer: %d\n", minInt);

	/*close files*/
	fclose(fp);
}	