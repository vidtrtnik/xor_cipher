#include <stdio.h>
#include <time.h>

char* getDate(char* format)
{
	time_t rawtime;
	struct tm * timeinfo;
	static char buffer [50];
	
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	
	strftime (buffer, 50, format, timeinfo);
	
	return buffer;
}

char* passgen(char* str, int f)
{
	static char pass[255];
	
	if(strlen(str) >= 255)
	{
		return NULL;
	}
	
	strcpy(pass, str);

	char fchar = (char)f;
	for(int i=strlen(pass); i < 255; i++)
	{
		pass[i] = fchar;
	}
	
	return pass;
	
}