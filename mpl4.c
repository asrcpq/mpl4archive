#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include<assert.h>
typedef struct _6e5d_mpl3_Term _6e5d_mpl3_Term;
struct _6e5d_mpl3_Term{
	uint32_t p;
	int16_t u;
	int16_t v;
};
char (*_6e5d_mpl3pmap_getn(uint32_t pid));
uint32_t _6e5d_mpl3_pneg(uint32_t p);
bool _6e5d_mpl3_seq(_6e5d_mpl3_Term s1[4],_6e5d_mpl3_Term s2[4]);
int8_t _6e5d_mpl3_normalize(_6e5d_mpl3_Term (*s),size_t len);
size_t _6e5d_mpl3_len(_6e5d_mpl3_Term (*s));
void doreplace(_6e5d_mpl3_Term r3[4],uint32_t predfrom,uint32_t predto,bool swap);
size_t _6e5d_mpl4_progAlign(_6e5d_mpl3_Term (*rules)[4],_6e5d_mpl3_Term (*out)[4],size_t olen);
void doreplace(_6e5d_mpl3_Term r3[4],uint32_t predfrom,uint32_t predto,bool swap){
	for(auto size_t idz = 0;(idz<4);(idz+=1)){
		if((predfrom==(r3[idz].p))){
			((r3[idz].p)=predto);
		}else if((_6e5d_mpl3_pneg(predfrom)==(r3[idz].p))){
			((r3[idz].p)=_6e5d_mpl3_pneg(predto));
		}else if(true){
			continue;
		};
		if(swap){
			auto int16_t tmp = (r3[idz].u);
			((r3[idz].u)=(r3[idz].v));
			((r3[idz].v)=tmp);
		};
	};
}
size_t _6e5d_mpl4_progAlign(_6e5d_mpl3_Term (*rules)[4],_6e5d_mpl3_Term (*out)[4],size_t olen){
	for(auto size_t idx = 0;(idx<olen);(idx+=1)){
		auto _6e5d_mpl3_Term (*r1) = out[idx];
		auto _6e5d_mpl3_Term (*r2) = rules[idx];
		auto uint32_t predfrom = 0;
		auto uint32_t predto = 0;
		if(((r1[0].p)!=(r2[0].p))){
			if(_6e5d_mpl3pmap_getn((r1[0].p))){
				return idx;
			};
			(predfrom=(r1[0].p));
			(predto=(r2[0].p));
			((r1[0].p)=(r2[0].p));
			auto bool swap = false;
			_6e5d_mpl3_normalize(r1,_6e5d_mpl3_len(r1));
			if((!_6e5d_mpl3_seq(r1,r2))){
				auto int16_t tmp = (r1[0].u);
				((r1[0].u)=(r1[0].v));
				((r1[0].v)=tmp);
				_6e5d_mpl3_normalize(r1,_6e5d_mpl3_len(r1));
				(swap=true);
			};
			for(auto size_t idy = (idx+1);(idy<olen);(idy+=1)){
				auto _6e5d_mpl3_Term (*r3) = out[idy];
				doreplace(r3,predfrom,predto,swap);
				_6e5d_mpl3_normalize(r3,_6e5d_mpl3_len(r3));
			};
		};
		if((!_6e5d_mpl3_seq(r1,r2))){
			return idx;
		};
	};
	return olen;
}
