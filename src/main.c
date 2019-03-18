/*
 * main.c
 *
 *  Created on: May 1, 2017
 *      Author: pos
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <curl/curl.h>

int main(int argc,char *argv[]){
	CURL *curl;
	CURLcode res;
	char url[80];
	void *buffer;
	buffer = malloc(1000);
	int size_t =  1000;
	int *size;

	printf("Hello world\n");
	strcpy(url,"http://192.168.0.22:8080/getMenus");
	curl = curl_easy_init();
	if(curl){
		curl_easy_setopt(curl,CURLOPT_URL,url);
		curl_easy_setopt(curl,CURLOPT_POSTFIELDS,"peter kimari");
		res = curl_easy_perform(curl);
		printf("Res:%d\n",res);
		//res = curl_easy_recv(curl,buffer,size_t,size);
		//printf("Buffer content::%s\n",buffer);
		curl_easy_cleanup(curl);
	}
	return 0;
}
