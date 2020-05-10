#include <stdio.h>
#include <string.h>

int xorCypher_str(char* data, char* key)
{
	
	for(int i=0; i < strlen(data); i++)
	{
		// TODO
		break;
	}
	return 0;
}

char xorCypher_char(char data,  char* key)
{
	char result = data;

	for(int i=0; i < strlen(key); i++)
	{
		result = result ^ key[i];
	}
	
	return result;
}
