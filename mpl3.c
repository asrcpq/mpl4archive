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
uint32_t _6e5d_mpl3_pneg(uint32_t p);
size_t _6e5d_mpl3_len(_6e5d_mpl3_Term (*s));
uint32_t _6e5d_mpl3_ppdeco(FILE (*f),uint32_t p);
void dispterm(FILE (*f),_6e5d_mpl3_Term (*sp));
void dispterms(FILE (*f),_6e5d_mpl3_Term (*s),size_t len);
void _6e5d_mpl3_dispsent(FILE (*f),_6e5d_mpl3_Term s[4]);
void _6e5d_mpl3_epterms(_6e5d_mpl3_Term (*s));
void _6e5d_mpl3_epfact(FILE (*f),uint32_t fact[3]);
int cmpterm(void (*v1),void (*v2));
int16_t i16sign(int16_t x);
int16_t i16abs(int16_t x);
bool _6e5d_mpl3_seq(_6e5d_mpl3_Term s1[4],_6e5d_mpl3_Term s2[4]);
int cmpsent(_6e5d_mpl3_Term s1[4],_6e5d_mpl3_Term s2[4]);
int cmpsent2(_6e5d_mpl3_Term s1[4],_6e5d_mpl3_Term s2[4],size_t len);
bool check_porder(_6e5d_mpl3_Term s[4],size_t len);
bool reassign(_6e5d_mpl3_Term (*s),size_t len);
void maxassign(int16_t (*max),int16_t other);
void minassign(_6e5d_mpl3_Term best[4],_6e5d_mpl3_Term (*c),size_t len);
void test4(_6e5d_mpl3_Term best[4],_6e5d_mpl3_Term s[4],size_t i1,size_t i2,size_t i3,size_t i4);
void test3(_6e5d_mpl3_Term best[4],_6e5d_mpl3_Term s[4],size_t i1,size_t i2,size_t i3);
size_t dedup(_6e5d_mpl3_Term (*s),size_t len);
bool topcheck(_6e5d_mpl3_Term (*s),size_t len);
bool isconnected_propagate(int16_t changedvs[3],int16_t next_changedvs[3],_6e5d_mpl3_Term (*term),size_t nextlen);
bool isconnected(_6e5d_mpl3_Term (*s),size_t len);
size_t exelim(_6e5d_mpl3_Term (*s),size_t len);
void permutation(_6e5d_mpl3_Term (*s),size_t len);
int8_t _6e5d_mpl3_normalize(_6e5d_mpl3_Term (*s),size_t len);
void copywoith(_6e5d_mpl3_Term (*p),size_t len,size_t ith,_6e5d_mpl3_Term (*(*sout)));
void vsub(_6e5d_mpl3_Term (*s),size_t len,int16_t f,int16_t t);
void shift(_6e5d_mpl3_Term (*s),size_t len,int16_t offset);
int16_t max_absv(_6e5d_mpl3_Term s[4]);
int8_t ressol(_6e5d_mpl3_Term (*s),size_t len,int16_t u1,int16_t u2,int16_t v1,int16_t v2);
int8_t respair(_6e5d_mpl3_Term a[4],_6e5d_mpl3_Term b[4],_6e5d_mpl3_Term (*c),size_t la,size_t lb,size_t i,size_t j);
size_t _6e5d_mpl3_res(_6e5d_mpl3_Term a[4],_6e5d_mpl3_Term bb[4],_6e5d_mpl3_Term answer[20][4]);
bool _6e5d_mpl3_dsplit1(_6e5d_mpl3_Term s[4],uint32_t pi,_6e5d_mpl3_Term answer[4]);
bool _6e5d_mpl3_hasconst(_6e5d_mpl3_Term s[4]);
uint32_t _6e5d_mpl3_pneg(uint32_t p){
	return (p^(1u<<31));
}
size_t _6e5d_mpl3_len(_6e5d_mpl3_Term (*s)){
	auto size_t idx;
	for((idx=0);(idx<4);(idx+=1)){
		if(((s->p)==0)){
			break;
		};
		(s+=1);
	};
	return idx;
}
uint32_t _6e5d_mpl3_ppdeco(FILE (*f),uint32_t p){
	if((!(!(p&(1u<<31))))){
		fprintf(f,"!");
	};
	if((p&(1u<<30))){
		fprintf(f,"'");
	};
	return (p&(~((1u<<31)|(1u<<30))));
}
void dispterm(FILE (*f),_6e5d_mpl3_Term (*sp)){
	fprintf(f,"[");
	auto uint32_t p = _6e5d_mpl3_ppdeco(f,(sp->p));
	fprintf(f,"%u %d %d]",p,(sp->u),(sp->v));
}
void dispterms(FILE (*f),_6e5d_mpl3_Term (*s),size_t len){
	fprintf(f,"[");
	for(auto size_t i = 0;(i<len);(i+=1)){
		dispterm(f,(s+i));
	};
	fprintf(f,"]");
}
void _6e5d_mpl3_dispsent(FILE (*f),_6e5d_mpl3_Term s[4]){
	auto size_t len = _6e5d_mpl3_len(s);
	dispterms(f,s,len);
}
void _6e5d_mpl3_epterms(_6e5d_mpl3_Term (*s)){
	dispterms(stderr,s,4);
	fprintf(stderr,"""\x0a""");
}
void _6e5d_mpl3_epfact(FILE (*f),uint32_t fact[3]){
	fprintf(f,"%u ",_6e5d_mpl3_ppdeco(f,fact[0]));
	fprintf(f,"%u ",_6e5d_mpl3_ppdeco(f,fact[1]));
	fprintf(f,"%u""\x0a""",_6e5d_mpl3_ppdeco(f,fact[2]));
}
int cmpterm(void (*v1),void (*v2)){
	auto _6e5d_mpl3_Term (*c1) = v1;
	auto _6e5d_mpl3_Term (*c2) = v2;
	if(((c1->p)<(c2->p))){
		return -1;
	}else if(((c1->p)>(c2->p))){
		return 1;
	};
	return memcmp(c1,c2,((size_t )(&((_6e5d_mpl3_Term (*))0)[1])));
}
int16_t i16sign(int16_t x){
	if((x>0)){
		return 1;
	}else if((x<0)){
		return -1;
	}else if(true){
		return 0;
	};
}
int16_t i16abs(int16_t x){
	if((x<0)){
		return (-x);
	}else if(true){
		return x;
	};
}
bool _6e5d_mpl3_seq(_6e5d_mpl3_Term s1[4],_6e5d_mpl3_Term s2[4]){
	return (0==cmpsent(s1,s2));
}
int cmpsent(_6e5d_mpl3_Term s1[4],_6e5d_mpl3_Term s2[4]){
	return memcmp(s1,s2,((size_t )(&((_6e5d_mpl3_Term (*)[4])0)[1])));
}
int cmpsent2(_6e5d_mpl3_Term s1[4],_6e5d_mpl3_Term s2[4],size_t len){
	return memcmp(s1,s2,(len*((size_t )(&((_6e5d_mpl3_Term (*))0)[1]))));
}
bool check_porder(_6e5d_mpl3_Term s[4],size_t len){
	auto _6e5d_mpl3_Term (*sp) = s;
	for(auto size_t idx = 1;(idx<len);(idx+=1)){
		(sp+=1);
		if(((sp->p)==0)){
			break;
		};
		if((((sp-1)->p)>(sp->p))){
			return false;
		};
	};
	return true;
}
bool reassign(_6e5d_mpl3_Term (*s),size_t len){
	auto int16_t vo[5];
	auto size_t volen = 0;
	auto _6e5d_mpl3_Term (*sp) = s;
	if((!check_porder(s,len))){
		return false;
	};
	for(auto size_t idx = 0;(idx<len);(idx+=1)){
		auto bool replaced[2] = {0,};
		for(auto size_t idy = 0;(idy<volen);(idy+=1)){
			if(((!replaced[0])&&(vo[idy]==(sp->u)))){
				((sp->u)=(((int16_t )(idy+1))*i16sign((sp->u))));
				(replaced[0]=true);
			};
			if(((!replaced[1])&&(vo[idy]==(sp->v)))){
				((sp->v)=(((int16_t )(idy+1))*i16sign((sp->v))));
				(replaced[1]=true);
			};
		};
		if((!replaced[0])){
			(vo[volen]=(sp->u));
			(volen+=1);
			auto int16_t v = (((int16_t )volen)*i16sign((sp->u)));
			if(((!replaced[1])&&((sp->u)==(sp->v)))){
				((sp->v)=v);
				(replaced[1]=true);
			};
			((sp->u)=v);
		};
		if((!replaced[1])){
			(vo[volen]=(sp->v));
			(volen+=1);
			((sp->v)=(((int16_t )volen)*i16sign((sp->v))));
		};
		(sp+=1);
	};
	assert((volen<=5));
	return true;
}
void maxassign(int16_t (*max),int16_t other){
	if((other>(*max))){
		((*max)=other);
	};
}
void minassign(_6e5d_mpl3_Term best[4],_6e5d_mpl3_Term (*c),size_t len){
	if((cmpsent2(c,best,len)<0)){
		memcpy(best,c,((size_t )(&((_6e5d_mpl3_Term (*)[4])0)[1])));
	};
}
void test4(_6e5d_mpl3_Term best[4],_6e5d_mpl3_Term s[4],size_t i1,size_t i2,size_t i3,size_t i4){
	auto _6e5d_mpl3_Term c[4] = {s[i1],s[i2],s[i3],s[i4],};
	if(reassign(c,4)){
		minassign(best,c,4);
	};
}
void test3(_6e5d_mpl3_Term best[4],_6e5d_mpl3_Term s[4],size_t i1,size_t i2,size_t i3){
	auto _6e5d_mpl3_Term c[4] = {s[i1],s[i2],s[i3],{0,},};
	if(reassign(c,3)){
		minassign(best,c,3);
	};
}
size_t dedup(_6e5d_mpl3_Term (*s),size_t len){
	if((len<=1)){
		return len;
	};
	auto _6e5d_mpl3_Term (*s1) = s;
	auto _6e5d_mpl3_Term (*s2) = (1+s);
	auto size_t j = 1;
	for(auto size_t i = 1;(i<len);((i+=1),(s2+=1))){
		assert(((s2->p)!=0));
		if((0==cmpterm(s1,s2))){
			continue;
		};
		(s1+=1);
		memcpy(s1,s2,((size_t )(&((_6e5d_mpl3_Term (*))0)[1])));
		(j+=1);
	};
	return j;
}
bool topcheck(_6e5d_mpl3_Term (*s),size_t len){
	if((len<2)){
		return false;
	};
	if((((1u<<31)==((s[0].p)^(s[1].p)))&&((s[0].u)==(s[1].u))&&((s[0].v)==(s[1].v)))){
		return true;
	};
	if((len==2)){
		return false;
	};
	if((((1u<<31)==((s[0].p)^(s[2].p)))&&((s[0].u)==(s[2].u))&&((s[0].v)==(s[2].v)))){
		return true;
	};
	if((((1u<<31)==((s[1].p)^(s[2].p)))&&((s[1].u)==(s[2].u))&&((s[1].v)==(s[2].v)))){
		return true;
	};
	if((len==3)){
		return false;
	};
	if((((1u<<31)==((s[0].p)^(s[3].p)))&&((s[0].u)==(s[3].u))&&((s[0].v)==(s[3].v)))){
		return true;
	};
	if((((1u<<31)==((s[1].p)^(s[3].p)))&&((s[1].u)==(s[3].u))&&((s[1].v)==(s[3].v)))){
		return true;
	};
	if((((1u<<31)==((s[2].p)^(s[3].p)))&&((s[2].u)==(s[3].u))&&((s[2].v)==(s[3].v)))){
		return true;
	};
	return false;
}
bool isconnected_propagate(int16_t changedvs[3],int16_t next_changedvs[3],_6e5d_mpl3_Term (*term),size_t nextlen){
	auto size_t j = 0;
	for(;(j<3);(j+=1)){
		if((changedvs[j]==(term->u))){
			(next_changedvs[nextlen]=(term->v));
		}else if((changedvs[j]==(term->v))){
			(next_changedvs[nextlen]=(term->u));
		}else if(true){
			continue;
		};
		return true;
	};
	return false;
}
bool isconnected(_6e5d_mpl3_Term (*s),size_t len){
	auto bool connected[4] = {true,false,false,false,};
	auto bool changed = true;
	auto int16_t changedvs[3] = {(s->u),(s->v),0,};
	while(changed){
		auto int16_t next_changedvs[3] = {0,};
		auto size_t nextlen = 0;
		(changed=false);
		for(auto size_t i = 1;(i<len);(i+=1)){
			if(connected[i]){
				continue;
			};
			if(isconnected_propagate(changedvs,next_changedvs,(&s[i]),nextlen)){
				(nextlen+=1);
				(connected[i]=true);
				(changed=true);
			};
		};
		memcpy(changedvs,next_changedvs,6);
	};
	for(auto size_t i = 1;(i<len);(i+=1)){
		if((!connected[i])){
			return false;
		};
	};
	return true;
}
size_t exelim(_6e5d_mpl3_Term (*s),size_t len){
	auto size_t len2 = 0;
	auto _6e5d_mpl3_Term (*sp) = s;
	auto _6e5d_mpl3_Term (*s2) = s;
	for(auto size_t idx = 0;(idx<len);((idx+=1),(sp+=1))){
		auto uint32_t p = (s[idx].p);
		if(((!(p&(1u<<31)))||(!((1u<<30)&p)))){
			memcpy(s2,sp,((size_t )(&((_6e5d_mpl3_Term (*))0)[1])));
			(s2+=1);
			(len2+=1);
			continue;
		};
		auto int16_t test = (s[idx].v);
		for(auto size_t idy = 0;(idy<len);(idy+=1)){
			if((idy==idx)){
				continue;
			}else if((((s[idy].u)==test)||((s[idy].v)==test))){
				memcpy(s2,sp,((size_t )(&((_6e5d_mpl3_Term (*))0)[1])));
				(s2+=1);
				(len2+=1);
				break;
			};
		};
	};
	return len2;
}
void permutation(_6e5d_mpl3_Term (*s),size_t len){
	auto _6e5d_mpl3_Term best[4];
	memcpy(best,s,(4*((size_t )(&((_6e5d_mpl3_Term (*))0)[1]))));
	assert(reassign(best,len));
	if((0==len)){
		;
	}else if((1==len)){
		;
	}else if((2==len)){
		auto _6e5d_mpl3_Term c[4] = {0,};
		(c[0]=s[1]);
		(c[1]=s[0]);
		if(reassign(c,2)){
			minassign(best,c,2);
		};
	}else if((len==3)){
		test3(best,s,0,2,1);
		test3(best,s,1,0,2);
		test3(best,s,1,2,0);
		test3(best,s,2,0,1);
		test3(best,s,2,1,0);
	}else if(((s[1].p)!=(s[2].p))){
		assert((len==4));
		test4(best,s,0,1,3,2);
		test4(best,s,1,0,2,3);
		test4(best,s,1,0,3,2);
	}else if(((s[0].p)!=(s[1].p))){
		assert((len==4));
		test4(best,s,0,1,3,2);
		test4(best,s,0,2,1,3);
		test4(best,s,0,2,3,1);
		test4(best,s,0,3,1,2);
		test4(best,s,0,3,2,1);
	}else if(((s[2].p)!=(s[3].p))){
		assert((len==4));
		test4(best,s,0,2,1,3);
		test4(best,s,1,0,2,3);
		test4(best,s,1,2,0,3);
		test4(best,s,2,0,1,3);
		test4(best,s,2,1,0,3);
	}else if(true){
		assert((len==4));
		test4(best,s,0,1,3,2);
		test4(best,s,0,2,1,3);
		test4(best,s,0,2,3,1);
		test4(best,s,0,3,1,2);
		test4(best,s,0,3,2,1);
		test4(best,s,1,0,2,3);
		test4(best,s,1,0,3,2);
		test4(best,s,1,2,0,3);
		test4(best,s,1,2,3,0);
		test4(best,s,1,3,0,2);
		test4(best,s,1,3,2,0);
		test4(best,s,2,0,1,3);
		test4(best,s,2,0,3,1);
		test4(best,s,2,1,0,3);
		test4(best,s,2,1,3,0);
		test4(best,s,2,3,0,1);
		test4(best,s,2,3,1,0);
		test4(best,s,3,0,1,2);
		test4(best,s,3,0,2,1);
		test4(best,s,3,1,0,2);
		test4(best,s,3,1,2,0);
		test4(best,s,3,2,0,1);
		test4(best,s,3,2,1,0);
	};
	memcpy(s,best,(4*((size_t )(&((_6e5d_mpl3_Term (*))0)[1]))));
}
int8_t _6e5d_mpl3_normalize(_6e5d_mpl3_Term (*s),size_t len){
	qsort(s,len,((size_t )(&((_6e5d_mpl3_Term (*))0)[1])),cmpterm);
	(len=dedup(s,len));
	(len=exelim(s,len));
	if((len>4)){
		return -1;
	}else if(topcheck(s,len)){
		return -2;
	}else if((!isconnected(s,len))){
		return -3;
	};
	permutation(s,len);
	memset((s+len),0,((4-len)*((size_t )(&((_6e5d_mpl3_Term (*))0)[1]))));
	return ((int8_t )len);
}
void copywoith(_6e5d_mpl3_Term (*p),size_t len,size_t ith,_6e5d_mpl3_Term (*(*sout))){
	for(auto size_t idx = 0;(idx<len);(idx+=1)){
		if(((p->p)==0)){
			break;
		}else if((ith!=idx)){
			((*(*sout))=(*p));
			((*sout)+=1);
		};
		(p+=1);
	};
}
void vsub(_6e5d_mpl3_Term (*s),size_t len,int16_t f,int16_t t){
	for(auto size_t idx = 0;(idx<len);(idx+=1)){
		if((f==(s->u))){
			((s->u)=t);
		};
		if((f==(s->v))){
			((s->v)=t);
		};
		(s+=1);
	};
}
void shift(_6e5d_mpl3_Term (*s),size_t len,int16_t offset){
	for(auto size_t idx = 0;(idx<len);(idx+=1)){
		if(((s->u)>0)){
			((s->u)+=offset);
		}else if(true){
			((s->u)-=offset);
		};
		if(((s->v)>0)){
			((s->v)+=offset);
		}else if(true){
			((s->v)-=offset);
		};
		(s+=1);
	};
}
int16_t max_absv(_6e5d_mpl3_Term s[4]){
	auto int16_t max = 0;
	for(auto size_t idx = 0;(idx<4);(idx+=1)){
		if(((s->p)==0)){
			break;
		};
		maxassign((&max),i16abs((s->u)));
		maxassign((&max),i16abs((s->v)));
		(s+=1);
	};
	return max;
}
int8_t ressol(_6e5d_mpl3_Term (*s),size_t len,int16_t u1,int16_t u2,int16_t v1,int16_t v2){
	if((u1==v1)){
		vsub(s,len,u2,u1);
		vsub(s,len,v2,v1);
	}else if(true){
		vsub(s,len,u1,u2);
		vsub(s,len,v1,v2);
	};
	return _6e5d_mpl3_normalize(s,len);
}
int8_t respair(_6e5d_mpl3_Term a[4],_6e5d_mpl3_Term b[4],_6e5d_mpl3_Term (*c),size_t la,size_t lb,size_t i,size_t j){
	auto _6e5d_mpl3_Term cat[5] = {0,};
	auto _6e5d_mpl3_Term (*p) = cat;
	copywoith(a,la,i,(&p));
	copywoith(b,lb,j,(&p));
	auto size_t lcat = ((la+lb)-2);
	auto int8_t lc = ressol(cat,lcat,(a[i].u),(b[j].u),(a[i].v),(b[j].v));
	if(((lc==4)&&(la==4))){
		return -9;
	};
	if((lc<0)){
		return lc;
	};
	memcpy(c,cat,((size_t )(&((_6e5d_mpl3_Term (*)[4])0)[1])));
	return lc;
}
size_t _6e5d_mpl3_res(_6e5d_mpl3_Term a[4],_6e5d_mpl3_Term bb[4],_6e5d_mpl3_Term answer[20][4]){
	auto _6e5d_mpl3_Term b[4];
	memcpy(b,bb,((size_t )(&((_6e5d_mpl3_Term (*)[4])0)[1])));
	auto size_t la = _6e5d_mpl3_len(a);
	auto size_t lb = _6e5d_mpl3_len(b);
	assert((4>=la));
	assert((3>=lb));
	auto int16_t maxva = max_absv(a);
	auto size_t anslen = 0;
	shift(b,lb,maxva);
	for(auto size_t i = 0;(i<la);(i+=1)){
		for(auto size_t j = 0;(j<lb);(j+=1)){
			if((((a[i].p)==_6e5d_mpl3_pneg((b[j].p)))&&(respair(a,b,answer[anslen],la,lb,i,j)>=0))){
				(anslen+=1);
			};
		};
	};
	return anslen;
}
bool _6e5d_mpl3_dsplit1(_6e5d_mpl3_Term s[4],uint32_t pi,_6e5d_mpl3_Term answer[4]){
	memcpy(answer,s,((size_t )(&((_6e5d_mpl3_Term (*)[4])0)[1])));
	assert(((pi&(1u<<30))&&(!(pi&(1u<<31)))));
	auto size_t len = _6e5d_mpl3_len(s);
	if(((len<=1)||(len>=4))){
		return false;
	};
	auto int16_t const_variable = 0;
	for(auto size_t idx = 0;(idx<len);(idx+=1)){
		auto _6e5d_mpl3_Term (*term) = (answer+idx);
		auto int16_t (*v) = (&(term->u));
		for(auto int16_t idy = 0;(idy<2);(idy+=1)){
			if((idy==1)){
				(v=(&(term->v)));
			};
			if((0<(*v))){
				continue;
			};
			if((const_variable==(*v))){
				((*v)=0x7fff);
				continue;
			};
			if((const_variable!=0)){
				return false;
			};
			(const_variable=(*v));
			((*v)=0x7fff);
		};
	};
	(answer[len]=((_6e5d_mpl3_Term ){.p=_6e5d_mpl3_pneg(pi),.u=0x7fff,.v=0x7fff,}));
	assert((((int8_t )(len+1))==_6e5d_mpl3_normalize(answer,(len+1))));
	return true;
}
bool _6e5d_mpl3_hasconst(_6e5d_mpl3_Term s[4]){
	auto _6e5d_mpl3_Term (*p) = s;
	for(auto size_t idx = 0;(idx<4);(idx+=1)){
		if((0==(p->p))){
			break;
		}else if(((1u<<30)&(p->p))){
			return true;
		};
		(p+=1);
	};
	return false;
}
