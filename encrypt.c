#include "xorcypher.c"
#include "passgen.c"
#include "stdio.h"
#include <string.h>
#include <windows.h>
#include <ctype.h>

char* filename = "out.txt";

void writeToFile(char c, char* filename)
{
	FILE* f = fopen(filename, "a");
	fprintf(f, "%c", c);
	fclose(f);
}

int main()
{
	char* pass = passgen("test", (int)'x');
	char* in = "Example message";

	printf("Input: %s\n", in);
	printf("Pass: %s\n,len:%d\n\n", pass, strlen(pass));

	for(int i = 0; i < strlen(in); i++)
	{
		char c = in[i];
		char out = xorCypher_char(c, pass);
		char out2 = xorCypher_char(out, pass);

		printf("in:%c\nout:%d\n\n", c, (int)out);

		writeToFile(out, filename);
	}
	return 0;
}