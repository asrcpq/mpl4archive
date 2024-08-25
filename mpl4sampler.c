#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include<assert.h>
typedef struct _6e5d_hashmap_Hashmap _6e5d_hashmap_Hashmap;
typedef struct _6e5d_vec_Vec _6e5d_vec_Vec;
typedef struct _6e5d_mpl4kb2_Kb _6e5d_mpl4kb2_Kb;
typedef struct _6e5d_mpl3_Term _6e5d_mpl3_Term;
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
struct _6e5d_vec_Vec{
	size_t size;
	size_t capacity;
	size_t len;
	void (*p);
};
struct _6e5d_mpl4kb2_Kb{
	_6e5d_hashmap_Hashmap lookup;
	_6e5d_hashmap_Hashmap facts;
	_6e5d_vec_Vec rules;
};
struct _6e5d_mpl3_Term{
	uint32_t p;
	int16_t u;
	int16_t v;
};
int8_t _6e5d_mpl3_normalize(_6e5d_mpl3_Term (*s),size_t len);
uint32_t _6e5d_mpl3_pneg(uint32_t p);
void (*_6e5d_hashmap_get(_6e5d_hashmap_Hashmap (*map),void (*key)));
uint64_t _6e5d_rand_u64();
bool sampleNeigh(_6e5d_vec_Vec (*v),uint32_t dup[6][3],size_t duplen,uint32_t out[3]);
void vecins(uint32_t (*v),size_t (*vlen),uint32_t new);
bool _6e5d_mpl4sampler_sampleNp(_6e5d_mpl4kb2_Kb (*kb),uint32_t pos[3],size_t len,uint32_t out[6][3]);
bool _6e5d_mpl4sampler_sampleTpw(_6e5d_mpl4kb2_Kb (*kb),uint32_t pos[3],size_t len,uint32_t out[6][3]);
int16_t pid2i(uint32_t (*cs),uint32_t pid);
bool foldstep(uint32_t subg[6][3],size_t (*l),uint32_t pos[3],uint32_t (*pi),_6e5d_mpl3_Term out[6][4],size_t (*outlen));
size_t _6e5d_mpl4sampler_fold(uint32_t subg[6][3],size_t l,uint32_t pos[3],uint32_t (*pi),_6e5d_mpl3_Term out[6][4]);
bool sampleNeigh(_6e5d_vec_Vec (*v),uint32_t dup[6][3],size_t duplen,uint32_t out[3]){
	auto size_t len = (v->len);
	assert((0<len));
	for(auto size_t idx = 0;(idx<5);(idx+=1)){
		auto size_t idx = (_6e5d_rand_u64()%len);
		auto uint32_t (*f) = ((void (*))(((uint8_t (*))(v->p))+(idx*(v->size))));
		auto bool dupflag = false;
		for(auto size_t idy = 0;(idy<duplen);(idy+=1)){
			auto uint32_t (*d) = dup[idy];
			if((0==memcmp(d,f,((size_t )(&((uint32_t (*)[3])0)[1]))))){
				(dupflag=true);
				break;
			};
		};
		if(dupflag){
			return false;
		};
		memcpy(out,f,((size_t )(&((uint32_t (*)[3])0)[1])));
		return true;
	};
	return false;
}
void vecins(uint32_t (*v),size_t (*vlen),uint32_t new){
	for(auto size_t idx = 0;(idx<(*vlen));(idx+=1)){
		if((new==v[idx])){
			return ;
		};
	};
	(v[(*vlen)]=new);
	((*vlen)+=1);
}
bool _6e5d_mpl4sampler_sampleNp(_6e5d_mpl4kb2_Kb (*kb),uint32_t pos[3],size_t len,uint32_t out[6][3]){
	assert((len<=6));
	auto uint32_t vs[7];
	(vs[0]=pos[1]);
	auto size_t vlen = 1;
	if((pos[2]!=pos[1])){
		(vs[1]=pos[2]);
		(vlen=2);
	};
	for(auto size_t idx = 0;(idx<len);(idx+=1)){
		auto size_t vid = (_6e5d_rand_u64()%vlen);
		auto uint32_t pid = vs[vid];
		auto _6e5d_vec_Vec (*v) = _6e5d_hashmap_get((&(kb->lookup)),(&pid));
		assert(v);
		if((!sampleNeigh(v,out,idx,out[idx]))){
			return false;
		};
		auto uint32_t (*newfact) = out[idx];
		vecins(vs,(&vlen),newfact[1]);
		if((newfact[2]!=newfact[1])){
			vecins(vs,(&vlen),newfact[2]);
		};
	};
	return true;
}
bool _6e5d_mpl4sampler_sampleTpw(_6e5d_mpl4kb2_Kb (*kb),uint32_t pos[3],size_t len,uint32_t out[6][3]){
	assert((len<=6));
	auto uint32_t v1 = pos[1];
	auto uint32_t v2 = pos[2];
	auto size_t walk = (_6e5d_rand_u64()%(1+len));
	for(auto size_t idx = 0;(idx<walk);(idx+=1)){
		auto _6e5d_vec_Vec (*vneigh) = _6e5d_hashmap_get((&(kb->lookup)),(&v1));
		assert(vneigh);
		auto size_t idn = (_6e5d_rand_u64()%(vneigh->len));
		auto uint32_t (*f) = ((void (*))(((uint8_t (*))(vneigh->p))+(idn*(vneigh->size))));
		for(auto size_t idy = 0;(idy<idx);(idy+=1)){
			if((0==memcmp(out[idy],f,((size_t )(&((uint32_t (*)[3])0)[1]))))){
				if((((uint8_t )_6e5d_rand_u64())<128)){
					return false;
				};
			};
		};
		memcpy(out[idx],f,((size_t )(&((uint32_t (*)[3])0)[1])));
		if((v1==f[1])){
			(v1=f[2]);
		}else if(true){
			(v1=f[1]);
		};
	};
	for(auto size_t idx = walk;(idx<len);(idx+=1)){
		auto _6e5d_vec_Vec (*vneigh) = _6e5d_hashmap_get((&(kb->lookup)),(&v2));
		assert(vneigh);
		auto size_t idn = (_6e5d_rand_u64()%(vneigh->len));
		auto uint32_t (*f) = ((void (*))(((uint8_t (*))(vneigh->p))+(idn*(vneigh->size))));
		for(auto size_t idy = 0;(idy<idx);(idy+=1)){
			if((0==memcmp(out[idy],f,((size_t )(&((uint32_t (*)[3])0)[1]))))){
				if((((uint8_t )_6e5d_rand_u64())<128)){
					return false;
				};
			};
		};
		memcpy(out[idx],f,((size_t )(&((uint32_t (*)[3])0)[1])));
		if((v2==f[1])){
			(v2=f[2]);
		}else if(true){
			(v2=f[1]);
		};
	};
	return true;
}
int16_t pid2i(uint32_t (*cs),uint32_t pid){
	if((pid==cs[0])){
		return 1;
	};
	if((pid==cs[1])){
		return 2;
	};
	if((pid==cs[2])){
		return 3;
	};
	abort();
}
bool foldstep(uint32_t subg[6][3],size_t (*l),uint32_t pos[3],uint32_t (*pi),_6e5d_mpl3_Term out[6][4],size_t (*outlen)){
	if(((*l)<=1)){
		return false;
	};
	auto size_t ide1 = (_6e5d_rand_u64()%(*l));
	auto size_t ide2 = (_6e5d_rand_u64()%((*l)-1));
	if((ide2<ide1)){
		auto size_t tmp = ide2;
		(ide2=ide1);
		(ide1=tmp);
	}else if(true){
		(ide2+=1);
	};
	auto uint32_t (*f1) = subg[ide1];
	auto uint32_t (*f2) = subg[ide2];
	if(((f1[1]!=f2[1])&&(f1[1]!=f2[2])&&(f1[2]!=f2[1])&&(f1[2]!=f2[2]))){
		return false;
	};
	auto uint32_t cs[4];
	auto size_t clen = 1;
	(cs[0]=f1[1]);
	vecins(cs,(&clen),f1[2]);
	vecins(cs,(&clen),f2[1]);
	vecins(cs,(&clen),f2[2]);
	if((clen==4)){
		return false;
	};
	auto size_t idc1 = (_6e5d_rand_u64()%clen);
	auto size_t idc2 = (_6e5d_rand_u64()%clen);
	auto uint32_t pid1 = cs[idc1];
	auto uint32_t pid2 = cs[idc2];
	auto _6e5d_mpl3_Term sent[4] = {0,};
	auto uint32_t newpi = 0;
	if((2==(*l))){
		auto uint32_t p1;
		auto uint32_t p2;
		if((pid1==pos[1])){
			(p1=pid1);
		}else if((pid2==pos[1])){
			(p1=pid2);
		}else if(true){
			return false;
		};
		if((pid1==pos[2])){
			(p2=pid1);
		}else if((pid2==pos[2])){
			(p2=pid2);
		}else if(true){
			return false;
		};
		(sent[0]=((_6e5d_mpl3_Term ){.p=pos[0],.u=pid2i(cs,p1),.v=pid2i(cs,p2),}));
	}else if(true){
		(newpi=(*pi));
		((*pi)+=1);
		(sent[0]=((_6e5d_mpl3_Term ){.p=newpi,.u=pid2i(cs,pid1),.v=pid2i(cs,pid2),}));
	};
	(sent[1]=((_6e5d_mpl3_Term ){.p=_6e5d_mpl3_pneg(f1[0]),.u=pid2i(cs,f1[1]),.v=pid2i(cs,f1[2]),}));
	if((ide1!=ide2)){
		(sent[2]=((_6e5d_mpl3_Term ){.p=_6e5d_mpl3_pneg(f2[0]),.u=pid2i(cs,f2[1]),.v=pid2i(cs,f2[2]),}));
		if((0>_6e5d_mpl3_normalize(sent,3))){
			return false;
		};
	}else if(true){
		if((0>_6e5d_mpl3_normalize(sent,2))){
			return false;
		};
	};
	((*l)-=1);
	memcpy(subg[ide2],subg[(*l)],((size_t )(&((uint32_t (*)[3])0)[1])));
	if((ide2!=ide1)){
		((*l)-=1);
		memcpy(subg[ide1],subg[(*l)],((size_t )(&((uint32_t (*)[3])0)[1])));
	};
	memcpy(out[(*outlen)],sent,((size_t )(&((_6e5d_mpl3_Term (*)[4])0)[1])));
	((*outlen)+=1);
	if(((*l)==0)){
		return true;
	};
	(subg[(*l)][0]=newpi);
	(subg[(*l)][1]=pid1);
	(subg[(*l)][2]=pid2);
	((*l)+=1);
	return true;
}
size_t _6e5d_mpl4sampler_fold(uint32_t subg[6][3],size_t l,uint32_t pos[3],uint32_t (*pi),_6e5d_mpl3_Term out[6][4]){
	assert((l>0));
	assert((pos[0]>0));
	auto size_t outlen = 0;
	for(auto size_t attempt = 0;(attempt<6);(attempt+=1)){
		if((!foldstep(subg,(&l),pos,pi,out,(&outlen)))){
			return 0;
		};
		if((l==0)){
			return outlen;
		};
	};
	return 0;
}
