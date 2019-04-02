#include<iostream>

using namespace std;

struct Monomio
{
	int coef;
	int exponent;
};

struct Polinom{
	Monomio mon[50];
	int nmonomios=0;
};

bool read(Polinom *p, int co, int ex){
	if(co == -1||ex==-1)
		return 1;
	else{
		p->mon[p->nmonomios].coef=co;
		p->mon[p->nmonomios].exponent=ex;
		p->nmonomios++;
		return 0;
	}
}

void write(Polinom p){
	for(int i = 0; i < p.nmonomios; i++)
		cout << p.mon[i].coef << "x^" << p.mon[i].exponent << " ";
}

Polinom add(Polinom TP1, Polinom TP2){
	Polinom res;
	for(int i = 0; i < TP1.nmonomios; i++){
		bool encontrado = false;
		for(int j = 0; j < TP2.nmonomios; j++){
			if(TP1.mon[i].exponent==TP2.mon[j].exponent){
				res.mon[i].exponent = TP1.mon[i].exponent;
				res.mon[i].coef = TP1.mon[i].coef + TP2.mon[j].coef;
				encontrado = true;
				res.nmonomios++;
			}
		}
		if(!encontrado){
			res.mon[i].exponent = TP1.mon[i].exponent;
			res.mon[i].coef = TP1.mon[i].coef;
			res.nmonomios++;
		}
	}
	
	for(int i=0;i<TP2.nmonomios;i++){
		bool encontrado = false;
		for(int j=0; j< res.nmonomios; j++){
			if(TP2.mon[i].exponent == res.mon[i].exponent)
				encontrado = true;
		}
		if(!encontrado){
			res.mon[res.nmonomios].exponent = TP2.mon[i].exponent;
			res.mon[res.nmonomios].coef = TP2.mon[i].coef;
			res.nmonomios++;
		}
	}
	return res;
}

Polinom mul(Polinom TP1, Polinom TP2){
	Polinom res;
	int etmp, ctmp;
	for(int i=0; i < TP1.nmonomios; i++){
		for(int j=0; j < TP2.nmonomios;j++){
			etmp = TP1.mon[i].exponent+TP2.mon[j].exponent;
			ctmp = TP1.mon[i].coef*TP2.mon[j].coef;
			bool existe = false;
			for(int k = 0; k< res.nmonomios && !existe; k++){
				if(etmp == res.mon[k].exponent){
					res.mon[k].coef +=  ctmp;
					existe = true;
				}
			}
			if(!existe){
				res.mon[res.nmonomios].coef = ctmp;
				res.mon[res.nmonomios].exponent = etmp;
				res.nmonomios++;
			}
		}
	}
	return res;
}

int main(){
	int c, e;
	bool salida = false;
	Polinom p1, p2, res;
	while(!salida){
		cout << "Write the coef and the exponent, use -1 for end: ";
		cin >> c;
		cin >> e;
		salida = read(&p1,c,e);
	}
	
	salida = false;
	
		while(!salida){
		cout << "Write the coef and the exponent, use -1 for end: ";
		cin >> c;
		cin >> e;
		salida = read(&p2,c,e);
	}
	
	cout << "POLINOM 1: ";
	write(p1);
	cout << "POLINOM 2: ";
	write(p2);
	cout << "ADD: ";
	res = add(p1,p2);
	write(res);
	cout << "MUL: ";
	res = mul(p1,p2);
	write(res);
	
	

	return 0;
}



