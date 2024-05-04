#include <iostream>

using namespace std;
#include "Vector.h"
int main()
{
    try{
        Vector v(3,'V'),w(3,'W'),z(3,'Z');
        Vector x;
        cout << x;
        cout << "suma de dos vectores" << endl;
        cout << "Capturando las " << v.ObtenerDimension()
                << " componentes del primer vector..." << endl;
        cin >> v;
        cout << "Capturando las "<< w.ObtenerDimension()
                <<" componentes del segundo vector..." << endl;
        cin >> w;

        cout << z << endl;
        z = v;
        cout << z << endl;
        cout << "v = " << v << endl;
        cout <<"w = " << w << endl;
        cout << "v + w = " << v+w <<endl;




    }catch(out_of_range &exc){
        cout << "Error: " << exc.what() << endl;
    }catch(logic_error &exc){
        cout << "Error: " << exc.what() << endl;
    }catch(bad_alloc &exc){
        cout << "Error: falla en la asignaci\242n de memoria"  << endl;
    }
    return 0;
}
