//#include <graph.h>
#include <iostream>
using namespace std;

class Arista;
class Vertice{
    Vertice *sig;
    Arista *ady;
    string nombre;
    friend class Grafo;    
};

class Arista{
    Arista *sig;
    Vertice *ady;
    friend class Grafo;
};
class Grafo{
    Vertice *h;//apunta al primer vertice
    public:
        void Inicializa();
        bool Vacio();
        int Tamano();
        Vertice *GetVertice(string nombre);//para obtener la direccion de un vertice
        void InsertaArista(Vertice *origen,Vertice *destino);
        void InsertaVertice(string nombre);
        void ListaAdyacencia();
     //   void Caminos(Vertice *origen,Vertice *destino);
};
void Grafo::Inicializa(){
    h=NULL;
}

bool Grafo::Vacio(){
    if(h==NULL)
        return true;
    else 
        return false;
}
int Grafo::Tamano(){
    int cont=0;
    Vertice *aux;//recorre el grafo para contarlo
    aux = h;//inicializa al recorredor en el primer vertice del grafo
    while(aux!=NULL){//El ultimo vertice va a tener un sig a NULL  
        cont++;
        aux = aux->sig;
    }
    return cont;
}
Vertice *Grafo::GetVertice(string nombre){
    Vertice *aux;//para recorrer el grafo
    aux=h;//primer vertice
    while(aux!=NULL){
        if(aux->nombre == nombre)
            return aux;
        aux=aux->sig;
    }
    return NULL;
}
void Grafo::InsertaVertice(string nombre){
    Vertice *nuevo = new Vertice;
    nuevo->nombre = nombre;
    nuevo->sig = NULL;//aun no apunta a otro vertice
    nuevo->ady = NULL;//aun no hay aristas
    if(Vacio())
        h=nuevo;
    else{
        Vertice *aux;
        aux = h;
        while(aux->sig!=NULL){
            aux= aux->sig;
        }
        aux->sig=nuevo;
    }
}

void Grafo::InsertaArista(Vertice *origen,Vertice *destino){
    Arista *nueva = new Arista;
    nueva->sig = NULL;
    nueva->ady = NULL;
    
    Arista *aux;
    
    aux=origen->ady;

    if(aux == NULL){
        origen->ady = nueva;
        nueva->ady = destino; 
    }
    else {
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nueva;
        nueva->ady = destino;
    }
}
void Grafo::ListaAdyacencia(){
    Vertice *VertAux;
    Arista *AristAux;
    VertAux = h;
    while(VertAux != NULL){
        cout<< VertAux->nombre << "->";
        AristAux = VertAux->ady;
        while(AristAux != NULL){
            cout << AristAux->ady->nombre <<"->";
            AristAux = AristAux->sig;
        }
        VertAux = VertAux->sig;
        cout<<endl;
    }
}

/*void Grafo::Caminos(Vertice *origen,Vertice *destino){
    Vertice *VertAux;
    Arista *AristAux;
    VertAux = origen;
    while(VertAux != NULL){
        cout<< VertAux->nombre << "->";
        AristAux = VertAux->ady;
        while(AristAux != NULL){
            if(AristAux->ady->sig!=NULL)
        }
        VertAux = VertAux->sig;
    }
}

*/
int main(){
    Grafo G;
    G.Inicializa();
    G.InsertaVertice("V1");
    G.InsertaVertice("V2");
    G.InsertaVertice("V3");
    G.InsertaVertice("V4");
    G.InsertaVertice("V5");
    G.InsertaArista(G.GetVertice("V1"),G.GetVertice("V2"));
    G.InsertaArista(G.GetVertice("V1"),G.GetVertice("V3"));
    G.InsertaArista(G.GetVertice("V1"),G.GetVertice("V5"));
    G.InsertaArista(G.GetVertice("V2"),G.GetVertice("V4"));
    G.InsertaArista(G.GetVertice("V2"),G.GetVertice("V5"));
    G.InsertaArista(G.GetVertice("V3"),G.GetVertice("V4"));
    G.InsertaArista(G.GetVertice("V4"),G.GetVertice("V5"));
    G.ListaAdyacencia();
}
