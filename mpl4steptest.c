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
void _6e5d_vec_deinit(_6e5d_vec_Vec (*v));
size_t _6e5d_mpl4sampler2_sample(_6e5d_mpl4kb2_Kb (*kb),uint32_t pos[3],_6e5d_mpl3_Term out[4][4],uint32_t (*pi));
bool _6e5d_mpl4sampler_sampleTpw(_6e5d_mpl4kb2_Kb (*kb),uint32_t pos[3],size_t len,uint32_t out[6][3]);
size_t _6e5d_mpl4sampler_fold(uint32_t subg[6][3],size_t l,uint32_t pos[3],uint32_t (*pi),_6e5d_mpl3_Term out[6][4]);
bool _6e5d_hashmap_contains(_6e5d_hashmap_Hashmap (*map),void (*key));
uint64_t _6e5d_rand_u64();
void _6e5d_mpl4kb2_deinit(_6e5d_mpl4kb2_Kb (*kb));
void _6e5d_mpl4kb2_addRule(_6e5d_mpl4kb2_Kb (*kb),_6e5d_mpl3_Term (*rule));
typedef struct _6e5d_mpl4steptest_Node _6e5d_mpl4steptest_Node;
struct _6e5d_mpl4steptest_Node{
	_6e5d_mpl4kb2_Kb kb;
	_6e5d_vec_Vec abduced;
	_6e5d_vec_Vec sources;
	uint32_t pi;
};
void _6e5d_mpl4steptest_nodeDeinit(_6e5d_mpl4steptest_Node (*node));
size_t _6e5d_mpl4steptest_step2(_6e5d_mpl4steptest_Node (*node),_6e5d_mpl3_Term out[6][4],uint32_t (*opi),size_t (*select));
size_t _6e5d_mpl4steptest_step(_6e5d_mpl4steptest_Node (*node),_6e5d_mpl3_Term out[6][4],uint32_t (*opi),size_t (*select));
bool _6e5d_mpl4steptest_buildkb(_6e5d_mpl3_Term out[6][4],size_t olen,_6e5d_mpl4kb2_Kb (*kb2),_6e5d_vec_Vec (*negs));
void _6e5d_mpl4steptest_nodeDeinit(_6e5d_mpl4steptest_Node (*node)){
	_6e5d_mpl4kb2_deinit((&(node->kb)));
	_6e5d_vec_deinit((&(node->abduced)));
	_6e5d_vec_deinit((&(node->sources)));
}
size_t _6e5d_mpl4steptest_step2(_6e5d_mpl4steptest_Node (*node),_6e5d_mpl3_Term out[6][4],uint32_t (*opi),size_t (*select)){
	auto uint32_t pi = (node->pi);
	auto size_t abidx = (_6e5d_rand_u64()%((node->abduced).len));
	((*select)=abidx);
	auto uint32_t pos[3];
	memcpy(pos,((void (*))(((uint8_t (*))((&(node->abduced))->p))+(abidx*((&(node->abduced))->size)))),((size_t )(&((uint32_t (*)[3])0)[1])));
	auto size_t olen = _6e5d_mpl4sampler2_sample((&(node->kb)),pos,out,(&pi));
	if((0==olen)){
		return 0;
	};
	((*opi)=pi);
	return olen;
}
size_t _6e5d_mpl4steptest_step(_6e5d_mpl4steptest_Node (*node),_6e5d_mpl3_Term out[6][4],uint32_t (*opi),size_t (*select)){
	while(true){
		auto uint32_t pi = (node->pi);
		auto size_t len = (2+(_6e5d_rand_u64()%4));
		auto uint32_t subg[6][3];
		auto size_t abidx = (_6e5d_rand_u64()%((node->abduced).len));
		((*select)=abidx);
		auto uint32_t pos[3];
		memcpy(pos,((void (*))(((uint8_t (*))((&(node->abduced))->p))+(abidx*((&(node->abduced))->size)))),((size_t )(&((uint32_t (*)[3])0)[1])));
		auto bool ok = _6e5d_mpl4sampler_sampleTpw((&(node->kb)),pos,len,subg);
		if((!ok)){
			continue;
		};
		auto size_t olen = _6e5d_mpl4sampler_fold(subg,len,pos,(&pi),out);
		if((0==olen)){
			continue;
		};
		((*opi)=pi);
		return olen;
	};
}
bool _6e5d_mpl4steptest_buildkb(_6e5d_mpl3_Term out[6][4],size_t olen,_6e5d_mpl4kb2_Kb (*kb2),_6e5d_vec_Vec (*negs)){
	for(auto size_t idx = 0;(idx<olen);(idx+=1)){
		_6e5d_mpl4kb2_addRule(kb2,out[idx]);
	};
	for(auto uint32_t (*iter)[3] = (negs->p);(((void (*))iter)<((void (*))(((uint8_t (*))(negs->p))+((negs->len)*(negs->size)))));(iter+=1)){
		if(_6e5d_hashmap_contains((&(kb2->facts)),iter)){
			return false;
		};
	};
	return true;
}
