#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include<assert.h>
typedef struct _6e5d_hashmap_Iter _6e5d_hashmap_Iter;
typedef struct _6e5d_hashmap_Hashmap _6e5d_hashmap_Hashmap;
struct _6e5d_hashmap_Iter{
	uint8_t (*entry);
	void (*key);
	void (*value);
	uint8_t (*end);
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
uint64_t u64v(uint8_t (*p));
uint64_t (*u64p(uint8_t (*p)));
uint64_t _6e5d_hashmap_fnv1astr(void (*v),size_t len);
uint64_t _6e5d_hashmap_fnv1a(void (*v),size_t len);
bool _6e5d_hashmap_memeq(void (*p1),void (*p2),size_t len);
bool _6e5d_hashmap_streq(void (*p1),void (*p2),size_t len);
uint64_t _6e5d_hashmap_hash(_6e5d_hashmap_Hashmap (*map),uint8_t (*p),size_t len);
void _6e5d_hashmap_init(_6e5d_hashmap_Hashmap (*map),size_t size_key,size_t size_value);
void _6e5d_hashmap_initstr(_6e5d_hashmap_Hashmap (*map),uint32_t size_value);
void _6e5d_hashmap_deinit(_6e5d_hashmap_Hashmap (*map));
uint64_t shift_hash(_6e5d_hashmap_Hashmap (*map),uint64_t hsh);
void (*getEntry(_6e5d_hashmap_Hashmap (*map),uint64_t hsh,void (*key)));
void (*_6e5d_hashmap_getk(_6e5d_hashmap_Hashmap (*map),void (*key)));
void (*_6e5d_hashmap_get(_6e5d_hashmap_Hashmap (*map),void (*key)));
bool _6e5d_hashmap_contains(_6e5d_hashmap_Hashmap (*map),void (*key));
void _6e5d_hashmap_debug(_6e5d_hashmap_Hashmap (*map));
void (*do_insert(_6e5d_hashmap_Hashmap (*map),void (*key),bool overwrite));
void _6e5d_hashmap_resize(_6e5d_hashmap_Hashmap (*map),uint8_t bitshift);
void _6e5d_hashmap_reserve(_6e5d_hashmap_Hashmap (*map),size_t upcoming);
void _6e5d_hashmap_insertv(_6e5d_hashmap_Hashmap (*map),void (*key),void (*value));
void (*_6e5d_hashmap_add(_6e5d_hashmap_Hashmap (*map),void (*key)));
bool _6e5d_hashmap_addv(_6e5d_hashmap_Hashmap (*map),void (*key),void (*value));
bool _6e5d_hashmap_remove(_6e5d_hashmap_Hashmap (*map),void (*key));
bool _6e5d_hashmap_next(_6e5d_hashmap_Hashmap (*p),_6e5d_hashmap_Iter (*it));
_6e5d_hashmap_Iter _6e5d_hashmap_iter(_6e5d_hashmap_Hashmap (*p));
void _6e5d_hashmap_clear(_6e5d_hashmap_Hashmap (*p));
void _6e5d_hashmap_copy(_6e5d_hashmap_Hashmap (*i),_6e5d_hashmap_Hashmap (*o));
uint64_t u64v(uint8_t (*p)){
	return (*((uint64_t (*))((void (*))p)));
}
uint64_t (*u64p(uint8_t (*p))){
	return ((uint64_t (*))((void (*))p));
}
uint64_t _6e5d_hashmap_fnv1astr(void (*v),size_t len){
	auto uint8_t (*(*p)) = v;
	((void )len);
	auto uint64_t hsh = 0xcbf29ce484222325lu;
	for(auto uint8_t (*pp) = (*p);((*pp)!=0);(pp+=1)){
		(hsh^=(*pp));
		(hsh*=0x100000001b3lu);
	};
	return hsh;
}
uint64_t _6e5d_hashmap_fnv1a(void (*v),size_t len){
	auto uint8_t (*p) = v;
	auto uint64_t hsh = 0xcbf29ce484222325lu;
	for(auto size_t i = 0;(i<len);(i+=1)){
		(hsh^=(*p));
		(hsh*=0x100000001b3lu);
		(p+=1);
	};
	return hsh;
}
bool _6e5d_hashmap_memeq(void (*p1),void (*p2),size_t len){
	return (0==memcmp(p1,p2,len));
}
bool _6e5d_hashmap_streq(void (*p1),void (*p2),size_t len){
	((void )len);
	auto char (*(*pp1)) = p1;
	auto char (*(*pp2)) = p2;
	return (0==strcmp((*pp1),(*pp2)));
}
uint64_t _6e5d_hashmap_hash(_6e5d_hashmap_Hashmap (*map),uint8_t (*p),size_t len){
	auto uint64_t hsh = (map->hasher)(p,len);
	return (hsh|(1lu<<63));
}
void _6e5d_hashmap_init(_6e5d_hashmap_Hashmap (*map),size_t size_key,size_t size_value){
	auto size_t size_entry = (size_key+size_value+8);
	auto void (*buckets) = calloc(2,size_entry);
	assert((buckets!=NULL));
	((*map)=((_6e5d_hashmap_Hashmap ){.size_key=size_key,.size_value=size_value,.size_entry=size_entry,.len=0,.bitshift=1,.buckets=buckets,.hasher=_6e5d_hashmap_fnv1a,.eq=_6e5d_hashmap_memeq,}));
}
void _6e5d_hashmap_initstr(_6e5d_hashmap_Hashmap (*map),uint32_t size_value){
	auto size_t size_key = ((size_t )(&((char (*(*)))0)[1]));
	auto size_t size_entry = (size_key+size_value+8);
	auto void (*buckets) = calloc(2,size_entry);
	assert((buckets!=NULL));
	((*map)=((_6e5d_hashmap_Hashmap ){.size_key=size_key,.size_value=size_value,.size_entry=size_entry,.len=0,.bitshift=1,.buckets=buckets,.hasher=_6e5d_hashmap_fnv1astr,.eq=_6e5d_hashmap_streq,}));
}
void _6e5d_hashmap_deinit(_6e5d_hashmap_Hashmap (*map)){
	free((map->buckets));
}
uint64_t shift_hash(_6e5d_hashmap_Hashmap (*map),uint64_t hsh){
	return (hsh%(1<<(map->bitshift)));
}
void (*getEntry(_6e5d_hashmap_Hashmap (*map),uint64_t hsh,void (*key))){
	auto uint8_t (*pent);
	auto uint8_t (*pdelete) = NULL;
	auto uint64_t idx0 = shift_hash(map,hsh);
	auto uint64_t bucket_len = (1<<(map->bitshift));
	auto uint64_t idx = idx0;
	for(auto size_t i = 0;(i<bucket_len);(i+=1)){
		(pent=(((uint8_t (*))(map->buckets))+(idx*(map->size_entry))));
		if((0==u64v(pent))){
			break;
		}else if((1==u64v(pent))){
			if((NULL==pdelete)){
				(pdelete=pent);
			};
		}else if((map->eq)(key,(8+pent),(map->size_key))){
			return pent;
		};
		(idx+=1);
		(idx%=bucket_len);
		if((idx==idx0)){
			assert((NULL!=pdelete));
		};
	};
	if((pdelete!=NULL)){
		return pdelete;
	}else if(true){
		return pent;
	};
}
void (*_6e5d_hashmap_getk(_6e5d_hashmap_Hashmap (*map),void (*key))){
	auto uint64_t hsh = _6e5d_hashmap_hash(map,key,(map->size_key));
	auto uint8_t (*p) = getEntry(map,hsh,key);
	if((0==((1lu<<63)&u64v(p)))){
		return NULL;
	};
	return (p+8);
}
void (*_6e5d_hashmap_get(_6e5d_hashmap_Hashmap (*map),void (*key))){
	auto uint8_t (*p) = _6e5d_hashmap_getk(map,key);
	if((NULL==p)){
		return NULL;
	};
	return (p+(map->size_key));
}
bool _6e5d_hashmap_contains(_6e5d_hashmap_Hashmap (*map),void (*key)){
	auto void (*ret) = _6e5d_hashmap_get(map,key);
	return (NULL!=ret);
}
void _6e5d_hashmap_debug(_6e5d_hashmap_Hashmap (*map)){
	fprintf(stderr,"k=%zu:v=%zu:l=%zu:s=%hhu""\x0a""",(map->size_key),(map->size_value),(map->len),(map->bitshift));
}
void (*do_insert(_6e5d_hashmap_Hashmap (*map),void (*key),bool overwrite)){
	_6e5d_hashmap_reserve(map,1);
	auto uint64_t hsh = _6e5d_hashmap_hash(map,key,(map->size_key));
	auto uint8_t (*p) = getEntry(map,hsh,key);
	auto bool isnew = (1>=u64v(p));
	if(isnew){
		((map->len)+=1);
	}else if((!overwrite)){
		return NULL;
	};
	memcpy(p,(&hsh),8);
	memcpy((p+8),key,(map->size_key));
	return (p+8+(map->size_key));
}
void _6e5d_hashmap_resize(_6e5d_hashmap_Hashmap (*map),uint8_t bitshift){
	auto size_t old_blen = (1<<(map->bitshift));
	((map->bitshift)=bitshift);
	auto size_t new_blen = (1<<bitshift);
	auto uint8_t (*old_buckets) = (map->buckets);
	((map->buckets)=calloc(new_blen,(map->size_entry)));
	assert((NULL!=(map->buckets)));
	for(auto uint8_t (*p) = old_buckets;(p<(old_buckets+(old_blen*(map->size_entry))));(p+=(map->size_entry))){
		auto uint64_t v = u64v(p);
		if((v==0)){
			continue;
		};
		auto uint8_t (*pent) = getEntry(map,v,(p+8));
		memcpy(pent,p,(map->size_entry));
	};
	free(old_buckets);
}
void _6e5d_hashmap_reserve(_6e5d_hashmap_Hashmap (*map),size_t upcoming){
	auto uint8_t bitshift = (map->bitshift);
	auto uint64_t goal = (upcoming+(((map->len)<<4)/12));
	while((goal>=(1ul<<bitshift))){
		(bitshift+=1);
	};
	if((bitshift!=(map->bitshift))){
		_6e5d_hashmap_resize(map,bitshift);
	};
}
void _6e5d_hashmap_insertv(_6e5d_hashmap_Hashmap (*map),void (*key),void (*value)){
	auto void (*v) = do_insert(map,key,true);
	memcpy(v,value,(map->size_value));
}
void (*_6e5d_hashmap_add(_6e5d_hashmap_Hashmap (*map),void (*key))){
	return do_insert(map,key,false);
}
bool _6e5d_hashmap_addv(_6e5d_hashmap_Hashmap (*map),void (*key),void (*value)){
	auto void (*v) = do_insert(map,key,false);
	if((v!=NULL)){
		memcpy(v,value,(map->size_value));
		return true;
	};
	return false;
}
bool _6e5d_hashmap_remove(_6e5d_hashmap_Hashmap (*map),void (*key)){
	auto uint64_t hsh = _6e5d_hashmap_hash(map,key,(map->size_key));
	auto uint8_t (*pent) = getEntry(map,hsh,key);
	if((0==((1lu<<63)&u64v(pent)))){
		return false;
	};
	((map->len)-=1);
	((*u64p(pent))=1);
	return true;
}
bool _6e5d_hashmap_next(_6e5d_hashmap_Hashmap (*p),_6e5d_hashmap_Iter (*it)){
	while(((it->entry)!=(it->end))){
		auto uint64_t hsh = u64v((it->entry));
		if((hsh&(1lu<<63))){
			((it->key)=(8+(it->entry)));
			((it->value)=(((uint8_t (*))(it->key))+(p->size_key)));
			((it->entry)+=(p->size_entry));
			return true;
		};
		((it->entry)+=(p->size_entry));
	};
	return false;
}
_6e5d_hashmap_Iter _6e5d_hashmap_iter(_6e5d_hashmap_Hashmap (*p)){
	auto uint8_t (*entry) = (p->buckets);
	auto size_t bucket_len = (1<<(p->bitshift));
	auto _6e5d_hashmap_Iter it = {.entry=entry,.end=(entry+((p->size_entry)*bucket_len)),};
	return it;
}
void _6e5d_hashmap_clear(_6e5d_hashmap_Hashmap (*p)){
	auto uint8_t (*pb) = (p->buckets);
	for(auto size_t idx = 0;(idx<(1<<(p->bitshift)));(idx+=1)){
		((*((uint64_t (*))pb))=0);
		(pb+=(p->size_entry));
	};
	((p->len)=0);
}
void _6e5d_hashmap_copy(_6e5d_hashmap_Hashmap (*i),_6e5d_hashmap_Hashmap (*o)){
	((*o)=(*i));
	auto size_t len = ((i->size_entry)*(1<<(i->bitshift)));
	((o->buckets)=malloc(len));
	assert((o->buckets));
	memcpy((o->buckets),(i->buckets),len);
}
