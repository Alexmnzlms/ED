#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include "diccionario.h"
#include "letra.h"
#include "bolsa_letras.h"

using namespace std;

bool Contiene(char a, const vector<char>& letras){
    char am = toupper(a);
    bool contiene = false;
    for(unsigned i = 0; i < letras.size() && !contiene ; i++){
        if(am == letras[i])
            contiene = true;
    }

    return contiene;
}
bool Contieneletrasvalidas(string comprobar, const vector<char>& letras){
    bool contiene = true;
    for(unsigned i = 0; i < comprobar.size() && contiene; i++){
        if(!Contiene(comprobar[i], letras))
            contiene = false;
    }
    return contiene;
}
Letra Encontrar(char a, const ConjuntoLetras& l){
    char am = toupper(a);
    ConjuntoLetras::iterator i;
    bool salir = false;
    Letra letra;
    for(i = l.begin(); i != l.end() && !salir; ++i){
        if(i->getLetra() == am){
            salir = true;
            letra = *i;
        }
    }

    return letra;
}
int Puntuacion(int modalidad, string solucion, const ConjuntoLetras& l){
    int punt = 0;
    if(modalidad == 0){
        for(unsigned i = 0; i < solucion.size(); i++){
            Letra letra = Encontrar(solucion[i], l);
            punt += letra.getPuntuacion();
        }
    }
    else if(modalidad == 1){
        punt = (int)solucion.size();
    }
        
    return punt;
}
bool Utilizanumeroletrascorrecto(string solucion, const vector<char>& letras){
    vector<pair<char, int>> s, l;
    bool correcto = true;
    bool coincidencia;
    for(unsigned i = 0; i < solucion.size(); i++){
        coincidencia = false;
        for(unsigned j = 0; j < s.size(); j++){
            if(toupper(solucion[i]) == s[j].first && s.size() != 0){
                s[j].second++;
                coincidencia = true;
            }
        }
        if(!coincidencia){
            pair<char, int> letra;
            letra.first = toupper(solucion[i]);
            letra.second = 1;
            s.push_back(letra);
        }
    }

    for(unsigned i = 0; i < letras.size(); i++){
        coincidencia = false;
        for(unsigned j = 0; j < l.size(); j++){
            if(letras[i] == l[j].first && l.size() != 0 ){
                l[j].second++;
                coincidencia = true;
            }
        }
        if(!coincidencia){
            pair<char, int> letra;
            letra.first = letras[i];
            letra.second = 1;
            l.push_back(letra);
        }
    }

    for(unsigned i = 0; i < s.size(); i++){
        for(unsigned j = 0; j < l.size(); j++){
            if(s[i].first == l[j].first){
                if(s[i].second > l[j].second){
                    correcto = false;
                }
            }
        }
    }
    return correcto;
}
int main(int argc, char *argv[]){
    string seguir;
    int modalidad;
    string solucion;

    if (argc!=5){
        cout << "Formato: <diccionario> <letras> <n_letras> <modo>" << endl;
        return 0;
    }

    ifstream dic (argv[1]);
    if (!dic){
        cout << "No puedo abrir el fichero " << argv[1] << endl;
        return 0;
    }

    ifstream let (argv[2]);
    if (!let){
        cout << "No puedo abrir el fichero " << argv[2] << endl;
        return 0;
    }

    if (atoi(argv[3]) <= 0){
        cout << "El cuarto argumento debe ser mayor de 0: " << argv[3] << endl;
        return 0;
    }

    if (argv[4] == string("P")){
        cout << "Modalidad puntos seleccionada" << endl;
        modalidad = 0;
    }
    else if(argv[4] == string("L")){
        cout << "Modalidad longitud seleccionada" << endl;
        modalidad = 1;
    }
    else{
        cout << "El cuarto argumento debe ser L o P: " << argv[4] << endl;
        return 0;
    }

    Diccionario d;
    ConjuntoLetras l;
    BolsaLetras bolsa;
    vector<char> letras;

    cout << "Comenzando carga del diccionario" << endl;
    dic >> d;
    cout << "Carga del diccionario finalizada" << endl;

    cout << "Comenzado carga del conjunto letras" << endl;
    let >> l;
    cout << "Carga del conjunto letras finalizado" << endl;
    do{

	    bolsa.Rellenar(l);
	    if(bolsa.Tamanio() < atoi(argv[3])){
		bolsa.Rellenar(l);
	    }

	    letras = bolsa.Cogerletras(atoi(argv[3]));

	    cout << "Las letras son: ";
	    vector<char>::iterator i;
	    for(i = letras.begin();i != letras.end();i++){
		cout << (*i) << "	";
	    }

	    cout << endl << "Dime tu solucion: " << endl;

	    cin >> solucion;

	    if(d.Esta(solucion)){
            if(Contieneletrasvalidas(solucion, letras) && Utilizanumeroletrascorrecto(solucion, letras)){
                vector<string> mis_soluciones;
                Diccionario::iterator i;
                for(i = d.begin(); i != d.end(); ++i){
                    if((Puntuacion(modalidad, *i, l) > Puntuacion(modalidad, solucion, l)) && Contieneletrasvalidas(*i, letras) && Utilizanumeroletrascorrecto(*i, letras)){
                        mis_soluciones.push_back(*i);
                    }
                }

                vector<string>::iterator k;
                string maximo;
                if(mis_soluciones.empty()){
                    maximo = "";
                }
                else{
                    maximo = *(mis_soluciones.begin());
                    for(k = mis_soluciones.begin(); k != mis_soluciones.end(); ++k){
                        if(Puntuacion(modalidad, *k, l) > Puntuacion(modalidad, maximo, l)){
                            maximo = *k;
                        }
                    }
                    cout << endl << "Mis soluciones son: " << endl;
                    for(k = mis_soluciones.begin(); k != mis_soluciones.end(); ++k){
                        if(Puntuacion(modalidad, *k, l) == Puntuacion(modalidad,maximo, l)){
                            cout << *k;
                            cout << " Puntuacion: " << Puntuacion(modalidad, *k, l) << endl;
                        }
                    }
                }
                
                cout << "-------------------------------------------------------------------------------------------------" << endl;
                cout << "Tu solucion: " << solucion << endl << "Puntos: " << Puntuacion(modalidad, solucion, l) << endl;
                cout << "Mi solucion: " << maximo << endl << "Puntos: " << Puntuacion(modalidad, maximo, l) << endl;
                if(Puntuacion(modalidad, solucion, l) > Puntuacion(modalidad, maximo, l)){
                    cout << "He perdido" << endl;
                }
                else {
                    cout << "Gane" << endl;
                }
                cout << "-------------------------------------------------------------------------------------------------" << endl;
            }
            else{
                cout << "Letras invalidas o Repites alguna letra" << endl;  
            }   
	    }
	    else{
		cout << "La palabra no se encuentra en el diccionario" << endl;
	   }
     do{
	cout << "Desea volver a jugar[s/n]?: " << endl;
	cin >> seguir;
     }while(seguir != "s" && seguir != "n");
   }while(seguir == "s");
	    

}
		

	





