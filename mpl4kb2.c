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
typedef struct _6e5d_vec_Vec _6e5d_vec_Vec;
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
struct _6e5d_vec_Vec{
	size_t size;
	size_t capacity;
	size_t len;
	void (*p);
};
uint32_t _6e5d_mpl3_pneg(uint32_t p);
size_t _6e5d_mpl3_len(_6e5d_mpl3_Term (*s));
void _6e5d_mpl3pmap_display(FILE (*f),_6e5d_mpl3_Term s[4]);
void _6e5d_mpl3pmap_displayFact(FILE (*f),uint32_t fact[3]);
void _6e5d_hashmap_init(_6e5d_hashmap_Hashmap (*map),size_t size_key,size_t size_value);
void _6e5d_hashmap_deinit(_6e5d_hashmap_Hashmap (*map));
bool _6e5d_hashmap_next(_6e5d_hashmap_Hashmap (*p),_6e5d_hashmap_Iter (*it));
_6e5d_hashmap_Iter _6e5d_hashmap_iter(_6e5d_hashmap_Hashmap (*p));
void (*_6e5d_hashmap_get(_6e5d_hashmap_Hashmap (*map),void (*key)));
void (*_6e5d_hashmap_add(_6e5d_hashmap_Hashmap (*map),void (*key)));
bool _6e5d_hashmap_contains(_6e5d_hashmap_Hashmap (*map),void (*key));
void _6e5d_hashmap_insertv(_6e5d_hashmap_Hashmap (*map),void (*key),void (*value));
void _6e5d_hashmap_copy(_6e5d_hashmap_Hashmap (*i),_6e5d_hashmap_Hashmap (*o));
void _6e5d_vec_init(_6e5d_vec_Vec (*v),size_t size);
void _6e5d_vec_deinit(_6e5d_vec_Vec (*v));
void _6e5d_vec_pushv(_6e5d_vec_Vec (*v),void (*val));
void (*_6e5d_vec_last(_6e5d_vec_Vec (*v)));
void _6e5d_vec_copy(_6e5d_vec_Vec (*i),_6e5d_vec_Vec (*o));
typedef struct _6e5d_mpl4kb2_Kb _6e5d_mpl4kb2_Kb;
struct _6e5d_mpl4kb2_Kb{
	_6e5d_hashmap_Hashmap lookup;
	_6e5d_hashmap_Hashmap facts;
	_6e5d_vec_Vec rules;
};
void _6e5d_mpl4kb2_init(_6e5d_mpl4kb2_Kb (*kb));
void _6e5d_mpl4kb2_deinit(_6e5d_mpl4kb2_Kb (*kb));
void lookupInsert(_6e5d_hashmap_Hashmap (*map),uint32_t k,uint32_t val[3]);
void _6e5d_mpl4kb2_insertFact(_6e5d_mpl4kb2_Kb (*kb),uint32_t fact[3]);
bool closure3(_6e5d_mpl3_Term rule[4],uint32_t fact1[3],uint32_t fact2[3],uint32_t out[3]);
bool closure2(_6e5d_mpl3_Term rule[4],uint32_t fact[3],uint32_t out[3]);
void closure1(_6e5d_mpl4kb2_Kb (*kb),_6e5d_vec_Vec (*pending),_6e5d_mpl3_Term rule[4],uint32_t fact[3]);
bool _6e5d_mpl4kb2_hasFact(_6e5d_mpl4kb2_Kb (*kb),uint32_t fact[3]);
void _6e5d_mpl4kb2_filterPos(_6e5d_mpl4kb2_Kb (*kb),_6e5d_vec_Vec (*poses));
void closure(_6e5d_mpl4kb2_Kb (*kb),_6e5d_vec_Vec (*pending));
bool abduce2(_6e5d_mpl3_Term rule[4],uint32_t fact[3],uint32_t out[3]);
bool abduce3(_6e5d_mpl3_Term rule[4],uint32_t fact1[3],uint32_t fact2[3],size_t idx,uint32_t out[3]);
void abduce1(_6e5d_mpl4kb2_Kb (*kb),_6e5d_vec_Vec (*pending),_6e5d_vec_Vec (*pendsrc),_6e5d_mpl3_Term rule[4],uint32_t fact[3],uint32_t fsrc[3]);
void _6e5d_mpl4kb2_abduce(_6e5d_mpl4kb2_Kb (*kb),_6e5d_vec_Vec (*pos),_6e5d_vec_Vec (*abduced),_6e5d_vec_Vec (*sources));
void _6e5d_mpl4kb2_addRule(_6e5d_mpl4kb2_Kb (*kb),_6e5d_mpl3_Term (*rule));
void _6e5d_mpl4kb2_dump(FILE (*f),_6e5d_mpl4kb2_Kb (*kb));
void _6e5d_mpl4kb2_copy(_6e5d_mpl4kb2_Kb (*in),_6e5d_mpl4kb2_Kb (*out));
void _6e5d_mpl4kb2_init(_6e5d_mpl4kb2_Kb (*kb)){
	auto size_t spid = ((size_t )(&((uint32_t (*))0)[1]));
	_6e5d_vec_init((&(kb->rules)),((size_t )(&((_6e5d_mpl3_Term (*)[4])0)[1])));
	_6e5d_hashmap_init((&(kb->lookup)),spid,((size_t )(&((_6e5d_vec_Vec (*))0)[1])));
	_6e5d_hashmap_init((&(kb->facts)),((size_t )(&((uint32_t (*)[3])0)[1])),0);
}
void _6e5d_mpl4kb2_deinit(_6e5d_mpl4kb2_Kb (*kb)){
	_6e5d_vec_deinit((&(kb->rules)));
	for(auto _6e5d_hashmap_Iter iter = _6e5d_hashmap_iter((&(kb->lookup)));_6e5d_hashmap_next((&(kb->lookup)),(&iter));){
		_6e5d_vec_deinit((iter.value));
	};
	_6e5d_hashmap_deinit((&(kb->lookup)));
	_6e5d_hashmap_deinit((&(kb->facts)));
}
void lookupInsert(_6e5d_hashmap_Hashmap (*map),uint32_t k,uint32_t val[3]){
	auto void (*p) = _6e5d_hashmap_add(map,(&k));
	if((NULL!=p)){
		_6e5d_vec_init(p,((size_t )(&((uint32_t (*)[3])0)[1])));
	}else if(true){
		(p=_6e5d_hashmap_get(map,(&k)));
	};
	_6e5d_vec_pushv(p,val);
}
void _6e5d_mpl4kb2_insertFact(_6e5d_mpl4kb2_Kb (*kb),uint32_t fact[3]){
	if((!_6e5d_hashmap_add((&(kb->facts)),fact))){
		return ;
	};
	auto uint32_t pid1 = fact[1];
	lookupInsert((&(kb->lookup)),pid1,fact);
	auto uint32_t pid2 = fact[2];
	if(((0!=pid2)&&(pid2!=pid1))){
		lookupInsert((&(kb->lookup)),pid2,fact);
	};
}
bool closure3(_6e5d_mpl3_Term rule[4],uint32_t fact1[3],uint32_t fact2[3],uint32_t out[3]){
	auto int16_t v1 = (rule[0].u);
	auto uint32_t c1 = 0;
	if((v1==(rule[1].u))){
		auto uint32_t tmp = fact1[1];
		if((c1==0)){
			(c1=tmp);
		}else if((tmp!=c1)){
			return false;
		};
	};
	if((v1==(rule[1].v))){
		auto uint32_t tmp = fact1[2];
		if((c1==0)){
			(c1=tmp);
		}else if((tmp!=c1)){
			return false;
		};
	};
	if((v1==(rule[2].u))){
		auto uint32_t tmp = fact2[1];
		if((c1==0)){
			(c1=tmp);
		}else if((tmp!=c1)){
			return false;
		};
	};
	if((v1==(rule[2].v))){
		auto uint32_t tmp = fact2[2];
		if((c1==0)){
			(c1=tmp);
		}else if((tmp!=c1)){
			return false;
		};
	};
	assert(c1);
	auto int16_t v2 = (rule[0].v);
	auto uint32_t c2 = 0;
	if((v1==v2)){
		(c2=c1);
	}else if(true){
		if((v2==(rule[1].u))){
			auto uint32_t tmp = fact1[1];
			if((c2==0)){
				(c2=tmp);
			}else if((tmp!=c2)){
				return false;
			};
		};
		if((v2==(rule[1].v))){
			auto uint32_t tmp = fact1[2];
			if((c2==0)){
				(c2=tmp);
			}else if((tmp!=c2)){
				return false;
			};
		};
		if((v2==(rule[2].u))){
			auto uint32_t tmp = fact2[1];
			if((c2==0)){
				(c2=tmp);
			}else if((tmp!=c2)){
				return false;
			};
		};
		if((v2==(rule[2].v))){
			auto uint32_t tmp = fact2[2];
			if((c2==0)){
				(c2=tmp);
			}else if((tmp!=c2)){
				return false;
			};
		};
	};
	assert(c2);
	auto int16_t v3 = 0;
	auto uint32_t c3 = 0;
	auto uint32_t c4 = 0;
	{
		auto int16_t vtmp = (rule[1].u);
		if(((v1!=vtmp)&&(v2!=vtmp))){
			auto uint32_t ctmp = fact1[1];
			if((c3==0)){
				(v3=vtmp);
				(c3=ctmp);
			}else if((v3==vtmp)){
				if((c3!=ctmp)){
					return false;
				};
			}else if((c4==0)){
				(c4=ctmp);
			}else if((c4!=ctmp)){
				return false;
			};
		};
	};
	{
		auto int16_t vtmp = (rule[1].v);
		if(((v1!=vtmp)&&(v2!=vtmp))){
			auto uint32_t ctmp = fact1[2];
			if((c3==0)){
				(v3=vtmp);
				(c3=ctmp);
			}else if((v3==vtmp)){
				if((c3!=ctmp)){
					return false;
				};
			}else if((c4==0)){
				(c4=ctmp);
			}else if((c4!=ctmp)){
				return false;
			};
		};
	};
	{
		auto int16_t vtmp = (rule[2].u);
		if(((v1!=vtmp)&&(v2!=vtmp))){
			auto uint32_t ctmp = fact2[1];
			if((c3==0)){
				(v3=vtmp);
				(c3=ctmp);
			}else if((v3==vtmp)){
				if((c3!=ctmp)){
					return false;
				};
			}else if((c4==0)){
				(c4=ctmp);
			}else if((c4!=ctmp)){
				return false;
			};
		};
	};
	{
		auto int16_t vtmp = (rule[2].v);
		if(((v1!=vtmp)&&(v2!=vtmp))){
			auto uint32_t ctmp = fact2[2];
			if((c3==0)){
				(v3=vtmp);
				(c3=ctmp);
			}else if((v3==vtmp)){
				if((c3!=ctmp)){
					return false;
				};
			}else if((c4==0)){
				(c4=ctmp);
			}else if((c4!=ctmp)){
				return false;
			};
		};
	};
	(out[0]=(rule[0].p));
	(out[1]=c1);
	(out[2]=c2);
	return true;
}
bool closure2(_6e5d_mpl3_Term rule[4],uint32_t fact[3],uint32_t out[3]){
	auto int16_t v1 = (rule[0].u);
	auto uint32_t c1 = 0;
	if((v1==(rule[1].u))){
		auto uint32_t tmp = fact[1];
		if((c1==0)){
			(c1=tmp);
		}else if((tmp!=c1)){
			return false;
		};
	};
	if((v1==(rule[1].v))){
		auto uint32_t tmp = fact[2];
		if((c1==0)){
			(c1=tmp);
		}else if((tmp!=c1)){
			return false;
		};
	};
	assert(c1);
	auto int16_t v2 = (rule[0].v);
	auto uint32_t c2 = 0;
	if((v1==v2)){
		(c2=c1);
	}else if(true){
		if((v2==(rule[1].u))){
			auto uint32_t tmp = fact[1];
			if((c2==0)){
				(c2=tmp);
			}else if((tmp!=c2)){
				return false;
			};
		};
		if((v2==(rule[1].v))){
			auto uint32_t tmp = fact[2];
			if((c2==0)){
				(c2=tmp);
			}else if((tmp!=c2)){
				return false;
			};
		};
	};
	assert(c2);
	(out[0]=(rule[0].p));
	(out[1]=c1);
	(out[2]=c2);
	return true;
}
void closure1(_6e5d_mpl4kb2_Kb (*kb),_6e5d_vec_Vec (*pending),_6e5d_mpl3_Term rule[4],uint32_t fact[3]){
	if((0==(rule[2].p))){
		if((fact[0]!=_6e5d_mpl3_pneg((rule[1].p)))){
			return ;
		};
		auto uint32_t out[3];
		if(closure2(rule,fact,out)){
			_6e5d_vec_pushv(pending,out);
		};
		return ;
	};
	if((fact[0]==_6e5d_mpl3_pneg((rule[1].p)))){
		for(auto size_t idx = 1;(idx<3);(idx+=1)){
			auto _6e5d_vec_Vec (*v) = _6e5d_hashmap_get((&(kb->lookup)),(fact+idx));
			if((NULL==v)){
				continue;
			};
			for(auto uint32_t (*pfact2)[3] = (v->p);(((void (*))pfact2)<((void (*))(((uint8_t (*))(v->p))+((v->len)*(v->size)))));(pfact2+=1)){
				auto uint32_t (*fact2) = (*pfact2);
				if((fact2[0]!=_6e5d_mpl3_pneg((rule[2].p)))){
					continue;
				};
				auto uint32_t out[3];
				if(closure3(rule,fact,fact2,out)){
					_6e5d_vec_pushv(pending,out);
				};
			};
		};
	};
	if((fact[0]==_6e5d_mpl3_pneg((rule[2].p)))){
		for(auto size_t idx = 1;(idx<3);(idx+=1)){
			auto _6e5d_vec_Vec (*v) = _6e5d_hashmap_get((&(kb->lookup)),(fact+idx));
			if((NULL==v)){
				continue;
			};
			for(auto uint32_t (*pfact2)[3] = (v->p);(((void (*))pfact2)<((void (*))(((uint8_t (*))(v->p))+((v->len)*(v->size)))));(pfact2+=1)){
				auto uint32_t (*fact2) = (*pfact2);
				if((fact2[0]!=_6e5d_mpl3_pneg((rule[1].p)))){
					continue;
				};
				auto uint32_t out[3];
				if(closure3(rule,fact2,fact,out)){
					_6e5d_vec_pushv(pending,out);
				};
			};
		};
	};
}
bool _6e5d_mpl4kb2_hasFact(_6e5d_mpl4kb2_Kb (*kb),uint32_t fact[3]){
	return _6e5d_hashmap_contains((&(kb->facts)),fact);
}
void _6e5d_mpl4kb2_filterPos(_6e5d_mpl4kb2_Kb (*kb),_6e5d_vec_Vec (*poses)){
	auto size_t len0 = (poses->len);
	auto size_t idy = 0;
	for(auto size_t idx = 0;(idx<len0);(idx+=1)){
		if(_6e5d_mpl4kb2_hasFact(kb,((void (*))(((uint8_t (*))(poses->p))+(idx*(poses->size)))))){
			continue;
		};
		memcpy(((void (*))(((uint8_t (*))(poses->p))+(idy*(poses->size)))),((void (*))(((uint8_t (*))(poses->p))+(idx*(poses->size)))),((size_t )(&((uint32_t (*)[3])0)[1])));
		(idy+=1);
	};
	((poses->len)=idy);
}
void closure(_6e5d_mpl4kb2_Kb (*kb),_6e5d_vec_Vec (*pending)){
	while((0<(pending->len))){
		auto uint32_t (*pend)[3] = _6e5d_vec_last(pending);
		((pending->len)-=1);
		if(_6e5d_mpl4kb2_hasFact(kb,(*pend))){
			continue;
		};
		auto uint32_t fact[3];
		memcpy((&fact),pend,((size_t )(&((uint32_t (*)[3])0)[1])));
		for(auto _6e5d_mpl3_Term (*rule)[4] = ((&(kb->rules))->p);(((void (*))rule)<((void (*))(((uint8_t (*))((&(kb->rules))->p))+(((&(kb->rules))->len)*((&(kb->rules))->size)))));(rule+=1)){
			closure1(kb,pending,(*rule),fact);
		};
		_6e5d_mpl4kb2_insertFact(kb,fact);
	};
}
bool abduce2(_6e5d_mpl3_Term rule[4],uint32_t fact[3],uint32_t out[3]){
	auto int16_t v1 = (rule[1].u);
	auto uint32_t c1 = 0;
	if((v1==(rule[0].u))){
		auto uint32_t tmp = fact[1];
		if((c1==0)){
			(c1=tmp);
		}else if((tmp!=c1)){
			return false;
		};
	};
	if((v1==(rule[0].v))){
		auto uint32_t tmp = fact[2];
		if((c1==0)){
			(c1=tmp);
		}else if((tmp!=c1)){
			return false;
		};
	};
	if((c1==0)){
		return false;
	};
	auto int16_t v2 = (rule[1].v);
	auto uint32_t c2 = 0;
	if((v2==(rule[0].u))){
		auto uint32_t tmp = fact[1];
		if((c2==0)){
			(c2=tmp);
		}else if((tmp!=c2)){
			return false;
		};
	};
	if((v2==(rule[0].v))){
		auto uint32_t tmp = fact[2];
		if((c2==0)){
			(c2=tmp);
		}else if((tmp!=c2)){
			return false;
		};
	};
	if((c2==0)){
		return false;
	};
	(out[0]=_6e5d_mpl3_pneg((rule[1].p)));
	(out[1]=c1);
	(out[2]=c2);
	return true;
}
bool abduce3(_6e5d_mpl3_Term rule[4],uint32_t fact1[3],uint32_t fact2[3],size_t idx,uint32_t out[3]){
	auto size_t idy = (3-idx);
	auto int16_t v1 = (rule[idy].u);
	auto uint32_t c1 = 0;
	if((v1==(rule[0].u))){
		auto uint32_t tmp = fact1[1];
		if((c1==0)){
			(c1=tmp);
		}else if((tmp!=c1)){
			return false;
		};
	};
	if((v1==(rule[0].v))){
		auto uint32_t tmp = fact1[2];
		if((c1==0)){
			(c1=tmp);
		}else if((tmp!=c1)){
			return false;
		};
	};
	if((v1==(rule[idx].u))){
		auto uint32_t tmp = fact2[1];
		if((c1==0)){
			(c1=tmp);
		}else if((tmp!=c1)){
			return false;
		};
	};
	if((v1==(rule[idx].v))){
		auto uint32_t tmp = fact2[2];
		if((c1==0)){
			(c1=tmp);
		}else if((tmp!=c1)){
			return false;
		};
	};
	if((c1==0)){
		return false;
	};
	auto int16_t v2 = (rule[idy].v);
	auto uint32_t c2 = 0;
	if((v2==(rule[0].u))){
		auto uint32_t tmp = fact1[1];
		if((c2==0)){
			(c2=tmp);
		}else if((tmp!=c2)){
			return false;
		};
	};
	if((v2==(rule[0].v))){
		auto uint32_t tmp = fact1[2];
		if((c2==0)){
			(c2=tmp);
		}else if((tmp!=c2)){
			return false;
		};
	};
	if((v2==(rule[idx].u))){
		auto uint32_t tmp = fact2[1];
		if((c2==0)){
			(c2=tmp);
		}else if((tmp!=c2)){
			return false;
		};
	};
	if((v2==(rule[idx].v))){
		auto uint32_t tmp = fact2[2];
		if((c2==0)){
			(c2=tmp);
		}else if((tmp!=c2)){
			return false;
		};
	};
	if((c2==0)){
		return false;
	};
	auto int16_t v3 = 0;
	auto uint32_t c3 = 0;
	auto uint32_t c4 = 0;
	{
		auto int16_t vtmp = (rule[0].u);
		if(((v1!=vtmp)&&(v2!=vtmp))){
			auto uint32_t ctmp = fact1[1];
			if((c3==0)){
				(v3=vtmp);
				(c3=ctmp);
			}else if((v3==vtmp)){
				if((c3!=ctmp)){
					return false;
				};
			}else if((c4==0)){
				(c4=ctmp);
			}else if((c4!=ctmp)){
				return false;
			};
		};
	};
	{
		auto int16_t vtmp = (rule[0].v);
		if(((v1!=vtmp)&&(v2!=vtmp))){
			auto uint32_t ctmp = fact1[2];
			if((c3==0)){
				(v3=vtmp);
				(c3=ctmp);
			}else if((v3==vtmp)){
				if((c3!=ctmp)){
					return false;
				};
			}else if((c4==0)){
				(c4=ctmp);
			}else if((c4!=ctmp)){
				return false;
			};
		};
	};
	{
		auto int16_t vtmp = (rule[idx].u);
		if(((v1!=vtmp)&&(v2!=vtmp))){
			auto uint32_t ctmp = fact2[1];
			if((c3==0)){
				(v3=vtmp);
				(c3=ctmp);
			}else if((v3==vtmp)){
				if((c3!=ctmp)){
					return false;
				};
			}else if((c4==0)){
				(c4=ctmp);
			}else if((c4!=ctmp)){
				return false;
			};
		};
	};
	{
		auto int16_t vtmp = (rule[idx].v);
		if(((v1!=vtmp)&&(v2!=vtmp))){
			auto uint32_t ctmp = fact2[2];
			if((c3==0)){
				(v3=vtmp);
				(c3=ctmp);
			}else if((v3==vtmp)){
				if((c3!=ctmp)){
					return false;
				};
			}else if((c4==0)){
				(c4=ctmp);
			}else if((c4!=ctmp)){
				return false;
			};
		};
	};
	(out[0]=_6e5d_mpl3_pneg((rule[idy].p)));
	(out[1]=c1);
	(out[2]=c2);
	return true;
}
void abduce1(_6e5d_mpl4kb2_Kb (*kb),_6e5d_vec_Vec (*pending),_6e5d_vec_Vec (*pendsrc),_6e5d_mpl3_Term rule[4],uint32_t fact[3],uint32_t fsrc[3]){
	auto _6e5d_vec_Vec abdepths;
	auto _6e5d_vec_Vec abvs;
	auto _6e5d_hashmap_Hashmap visited;
	_6e5d_vec_init((&abdepths),((size_t )(&((uint32_t (*))0)[1])));
	_6e5d_vec_init((&abvs),((size_t )(&((uint32_t (*))0)[1])));
	_6e5d_hashmap_init((&visited),((size_t )(&((uint32_t (*)[3])0)[1])),0);
	auto uint32_t zero = 0;
	_6e5d_vec_pushv((&abdepths),(&zero));
	_6e5d_vec_pushv((&abvs),(fact+1));
	if((fact[1]!=fact[2])){
		_6e5d_vec_pushv((&abvs),(fact+2));
		_6e5d_vec_pushv((&abdepths),(&zero));
	};
	while((0<(abvs.len))){
		auto uint32_t depth = (*((uint32_t (*))_6e5d_vec_last((&abdepths))));
		auto uint32_t v = (*((uint32_t (*))_6e5d_vec_last((&abvs))));
		((abvs.len)-=1);
		((abdepths.len)-=1);
		(depth+=1);
		if((depth>=5)){
			continue;
		};
		auto _6e5d_vec_Vec (*neigh) = _6e5d_hashmap_get((&(kb->lookup)),(&v));
		if((NULL==neigh)){
			continue;
		};
		for(auto uint32_t (*pfact2)[3] = (neigh->p);(((void (*))pfact2)<((void (*))(((uint8_t (*))(neigh->p))+((neigh->len)*(neigh->size)))));(pfact2+=1)){
			auto uint32_t (*fact2) = (*pfact2);
			if(_6e5d_hashmap_contains((&visited),fact2)){
				continue;
			};
			_6e5d_hashmap_insertv((&visited),fact,NULL);
			if((fact2[1]!=v)){
				_6e5d_vec_pushv((&abdepths),(&depth));
				_6e5d_vec_pushv((&abvs),(fact2+1));
			};
			if((fact2[2]!=v)){
				_6e5d_vec_pushv((&abdepths),(&depth));
				_6e5d_vec_pushv((&abvs),(fact2+2));
			};
			auto uint32_t out[3];
			if((fact2[0]==_6e5d_mpl3_pneg((rule[1].p)))){
				if(abduce3(rule,fact,fact2,1,out)){
					if(_6e5d_hashmap_contains((&(kb->facts)),out)){
						continue;
					};
					_6e5d_vec_pushv(pending,out);
					_6e5d_vec_pushv(pendsrc,fsrc);
				};
			};
			if((fact2[0]==_6e5d_mpl3_pneg((rule[2].p)))){
				if(abduce3(rule,fact,fact2,2,out)){
					if(_6e5d_hashmap_contains((&(kb->facts)),out)){
						continue;
					};
					_6e5d_vec_pushv(pending,out);
					_6e5d_vec_pushv(pendsrc,fsrc);
				};
			};
		};
	};
	_6e5d_hashmap_deinit((&visited));
	_6e5d_vec_deinit((&abdepths));
	_6e5d_vec_deinit((&abvs));
}
void _6e5d_mpl4kb2_abduce(_6e5d_mpl4kb2_Kb (*kb),_6e5d_vec_Vec (*pos),_6e5d_vec_Vec (*abduced),_6e5d_vec_Vec (*sources)){
	auto _6e5d_hashmap_Hashmap dup;
	auto _6e5d_vec_Vec pending_;
	auto _6e5d_vec_Vec pendsrc_;
	auto _6e5d_vec_Vec (*pending) = (&pending_);
	auto _6e5d_vec_Vec (*pendsrc) = (&pendsrc_);
	_6e5d_vec_init(pending,((size_t )(&((uint32_t (*)[3])0)[1])));
	_6e5d_vec_init(pendsrc,((size_t )(&((uint32_t (*)[3])0)[1])));
	_6e5d_hashmap_init((&dup),((size_t )(&((uint32_t (*)[3])0)[1])),0);
	for(auto uint32_t (*iter)[3] = (pos->p);(((void (*))iter)<((void (*))(((uint8_t (*))(pos->p))+((pos->len)*(pos->size)))));(iter+=1)){
		_6e5d_vec_pushv(pending,iter);
	};
	for(auto uint32_t (*iter)[3] = (pos->p);(((void (*))iter)<((void (*))(((uint8_t (*))(pos->p))+((pos->len)*(pos->size)))));(iter+=1)){
		_6e5d_vec_pushv(pendsrc,iter);
	};
	while((0<(pending->len))){
		auto uint32_t fact[3];
		auto uint32_t fsrc[3];
		memcpy(fact,_6e5d_vec_last(pending),((size_t )(&((uint32_t (*)[3])0)[1])));
		memcpy(fsrc,_6e5d_vec_last(pendsrc),((size_t )(&((uint32_t (*)[3])0)[1])));
		assert((0<fact[0]));
		((pending->len)-=1);
		((pendsrc->len)-=1);
		if(_6e5d_hashmap_contains((&dup),fact)){
			continue;
		};
		_6e5d_hashmap_insertv((&dup),fact,NULL);
		_6e5d_vec_pushv(abduced,fact);
		_6e5d_vec_pushv(sources,fsrc);
		for(auto _6e5d_mpl3_Term (*prule)[4] = ((&(kb->rules))->p);(((void (*))prule)<((void (*))(((uint8_t (*))((&(kb->rules))->p))+(((&(kb->rules))->len)*((&(kb->rules))->size)))));(prule+=1)){
			auto _6e5d_mpl3_Term (*rule) = (*prule);
			if((fact[0]!=(rule[0].p))){
				continue;
			};
			auto uint32_t out[3];
			if((0==(rule[2].p))){
				if(abduce2(rule,fact,out)){
					if(_6e5d_hashmap_contains((&(kb->facts)),out)){
						continue;
					};
					_6e5d_vec_pushv(pending,out);
					_6e5d_vec_pushv(pendsrc,fsrc);
				};
			}else if(true){
				abduce1(kb,pending,pendsrc,rule,fact,fsrc);
			};
		};
	};
	_6e5d_vec_deinit(pending);
	_6e5d_vec_deinit(pendsrc);
	_6e5d_hashmap_deinit((&dup));
}
void _6e5d_mpl4kb2_addRule(_6e5d_mpl4kb2_Kb (*kb),_6e5d_mpl3_Term (*rule)){
	auto size_t rlen = _6e5d_mpl3_len(rule);
	assert((rlen<=3));
	assert((rlen>=2));
	auto _6e5d_vec_Vec pending;
	_6e5d_vec_init((&pending),((size_t )(&((uint32_t (*)[3])0)[1])));
	for(auto _6e5d_hashmap_Iter iter = _6e5d_hashmap_iter((&(kb->facts)));_6e5d_hashmap_next((&(kb->facts)),(&iter));){
		auto uint32_t (*fact) = (iter.key);
		assert((0<fact[0]));
		closure1(kb,(&pending),rule,fact);
	};
	_6e5d_vec_pushv((&(kb->rules)),rule);
	closure(kb,(&pending));
	_6e5d_vec_deinit((&pending));
}
void _6e5d_mpl4kb2_dump(FILE (*f),_6e5d_mpl4kb2_Kb (*kb)){
	for(auto _6e5d_mpl3_Term (*iter)[4] = ((&(kb->rules))->p);(((void (*))iter)<((void (*))(((uint8_t (*))((&(kb->rules))->p))+(((&(kb->rules))->len)*((&(kb->rules))->size)))));(iter+=1)){
		_6e5d_mpl3pmap_display(f,(*iter));
		fprintf(f,"""\x0a""");
	};
	for(auto _6e5d_hashmap_Iter iter = _6e5d_hashmap_iter((&(kb->facts)));_6e5d_hashmap_next((&(kb->facts)),(&iter));){
		auto uint32_t (*fact) = (iter.key);
		_6e5d_mpl3pmap_displayFact(f,fact);
		fprintf(f,"""\x0a""");
	};
}
void _6e5d_mpl4kb2_copy(_6e5d_mpl4kb2_Kb (*in),_6e5d_mpl4kb2_Kb (*out)){
	_6e5d_hashmap_copy((&(in->facts)),(&(out->facts)));
	_6e5d_vec_copy((&(in->rules)),(&(out->rules)));
	_6e5d_hashmap_init((&(out->lookup)),((size_t )(&((uint32_t (*))0)[1])),((size_t )(&((_6e5d_vec_Vec (*))0)[1])));
	for(auto _6e5d_hashmap_Iter iter = _6e5d_hashmap_iter((&(in->lookup)));_6e5d_hashmap_next((&(in->lookup)),(&iter));){
		auto _6e5d_vec_Vec (*v) = _6e5d_hashmap_add((&(out->lookup)),(iter.key));
		_6e5d_vec_copy((iter.value),v);
	};
}
