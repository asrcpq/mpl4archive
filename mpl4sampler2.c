#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include<assert.h>
typedef struct _6e5d_vec_Vec _6e5d_vec_Vec;
typedef struct _6e5d_mpl3_Term _6e5d_mpl3_Term;
typedef struct _6e5d_hashmap_Hashmap _6e5d_hashmap_Hashmap;
typedef struct _6e5d_mpl4kb2_Kb _6e5d_mpl4kb2_Kb;
struct _6e5d_vec_Vec{
	size_t size;
	size_t capacity;
	size_t len;
	void (*p);
};
struct _6e5d_mpl3_Term{
	uint32_t p;
	int16_t u;
	int16_t v;
};
struct _6e5d_hashmap_Hashmap{
	size_t size_key;
	size_t size_value;
	size_t size_entry;
	size_t len;
	void (*buckets);
	uint8_t bitshift;
	uint64_t (*hasher)(void (*),size_t );
	bool (*eq)(void (*),void (*),size_t );
};
struct _6e5d_mpl4kb2_Kb{
	_6e5d_hashmap_Hashmap lookup;
	_6e5d_hashmap_Hashmap facts;
	_6e5d_vec_Vec rules;
};
int8_t _6e5d_mpl3_normalize(_6e5d_mpl3_Term (*s),size_t len);
uint32_t _6e5d_mpl3_pneg(uint32_t p);
void (*_6e5d_hashmap_get(_6e5d_hashmap_Hashmap (*map),void (*key)));
uint64_t _6e5d_rand_u64();
uint32_t samplestep(_6e5d_mpl4kb2_Kb (*kb),uint32_t start,uint32_t facts[5][3],size_t step);
void facts2s(_6e5d_mpl3_Term s[4],uint32_t start,uint32_t walk,uint32_t next,uint32_t f0[3],uint32_t f1[3],uint32_t f2[3]);
size_t _6e5d_mpl4sampler2_sample(_6e5d_mpl4kb2_Kb (*kb),uint32_t pos[3],_6e5d_mpl3_Term out[4][4],uint32_t (*pi));
uint32_t samplestep(_6e5d_mpl4kb2_Kb (*kb),uint32_t start,uint32_t facts[5][3],size_t step){
	auto _6e5d_vec_Vec (*vneigh) = _6e5d_hashmap_get((&(kb->lookup)),(&start));
	assert(vneigh);
	auto size_t nlen = (vneigh->len);
	assert((0<nlen));
	auto size_t idn = (_6e5d_rand_u64()%nlen);
	auto uint32_t (*f) = ((void (*))(((uint8_t (*))(vneigh->p))+(idn*(vneigh->size))));
	memcpy(facts[step],f,((size_t )(&((uint32_t (*)[3])0)[1])));
	if((start==f[2])){
		return f[1];
	}else if(true){
		return f[2];
	};
}
void facts2s(_6e5d_mpl3_Term s[4],uint32_t start,uint32_t walk,uint32_t next,uint32_t f0[3],uint32_t f1[3],uint32_t f2[3]){
	auto int16_t v0u;
	auto int16_t v0v;
	if((f0[1]==start)){
		(v0u=1);
	}else if((f0[1]==walk)){
		(v0u=2);
	}else if((f0[1]==next)){
		(v0u=3);
	}else if(true){
		fprintf(stderr,"%u %u %u %u""\x0a""",f0[1],start,walk,next);
		abort();
	};
	if((f0[2]==start)){
		(v0v=1);
	}else if((f0[2]==walk)){
		(v0v=2);
	}else if((f0[2]==next)){
		(v0v=3);
	}else if(true){
		fprintf(stderr,"%u %u %u %u""\x0a""",f0[2],start,walk,next);
		abort();
	};
	auto int16_t v1u;
	auto int16_t v1v;
	if((f1[1]==start)){
		(v1u=1);
	}else if((f1[1]==walk)){
		(v1u=2);
	}else if((f1[1]==next)){
		(v1u=3);
	}else if(true){
		fprintf(stderr,"%u %u %u %u""\x0a""",f1[1],start,walk,next);
		abort();
	};
	if((f1[2]==start)){
		(v1v=1);
	}else if((f1[2]==walk)){
		(v1v=2);
	}else if((f1[2]==next)){
		(v1v=3);
	}else if(true){
		fprintf(stderr,"%u %u %u %u""\x0a""",f1[2],start,walk,next);
		abort();
	};
	auto int16_t v2u;
	auto int16_t v2v;
	if((f2[1]==start)){
		(v2u=1);
	}else if((f2[1]==walk)){
		(v2u=2);
	}else if((f2[1]==next)){
		(v2u=3);
	}else if(true){
		fprintf(stderr,"%u %u %u %u""\x0a""",f2[1],start,walk,next);
		abort();
	};
	if((f2[2]==start)){
		(v2v=1);
	}else if((f2[2]==walk)){
		(v2v=2);
	}else if((f2[2]==next)){
		(v2v=3);
	}else if(true){
		fprintf(stderr,"%u %u %u %u""\x0a""",f2[2],start,walk,next);
		abort();
	};
	(s[0]=((_6e5d_mpl3_Term ){.p=f0[0],.u=v0u,.v=v0v,}));
	(s[1]=((_6e5d_mpl3_Term ){.p=_6e5d_mpl3_pneg(f1[0]),.u=v1u,.v=v1v,}));
	(s[2]=((_6e5d_mpl3_Term ){.p=_6e5d_mpl3_pneg(f2[0]),.u=v2u,.v=v2v,}));
	assert(_6e5d_mpl3_normalize(s,3));
}
size_t _6e5d_mpl4sampler2_sample(_6e5d_mpl4kb2_Kb (*kb),uint32_t pos[3],_6e5d_mpl3_Term out[4][4],uint32_t (*pi)){
	auto size_t startidx = (_6e5d_rand_u64()%2);
	auto uint32_t start = pos[(startidx+1)];
	auto uint32_t end = pos[(2-startidx)];
	auto uint32_t walk;
	auto uint32_t next = start;
	auto uint32_t facts[5][3];
	auto uint32_t bridge[3];
	for(auto size_t step = 0;(step<(4+1));(step+=1)){
		(walk=next);
		(next=samplestep(kb,walk,facts,step));
		if((next==0)){
			return 0;
		};
		if((step==0)){
			memcpy(bridge,facts[0],((size_t )(&((uint32_t (*)[3])0)[1])));
			continue;
		};
		if(((next==walk)&&(_6e5d_rand_u64()%2))){
			(next=start);
		};
		auto uint32_t (*fact) = facts[step];
		auto bool stop = (((end==next)&&((step==4)||(((uint8_t )_6e5d_rand_u64())<=128)))||((step==1)&&(end==start)&&(((uint8_t )_6e5d_rand_u64())<=32)));
		if(((step==4)&&(!stop))){
			return 0;
		};
		auto uint32_t bnext[3];
		auto uint32_t newp;
		if(stop){
			memcpy(bnext,pos,((size_t )(&((uint32_t (*)[3])0)[1])));
		}else if(true){
			(newp=(*pi));
			((*pi)+=1);
			auto uint32_t f[3] = {newp,start,next,};
			memcpy(bnext,f,((size_t )(&((uint32_t (*)[3])0)[1])));
		};
		auto _6e5d_mpl3_Term (*s) = out[(step-1)];
		facts2s(s,start,walk,next,bnext,fact,bridge);
		if((!stop)){
			memcpy(bridge,bnext,((size_t )(&((uint32_t (*)[3])0)[1])));
			continue;
		};
		auto bool dup1 = ((step==1)&&(((uint8_t )_6e5d_rand_u64())<96)&&(0!=(out[0][2].p)));
		if((!dup1)){
			return step;
		};
		memcpy(out[1],out[0],((size_t )(&((_6e5d_mpl3_Term (*)[4])0)[1])));
		auto _6e5d_mpl3_Term (*rule) = out[1];
		auto _6e5d_mpl3_Term (*last) = out[0];
		(newp=(*pi));
		((*pi)+=1);
		auto uint32_t f[3] = {newp,start,next,};
		memcpy(bnext,f,((size_t )(&((uint32_t (*)[3])0)[1])));
		facts2s(last,start,walk,next,bnext,fact,bridge);
		assert(_6e5d_mpl3_normalize(last,3));
		assert(_6e5d_mpl3_normalize(rule,3));
		return 2;
	};
	abort();
}
