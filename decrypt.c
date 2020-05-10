#include <stdio.h>
#include <string.h>
#include "passgen.c"
#include "xorcypher.c"

int main(int argc, char** argv)
{
	printf("%s\n\n", argv[1]);
	
	char* pass = passgen("test", (int)'x');
	
	FILE* file = fopen(argv[1], "r");

	fseek(file, 0, SEEK_END);
	size_t s = ftell(file);
	fseek(file, 0, SEEK_SET);
	
	printf("Input size: %d\n\n", s);
	printf("Output: ");

	for(int i=0; i < s; i++)
	{
		char b[1];
		fread(b, 1, 1, file);
		
		char in = b[0];
		
		char out = xorCypher_char(in, pass);

		printf("%c", out);
	}
	printf("\n");
	return 0;
}