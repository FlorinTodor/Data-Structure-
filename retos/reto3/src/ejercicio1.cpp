#include <iostream>
#include <stack>
#include <list>

using namespace std;

void Borrar(list<stack<int> > & L, int elemento){
    list<stack<int>>::iterator it = L.begin();

    while(it != L.end()) {
        if (it->top() == elemento) {
            L.pop_back();
        }
        ++it;

    }

    list<stack<int>> aa;
    list<stack<int>>::iterator aux = aa.begin();

    //Ordenacion por burbuja
    for(it ; it !=L.end(); ++it){
        for(it++; ++it != --L.end(); ++it){
            if(*it > *it++ ) {
                aa.push_back(*it++);
                it = it++;
                L.push_back(*it);
            }
        }
    }
}
