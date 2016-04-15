/*Carina Vargas*/
/*cv164112*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define STR_LEN 255

int TxtToBin(char *inp, char *out)
{
	/*variables*/
	long int count;
	unsigned int i;
	char string[STR_LEN];
	unsigned int integer;
	unsigned char length;
	
	/*file pointers*/
	FILE *fp;
	FILE *fo;
	
	/*input/output files error check*/
	if((fp = fopen(inp, "r")) == NULL)
	{
		fprintf(stderr, "Input file could not be opened\n");
		return 0;
	}
	
	if((fo = fopen(out, "w")) == NULL)
	{
		fprintf(stderr, "Output file could not be opened\n");
		return 0;
	}	
	
	/*to store the size of file*/
	fseek(fp, 0, SEEK_END);
	count = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	/*loop until EOF*/
	while((ftell(fp)) != count)
	{
		/*scans in one line*/
	 	fscanf(fp, "%s \t %d", string, &integer);
		
		/*finds length of string*/
		length = strlen(string);
		
		/*writes the integer in 1 byte*/
		fwrite((void *)&length, sizeof(char), 1, fo);
		
		/*writes string without null character*/
		for(i = 0; i < length; i++)
		{
			fwrite((void *)&string[i], sizeof(char), 1, fo);
		}
		
		/*writes integer in 4 bytes*/
		fwrite((void *)&integer, sizeof(int), 1, fo);
	}
	
	/*close files*/
	fclose(fp);
	fclose(fo);
}