#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include<assert.h>
typedef struct _6e5d_mpl3_Term _6e5d_mpl3_Term;
typedef struct _6e5d_vec_Vec _6e5d_vec_Vec;
struct _6e5d_mpl3_Term{
	uint32_t p;
	int16_t u;
	int16_t v;
};
struct _6e5d_vec_Vec{
	size_t size;
	size_t capacity;
	size_t len;
	void (*p);
};
int8_t _6e5d_mpl3_normalize(_6e5d_mpl3_Term (*s),size_t len);
uint32_t _6e5d_mpl3_pneg(uint32_t p);
void _6e5d_mpl3pmap_displayFact(FILE (*f),uint32_t fact[3]);
void _6e5d_mpl3pmap_display(FILE (*f),_6e5d_mpl3_Term s[4]);
uint32_t _6e5d_mpl3pmap_getpi(char (*name));
void _6e5d_vec_pushv(_6e5d_vec_Vec (*v),void (*val));
void _6e5d_mpl4parse_dumpFacts(FILE (*f),_6e5d_vec_Vec (*facts));
void _6e5d_mpl4parse_dumpRules(FILE (*f),_6e5d_vec_Vec (*rules));
void _6e5d_mpl4parse_loadRules(char (*path),_6e5d_vec_Vec (*out));
void _6e5d_mpl4parse_parseFact(char (*line),uint32_t fact[3]);
void _6e5d_mpl4parse_loadFacts(char (*path),_6e5d_vec_Vec (*out));
void setv(_6e5d_mpl3_Term (*term),int16_t value,bool firstv);
void _6e5d_mpl4parse_parse(char (*s),_6e5d_mpl3_Term out[4]);
void _6e5d_mpl4parse_dumpFacts(FILE (*f),_6e5d_vec_Vec (*facts)){
	fprintf(f,"===mpl4parse/dumpFacts===""\x0a""");
	for(auto size_t idx = 0;(idx<(facts->len));(idx+=1)){
		_6e5d_mpl3pmap_displayFact(f,((void (*))(((uint8_t (*))(facts->p))+(idx*(facts->size)))));
		fprintf(f,"""\x0a""");
	};
	fprintf(f,"===end===""\x0a""");
}
void _6e5d_mpl4parse_dumpRules(FILE (*f),_6e5d_vec_Vec (*rules)){
	fprintf(f,"===mpl4parse/dumpRules===""\x0a""");
	for(auto size_t idx = 0;(idx<(rules->len));(idx+=1)){
		_6e5d_mpl3pmap_display(f,((void (*))(((uint8_t (*))(rules->p))+(idx*(rules->size)))));
		fprintf(f,"""\x0a""");
	};
	fprintf(f,"===end===""\x0a""");
}
void _6e5d_mpl4parse_loadRules(char (*path),_6e5d_vec_Vec (*out)){
	auto FILE (*f) = fopen(path,"r");
	if((NULL==f)){
		fprintf(stderr,"bad file: %s""\x0a""",path);
		abort();
	};
	auto char (*line) = NULL;
	auto size_t len;
	while(true){
		auto ssize_t l = getline((&line),(&len),f);
		if((('\x23'==(*line))||('\x0a'==(*line)))){
			continue;
		};
		if((l==-1)){
			break;
		};
		auto _6e5d_mpl3_Term sent[4];
		_6e5d_mpl4parse_parse(line,sent);
		_6e5d_vec_pushv(out,sent);
	};
	free(line);
	fclose(f);
}
void _6e5d_mpl4parse_parseFact(char (*line),uint32_t fact[3]){
	auto char (*save);
	auto char (*w);
	(w=strtok_r(line," ""\x0a""",(&save)));
	assert(w);
	(fact[0]=_6e5d_mpl3pmap_getpi(w));
	(w=strtok_r(NULL," ""\x0a""",(&save)));
	assert(w);
	(fact[1]=_6e5d_mpl3pmap_getpi(w));
	(w=strtok_r(NULL," ""\x0a""",(&save)));
	if((NULL!=w)){
		(fact[2]=_6e5d_mpl3pmap_getpi(w));
	}else if(true){
		(fact[2]=fact[1]);
	};
}
void _6e5d_mpl4parse_loadFacts(char (*path),_6e5d_vec_Vec (*out)){
	auto FILE (*f) = fopen(path,"r");
	if((NULL==f)){
		fprintf(stderr,"bad file: %s""\x0a""",path);
		abort();
	};
	auto char (*line) = NULL;
	auto size_t len;
	while(true){
		auto ssize_t l = getline((&line),(&len),f);
		if((('\x23'==(*line))||('\x0a'==(*line)))){
			continue;
		};
		if((l==-1)){
			break;
		};
		auto uint32_t fact[3] = {0,};
		_6e5d_mpl4parse_parseFact(line,fact);
		_6e5d_vec_pushv(out,fact);
	};
	free(line);
	fclose(f);
}
void setv(_6e5d_mpl3_Term (*term),int16_t value,bool firstv){
	if(firstv){
		((term->u)=value);
		((term->v)=value);
	}else if(true){
		((term->v)=value);
	};
}
void _6e5d_mpl4parse_parse(char (*s),_6e5d_mpl3_Term out[4]){
	auto char (*saveptr) = NULL;
	memset(out,0,((size_t )(&((_6e5d_mpl3_Term (*)[4])0)[1])));
	auto size_t idx = 0;
	auto size_t arrowpos = 0;
	auto bool arrowleft = 0;
	auto bool firstv = true;
	auto char sep[] = " (),.""\x0a""";
	for(auto char (*p) = strtok_r(s,sep,(&saveptr));(p!=NULL);(p=strtok_r(NULL,sep,(&saveptr)))){
		auto char ch = (*p);
		if(((ch>='\x31')&&(ch<='\x39'))){
			assert((idx>0));
			setv((out+(idx-1)),(ch-'\x30'),firstv);
			(firstv=(!firstv));
		}else if((ch=='\x2d')){
			assert((idx>0));
			setv((out+(idx-1)),-1,firstv);
			(firstv=(!firstv));
		}else if((ch=='\x3c')){
			(arrowpos=idx);
			(arrowleft=true);
		}else if((ch=='\x3e')){
			(arrowpos=idx);
			(arrowleft=false);
		}else if(true){
			auto bool neg = false;
			if((ch=='\x21')){
				(neg=true);
				(p+=1);
			};
			(firstv=true);
			auto uint32_t pid = _6e5d_mpl3pmap_getpi(p);
			if(neg){
				(pid=_6e5d_mpl3_pneg(pid));
			};
			((out[idx].p)=pid);
			(idx+=1);
		};
	};
	auto size_t start = 0;
	auto size_t end = 4;
	if(arrowleft){
		(start=arrowpos);
	}else if(true){
		(end=arrowpos);
	};
	for(auto size_t idy = start;(idy<end);(idy+=1)){
		auto _6e5d_mpl3_Term (*term) = (out+idy);
		((term->p)=_6e5d_mpl3_pneg((term->p)));
	};
	_6e5d_mpl3_normalize(out,idx);
}
