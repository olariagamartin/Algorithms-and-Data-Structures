// Listas_01.cpp 
/* Las listas funcionas como cadenas, las cuales se componen de eslabones que llamamos "Nodos"
Estos nodos se componen de un dato que es el que define el tipo de cadena a formar, y una direccion
al siguiente eslabon o nodo. Para formar una lista se unen los nodos, esto es, se toma nodo que va a
ser el comienzo de la lista, para agregarle un nodo se guarda la direcci�n del dato de este nuevo
eslabon en el primer nodo que tiene una variable para esto, de este modo se van entrelazando los
los eslabones*/
//
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class Nodo {
private:
    T dato;
    Nodo* next;
public:
    Nodo() { next = NULL; }; //Constructor vacio
    //Puede dar un error
    Nodo(T a) { dato = a; next = NULL; }; //Constructor con param.
    void set_dato(T a) { dato = a; };
    void set_next(Nodo* n) { next = n; };
    T get_dato() { return dato; };
    Nodo* get_next() { return next; };
    bool es_vacio() { return next == NULL; }
    //Modificaci�n del original
    //bool es_vacio() { return &dato == NULL; }
};

template <class T> class Lista {
private: Nodo<T>* czo;
public:
    Lista() { czo = new Nodo<T>(); };
    Lista(Nodo<T>* n) { czo = n; };
    //~Lista(void);
    Nodo<T>* getCzo(){ return czo; }
    void add(T d);
    bool esvacia(void);
    T cabeza(void);
    Lista* resto(void);
    string toPrint(string p);
    T suma(T i);
    int size();// cantidad de nodos de la lista
    void borrar(void); //borra la cabeza
};

template <class T>
void Lista<T>::add(T d)
{
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->set_next(czo);
    czo = nuevo;
}

template <class T>
bool Lista<T>::esvacia(void)
{
    return czo->es_vacio();
}

template <class T>
T Lista<T>::cabeza(void)
{
    if (esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return NULL;
    }
    return czo->get_dato();
}

template <class T>
Lista<T>* Lista<T>::resto(void)
{
    Lista* l = new Lista(czo->get_next());
    return (l);
}

template <class T>
int Lista<T>::size(){
	if(this->esvacia())   return 0;
	return 1 + resto()->size();
}

template <class T>
void Lista<T>::borrar(){
	//TODO
	czo = resto()->getCzo();
}

template <class T>
string Lista<T>::toPrint(string p)
{
    if (this->esvacia()) {
        return p;
    }
    else {
        //std::ostringstream stm;
        ostringstream stm;
        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl;
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
        return stm.str();
    }
}

template <class T>
T Lista<T>::suma(T i)
{    //cout<<" i al entrar= "<<i<<endl;
    if (this->esvacia()) {
        return i;
    }
    else {

        //cout<<"this->cabeza()= "<<this->cabeza()<<endl;   
        return this->resto()->suma(i + this->cabeza());
    }
}

int main()
{
	//Prueba
//	Nodo<int>* nodo = new Nodo<int>(5);
//	Lista<int>* lista = new Lista<int>(nodo);
//	if(lista->esvacia())
//		cout << "La lista esta vacia" << endl;
//	else 
//		cout << "La lista no esta vacia" << endl;
//	 
//	 cout << "Sin embargo si me fijo en la cabeza tego el valor " << lista->getCzo()->get_dato() << endl;
	//...
    Lista<string>* l = new Lista<string>();
    Lista<int>* r = new Lista<int>();
    Lista<string>* l2 = new Lista<string>();
    l->add(" 11x");
    l->add(" 22y");
    l->add(" 33z");
    r->add(100);
    r->add(22);
    cout << "l= "<<l->toPrint("fin") << endl;
    cout << "r= " << r->toPrint("fin") << endl;
    cout << "suma:" << r->suma(0) << endl;
    
    cout<<endl << "Tama�o: " << l->size() <<endl;
    
    l->borrar();
    
    cout << "l= "<<l->toPrint("fin") << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;

}

/*
int size();// cantidad de nodos de la lista
void borrar(void); //borra la cabeza
void borrar_last();//borra el ultimo
void concat(Lista* l1);// le transfiere los datos de l1 a this
Lista* copy(void);// hace una copia de la lista
void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
*/
