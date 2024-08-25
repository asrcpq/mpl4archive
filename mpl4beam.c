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
typedef struct _6e5d_mpl4steptest_Node _6e5d_mpl4steptest_Node;
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
struct _6e5d_mpl4steptest_Node{
	_6e5d_mpl4kb2_Kb kb;
	_6e5d_vec_Vec abduced;
	_6e5d_vec_Vec sources;
	uint32_t pi;
};
void _6e5d_vec_copy(_6e5d_vec_Vec (*i),_6e5d_vec_Vec (*o));
void _6e5d_vec_init(_6e5d_vec_Vec (*v),size_t size);
void _6e5d_vec_deinit(_6e5d_vec_Vec (*v));
void _6e5d_mpl3pmap_display(FILE (*f),_6e5d_mpl3_Term s[4]);
uint32_t _6e5d_mpl3pmap_invent();
bool _6e5d_mpl4steptest_buildkb(_6e5d_mpl3_Term out[6][4],size_t olen,_6e5d_mpl4kb2_Kb (*kb2),_6e5d_vec_Vec (*negs));
void _6e5d_mpl4steptest_nodeDeinit(_6e5d_mpl4steptest_Node (*node));
size_t _6e5d_mpl4steptest_step2(_6e5d_mpl4steptest_Node (*node),_6e5d_mpl3_Term out[6][4],uint32_t (*opi),size_t (*select));
bool _6e5d_hashmap_contains(_6e5d_hashmap_Hashmap (*map),void (*key));
void _6e5d_mpl4kb2_abduce(_6e5d_mpl4kb2_Kb (*kb),_6e5d_vec_Vec (*pos),_6e5d_vec_Vec (*abduced),_6e5d_vec_Vec (*sources));
void _6e5d_mpl4kb2_filterPos(_6e5d_mpl4kb2_Kb (*kb),_6e5d_vec_Vec (*poses));
void _6e5d_mpl4kb2_copy(_6e5d_mpl4kb2_Kb (*in),_6e5d_mpl4kb2_Kb (*out));
void _6e5d_mpl4kb2_init(_6e5d_mpl4kb2_Kb (*kb));
void _6e5d_mpl4kb2_insertFact(_6e5d_mpl4kb2_Kb (*kb),uint32_t fact[3]);
typedef struct Beamnode Beamnode;
struct Beamnode{
	_6e5d_mpl4steptest_Node node;
	size_t len_p;
	size_t pidx;
};
void infoNode(Beamnode (*bn));
bool buildbn(Beamnode (*parent),Beamnode (*bn2),_6e5d_mpl3_Term out[4][4],size_t olen,uint32_t opi,size_t select,size_t pidx,_6e5d_vec_Vec (*ep),_6e5d_vec_Vec (*en));
size_t prop(size_t w,size_t d,size_t l,_6e5d_vec_Vec (*ep),_6e5d_vec_Vec (*en));
void dumpNode(Beamnode (*bnode));
bool _6e5d_mpl4beam_beam(size_t w,_6e5d_vec_Vec (*bk),_6e5d_vec_Vec (*ep),_6e5d_vec_Vec (*en));
static Beamnode nodes[1048576];
static Beamnode newnodes[1048576];
static size_t newlen;
void infoNode(Beamnode (*bn)){
	auto _6e5d_mpl4steptest_Node (*n) = (&(bn->node));
	auto _6e5d_mpl4kb2_Kb (*kb) = (&(n->kb));
	auto size_t f = ((kb->facts).len);
	auto size_t r = ((kb->rules).len);
	auto size_t p = (bn->len_p);
	auto size_t a = ((n->abduced).len);
	fprintf(stderr,"f:%zu r:%zu p:%zu a:%zu pidx:%zu""\x0a""",f,r,p,a,(bn->pidx));
}
bool buildbn(Beamnode (*parent),Beamnode (*bn2),_6e5d_mpl3_Term out[4][4],size_t olen,uint32_t opi,size_t select,size_t pidx,_6e5d_vec_Vec (*ep),_6e5d_vec_Vec (*en)){
	auto _6e5d_mpl4steptest_Node (*node) = (&(parent->node));
	auto uint32_t (*pos) = ((void (*))(((uint8_t (*))((&(node->abduced))->p))+(select*((&(node->abduced))->size))));
	auto uint32_t (*src) = ((void (*))(((uint8_t (*))((&(node->sources))->p))+(select*((&(node->sources))->size))));
	auto _6e5d_mpl4steptest_Node (*n2) = (&(bn2->node));
	_6e5d_mpl4kb2_copy((&(node->kb)),(&(n2->kb)));
	_6e5d_vec_init((&(n2->abduced)),((size_t )(&((uint32_t (*)[3])0)[1])));
	_6e5d_vec_init((&(n2->sources)),((size_t )(&((uint32_t (*)[3])0)[1])));
	auto _6e5d_mpl4kb2_Kb (*kb) = (&(n2->kb));
	if((!_6e5d_mpl4steptest_buildkb(out,olen,kb,en))){
		return false;
	};
	assert(_6e5d_hashmap_contains((&(kb->facts)),pos));
	assert(_6e5d_hashmap_contains((&(kb->facts)),src));
	auto size_t len_f = ((kb->facts).len);
	if((len_f>500)){
		return false;
	};
	((n2->pi)=opi);
	((bn2->pidx)=pidx);
	auto _6e5d_vec_Vec tmppos;
	_6e5d_vec_copy(ep,(&tmppos));
	_6e5d_mpl4kb2_filterPos(kb,(&tmppos));
	if(((tmppos.len)>=(parent->len_p))){
		abort();
	};
	((bn2->len_p)=(tmppos.len));
	_6e5d_mpl4kb2_abduce(kb,(&tmppos),(&(n2->abduced)),(&(n2->sources)));
	_6e5d_vec_deinit((&tmppos));
	auto size_t len_a = ((n2->abduced).len);
	if((len_a>1000)){
		return false;
	};
	return true;
}
size_t prop(size_t w,size_t d,size_t l,_6e5d_vec_Vec (*ep),_6e5d_vec_Vec (*en)){
	assert((l>0));
	(newlen=0);
	auto size_t try = 0;
	auto size_t pidx = 0;
	while((newlen<w)){
		(try+=1);
		if((0==(try%10000))){
			fprintf(stderr,"try:%zu/%zu""\x0a""",try,(w*100));
		};
		if((try>(w*100))){
			break;
		};
		(pidx+=1);
		(pidx%=l);
		auto Beamnode (*bnode) = (nodes+pidx);
		auto _6e5d_mpl4steptest_Node (*node) = (&(bnode->node));
		auto _6e5d_mpl3_Term out[4][4];
		auto uint32_t opi;
		auto size_t select;
		auto size_t olen = _6e5d_mpl4steptest_step2(node,out,(&opi),(&select));
		if((olen==0)){
			continue;
		};
		if(((olen+(((node->kb).rules).len))>(5+d))){
			continue;
		};
		auto Beamnode (*bn2) = (newnodes+newlen);
		if((!buildbn(bnode,bn2,out,olen,opi,select,pidx,ep,en))){
			_6e5d_mpl4steptest_nodeDeinit((&(bn2->node)));
			continue;
		};
		(newlen+=1);
		if((0==(bn2->len_p))){
			fprintf(stderr,"""\x1b""[3%hhum",5);
			fprintf(stderr,"SOLUTION""\x0a""");
			fprintf(stderr,"""\x1b""[0m");
			infoNode(bn2);
			dumpNode(bn2);
			return true;
		};
		fprintf(stderr,"%zu/%zu/%zu ",d,newlen,w);
		infoNode(bn2);
	};
	return false;
}
void dumpNode(Beamnode (*bnode)){
	auto _6e5d_mpl4steptest_Node (*node) = (&(bnode->node));
	auto _6e5d_vec_Vec (*rules) = (&((node->kb).rules));
	for(auto size_t idx = 0;(idx<(rules->len));(idx+=1)){
		auto _6e5d_mpl3_Term (*rule) = ((void (*))(((uint8_t (*))(rules->p))+(idx*(rules->size))));
		_6e5d_mpl3pmap_display(stderr,rule);
		fprintf(stderr,"""\x0a""");
	};
}
bool _6e5d_mpl4beam_beam(size_t w,_6e5d_vec_Vec (*bk),_6e5d_vec_Vec (*ep),_6e5d_vec_Vec (*en)){
	auto int32_t result = 0;
	auto size_t depth = 0;
	(newlen=1);
	auto Beamnode (*bfirst) = newnodes;
	auto _6e5d_mpl4steptest_Node (*first) = (&(bfirst->node));
	((first->pi)=_6e5d_mpl3pmap_invent());
	_6e5d_mpl4kb2_init((&(first->kb)));
	for(auto uint32_t (*iter)[3] = (bk->p);(((void (*))iter)<((void (*))(((uint8_t (*))(bk->p))+((bk->len)*(bk->size)))));(iter+=1)){
		_6e5d_mpl4kb2_insertFact((&(first->kb)),(*iter));
	};
	_6e5d_vec_copy(ep,(&(first->abduced)));
	_6e5d_vec_copy(ep,(&(first->sources)));
	((bfirst->len_p)=(ep->len));
	while((depth<8)){
		memcpy(nodes,newnodes,(newlen*((size_t )(&((Beamnode (*))0)[1]))));
		auto size_t len = newlen;
		auto bool success = prop(w,depth,newlen,ep,en);
		for(auto size_t idx = 0;(idx<len);(idx+=1)){
			_6e5d_mpl4steptest_nodeDeinit((&(nodes[idx].node)));
		};
		if(success){
			(result=1);
			break;
		};
		if((newlen==0)){
			(result=-1);
			break;
		};
		(depth+=1);
	};
	for(auto size_t idx = 0;(idx<newlen);(idx+=1)){
		_6e5d_mpl4steptest_nodeDeinit((&(newnodes[idx].node)));
	};
	return (result==1);
}
