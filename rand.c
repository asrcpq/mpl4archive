#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include<assert.h>
uint64_t _6e5d_rand_xorshift128p(uint64_t state[2]);
void _6e5d_rand_seed(uint64_t s);
uint64_t _6e5d_rand_u64();
float _6e5d_rand_f32();
uint64_t _6e5d_rand_xorshift128p(uint64_t state[2]){
	{
		auto uint64_t t = state[0];
		auto uint64_t s = state[1];
		(state[0]=s);
		(t^=(t<<23));
		(t^=(t>>18));
		(t^=(s^(s>>5)));
		(state[1]=t);
		return (t+s);
	};
}
thread_local uint64_t rand_state[2] = {0x243F6A8885A308D3,0x13198A2E03707344,};
void _6e5d_rand_seed(uint64_t s){
	(rand_state[0]=s);
}
uint64_t _6e5d_rand_u64(){
	return _6e5d_rand_xorshift128p(rand_state);
}
float _6e5d_rand_f32(){
	return (((float )_6e5d_rand_u64())/(1+((float )UINT64_MAX)));
}
