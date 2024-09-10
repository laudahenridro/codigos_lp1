#ifndef FUNCTION_H
	#define FUNCTION_H
	
	struct no{
		int valor;
		struct no** seguinte;
	};
	void insere_inicio(struct no**, int);
	void exclui_valor(struct no**, int);
	void exclui_lista(struct no**);
	void imprime(struct no*);
	struct no* criaElem(int);
#endif
