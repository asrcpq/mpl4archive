#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include<assert.h>
typedef struct _6e5d_mpl3_Term _6e5d_mpl3_Term;
typedef struct _6e5d_hashmap_Hashmap _6e5d_hashmap_Hashmap;
typedef struct _6e5d_hashmap_Iter _6e5d_hashmap_Iter;
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
struct _6e5d_hashmap_Iter{
	uint8_t (*entry);
	void (*key);
	void (*value);
	uint8_t (*end);
};
void _6e5d_hashmap_initstr(_6e5d_hashmap_Hashmap (*map),uint32_t size_value);
void _6e5d_hashmap_init(_6e5d_hashmap_Hashmap (*map),size_t size_key,size_t size_value);
void _6e5d_hashmap_deinit(_6e5d_hashmap_Hashmap (*map));
_6e5d_hashmap_Iter _6e5d_hashmap_iter(_6e5d_hashmap_Hashmap (*p));
bool _6e5d_hashmap_next(_6e5d_hashmap_Hashmap (*p),_6e5d_hashmap_Iter (*it));
void (*_6e5d_hashmap_get(_6e5d_hashmap_Hashmap (*map),void (*key)));
void _6e5d_hashmap_insertv(_6e5d_hashmap_Hashmap (*map),void (*key),void (*value));
void _6e5d_mpl3pmap_init();
void _6e5d_mpl3pmap_deinit();
uint32_t _6e5d_mpl3pmap_getp(char (*name));
char (*_6e5d_mpl3pmap_getn(uint32_t pid));
uint32_t _6e5d_mpl3pmap_getpi(char (*name));
void _6e5d_mpl3pmap_displayPid(FILE (*f),uint32_t pid);
void _6e5d_mpl3pmap_displayFact(FILE (*f),uint32_t fact[3]);
void _6e5d_mpl3pmap_display(FILE (*f),_6e5d_mpl3_Term s[4]);
uint32_t _6e5d_mpl3pmap_invent();
static _6e5d_hashmap_Hashmap n2p;
static _6e5d_hashmap_Hashmap p2n;
static uint32_t cid;
static uint32_t pid;
void _6e5d_mpl3pmap_init(){
	_6e5d_hashmap_initstr((&n2p),((size_t )(&((uint32_t (*))0)[1])));
	_6e5d_hashmap_init((&p2n),((size_t )(&((uint32_t (*))0)[1])),((size_t )(&((char (*(*)))0)[1])));
	(cid=(1+(1u<<30)));
	(pid=1);
}
void _6e5d_mpl3pmap_deinit(){
	for(auto _6e5d_hashmap_Iter iter = _6e5d_hashmap_iter((&n2p));_6e5d_hashmap_next((&n2p),(&iter));){
		auto char (*(*pp)) = (iter.key);
		free((*pp));
	};
	_6e5d_hashmap_deinit((&n2p));
	_6e5d_hashmap_deinit((&p2n));
}
uint32_t _6e5d_mpl3pmap_getp(char (*name)){
	auto uint32_t (*ret) = _6e5d_hashmap_get((&n2p),(&name));
	if((ret==NULL)){
		return 0;
	}else if(true){
		return (*ret);
	};
}
char (*_6e5d_mpl3pmap_getn(uint32_t pid)){
	auto char (*(*x)) = _6e5d_hashmap_get((&p2n),(&pid));
	if((x==NULL)){
		return NULL;
	}else if(true){
		return (*x);
	};
}
uint32_t _6e5d_mpl3pmap_getpi(char (*name)){
	auto uint32_t ret = _6e5d_mpl3pmap_getp(name);
	if((ret!=0)){
		return ret;
	};
	auto char firstch = (*name);
	auto bool isconst = ((firstch>='\x41')&&(firstch<='\x5a'));
	if(isconst){
		(ret=cid);
		(cid+=1);
	}else if(true){
		(ret=_6e5d_mpl3pmap_invent());
	};
	auto size_t len = (strlen(name)+1);
	auto char (*copied) = malloc(len);
	assert(copied);
	strcpy(copied,name);
	_6e5d_hashmap_insertv((&n2p),(&copied),(&ret));
	_6e5d_hashmap_insertv((&p2n),(&ret),(&copied));
	return ret;
}
void _6e5d_mpl3pmap_displayPid(FILE (*f),uint32_t pid){
	auto char (*name) = _6e5d_mpl3pmap_getn(pid);
	if((name==NULL)){
		fprintf(f,"_%u",pid);
	}else if(true){
		fprintf(f,"%s",name);
	};
}
void _6e5d_mpl3pmap_displayFact(FILE (*f),uint32_t fact[3]){
	for(auto size_t idx = 0;(idx<3);(idx+=1)){
		auto uint32_t p = fact[idx];
		if((p==0)){
			break;
		};
		if((idx!=0)){
			fprintf(f," ");
		};
		_6e5d_mpl3pmap_displayPid(f,p);
	};
}
void _6e5d_mpl3pmap_display(FILE (*f),_6e5d_mpl3_Term s[4]){
	for(auto size_t idx = 0;(idx<4);(idx+=1)){
		auto uint32_t p = (s->p);
		if((p==0)){
			break;
		};
		if(((1u<<31)&p)){
			fprintf(f,"!");
			(p^=(1u<<31));
		};
		auto char (*name) = _6e5d_mpl3pmap_getn(p);
		if((name==NULL)){
			fprintf(f,"_%u(",p);
		}else if(true){
			fprintf(f,"%s(",name);
		};
		fprintf(f,"%hd,",(s->u));
		fprintf(f,"%hd)",(s->v));
		(s+=1);
	};
}
uint32_t _6e5d_mpl3pmap_invent(){
	assert((pid<(1u<<30)));
	(pid+=1);
	return (pid-1);
}
