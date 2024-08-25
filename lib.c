#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include<assert.h>
#include<time.h>
void _6e5d_c0date_usleep(uint64_t u);
uint64_t _6e5d_c0date_now();
void _6e5d_c0date_usleep(uint64_t u){
	auto struct timespec ts = {.tv_sec=(u/1000000),.tv_nsec=(1000*(u%1000000)),};
	nanosleep((&ts),NULL);
}
uint64_t _6e5d_c0date_now(){
	auto struct timespec spec;
	clock_gettime(CLOCK_REALTIME,(&spec));
	return ((uint64_t )(((spec.tv_sec)*1000000)+((spec.tv_nsec)/1000)));
}
