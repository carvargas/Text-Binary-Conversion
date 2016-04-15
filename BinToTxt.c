/*Carina Vargas*/
/*cv164112*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define STR_LEN 255

int BinToTxt(char *inp, char *out)
{	
	/*variables*/
	long int count;
	char string[STR_LEN];
	unsigned int i;
	unsigned int integer;
	unsigned int length;
		
	/*file pointers*/
	FILE *fp;
	FILE *fo;
		
	/*input/output files error check*/
	if((fp = fopen(inp, "r")) == NULL)
	{
		printf("Input file could not be opened\n");
		return 0;
	}
	
	if((fo = fopen(out, "w")) == NULL)
	{
		printf("Output file could not be opened\n");
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
			
		i = 0;
		/*scans in characters with string length as counter*/
		while(length > 0)
		{
			fscanf(fp, "%c", &string[i]);
			i++;
			length--;
		}
		
		/*adds null terminator*/
		string[i] = '\0';
		
		/*read the integer*/
		fread((void *)&integer, sizeof(unsigned int), 1, fp);
		
		/*prints string to output*/
		fprintf(fo, "%s", string);
		
		/*prints tab to output*/
		fprintf(fo, "\t");
		 
		/*prints integer to output*/
		fprintf(fo, "%d", integer);	

		/*avoid newline at end of last line*/
		if((count - (ftell(fp)) != 0))
		{
			/*print new line*/
			fprintf(fo, "\n");
		}
	}

	/*close files*/
	fclose(fp);
	fclose(fo);
}