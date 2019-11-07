#include <openssl/sha.h>
#include<string.h>
#include<limits.h>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
  char str[100];
  char unsigned *buffer;
  long numbytes;
  unsigned char result[SHA_DIGEST_LENGTH] = {'\0'};
  printf("Enter the file name : ");
 // gets(str);

	cin >> str;
  FILE *fp;
  fp =  fopen(str, "r");
  if ( fp == NULL )  
        printf( "File doesn't exist !\n" ) ; 
  else
  {
  	fseek(fp, 0L, SEEK_END);
	numbytes = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    buffer = (unsigned char*)calloc(numbytes, sizeof(char));	
    if(buffer == NULL)
    {
    	printf("Memory error !\n");
    	return 1;
    }
    fread(buffer, sizeof(char), numbytes, fp);
	fclose(fp);	
	printf("The file contains this text\n\n%s", buffer);
	printf("\n\n");
  	printf("The Message Digest using SHA-1: \n");
  	
  	SHA1(buffer, strlen((char*)buffer), result);
  	for(int i = 0; i < SHA_DIGEST_LENGTH; i++)
    	printf("%02x%c", result[i], i < (SHA_DIGEST_LENGTH-1) ? ' ' : '\n');
    	
   }
  return 0;
}

/* 	Command to install openssl
	sudo apt-get install libssl-dev
	Command to run:
    gcc sha1.c -lcrypto -o sha1
    ./sha1 gh
*/
