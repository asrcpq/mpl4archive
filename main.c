#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include<assert.h>
typedef struct _6e5d_vec_Vec _6e5d_vec_Vec;
struct _6e5d_vec_Vec{
	size_t size;
	size_t capacity;
	size_t len;
	void (*p);
};
void _6e5d_mpl3pmap_init();
void _6e5d_mpl3pmap_deinit();
void _6e5d_mpl4parse_loadFacts(char (*path),_6e5d_vec_Vec (*out));
bool _6e5d_mpl4beam_beam(size_t w,_6e5d_vec_Vec (*bk),_6e5d_vec_Vec (*ep),_6e5d_vec_Vec (*en));
void _6e5d_rand_seed(uint64_t s);
uint64_t _6e5d_c0date_now();
void _6e5d_vec_init(_6e5d_vec_Vec (*v),size_t size);
void _6e5d_vec_deinit(_6e5d_vec_Vec (*v));
int main(int argc,char (*(*argv)));
int main(int argc,char (*(*argv))){
	auto char (*es) = getenv("SEED");
	if(es){
		_6e5d_rand_seed(((uint64_t )atol(es)));
	};
	_6e5d_mpl3pmap_init();
	assert((argc==4));
	auto _6e5d_vec_Vec bk_;
	auto _6e5d_vec_Vec (*bk) = (&bk_);
	_6e5d_vec_init(bk,((size_t )(&((uint32_t (*)[3])0)[1])));
	_6e5d_mpl4parse_loadFacts(argv[1],bk);
	auto _6e5d_vec_Vec ep_;
	auto _6e5d_vec_Vec (*ep) = (&ep_);
	_6e5d_vec_init(ep,((size_t )(&((uint32_t (*)[3])0)[1])));
	_6e5d_mpl4parse_loadFacts(argv[2],ep);
	auto _6e5d_vec_Vec en_;
	auto _6e5d_vec_Vec (*en) = (&en_);
	_6e5d_vec_init(en,((size_t )(&((uint32_t (*)[3])0)[1])));
	_6e5d_mpl4parse_loadFacts(argv[3],en);
	auto uint64_t t = _6e5d_c0date_now();
	auto size_t w = 1;
	while((!_6e5d_mpl4beam_beam(w,bk,ep,en))){
		(w*=2);
		if((1048576<w)){
			abort();
		};
	};
	printf("%lu""\x0a""",(_6e5d_c0date_now()-t));
	_6e5d_vec_deinit(bk);
	_6e5d_vec_deinit(ep);
	_6e5d_vec_deinit(en);
	_6e5d_mpl3pmap_deinit();
}
