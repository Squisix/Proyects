// Nombre: Tarea 2
// Fecha: 30/10/2020
// Autor: Marco Antonio Guerrero Vasquez : 219202704
// Descripción: Clase que administra la manipulación de numeros complejos así como sus operaciones
import static java.lang.Math. *;

public class Complejo {
    double real;        /* Parte real del número complejo */
    double imaginario;  /* Parte imaginaria del número complejo */

    //Constructores
    public Complejo(){
    }

    public Complejo(double real, double imaginario){
        this.real = real;
        this.imaginario = imaginario;
    }

    public double getReal() {
        return real;
    }

    public void setReal(double real) {
        this.real = real;
    }

    public double getImaginario() {
        return imaginario;
    }

    public void setImaginario(double imaginario) {
        this.imaginario = imaginario;
    }

    /**
     * @brief Sirve para sumar dos números complejos
     * @param z2 Segundo número complejo
     * @return Regresa el resultado de la operación SUMA
     */
    public Complejo SumarComplejo(Complejo z2){
        Complejo z3 = new Complejo();

        double resultadoReal = this.real + z2.getReal();
        double resultadoImaginario = this.imaginario + z2.getImaginario();
        z3.setReal(resultadoReal);
        z3.setImaginario(resultadoImaginario);
        return z3;
    }

    /**
     * @brief Sirve para restar dos números complejos
     * @param z2 Segundo número complejo
     * @return Regresa el resultado de la operación RESTA
     */
    public Complejo RestarComplejo(Complejo z2){
        Complejo z3 = new Complejo();

        double resultadoReal = this.real - z2.getReal();
        double resultadoImaginario = this.imaginario - z2.getImaginario();
        z3.setReal(resultadoReal);
        z3.setImaginario(resultadoImaginario);
        return z3;
    }
    /**
     * @brief Sirve para multiplicar dos números complejos
     * @param z2 Segundo número complejo
     * @return Regresa el resultado de la operación MULTIPLICACIÓN
     */
    public Complejo MultiplicarComplejo(Complejo z2){
        Complejo z3 = new Complejo();

        double resultadoReal = ((this.real*z2.getReal())-(this.imaginario*z2.getImaginario()));/*(ac-bd)+(ad+bc)i*/
        double resultadoImaginario = ((this.real*z2.getImaginario())+(this.imaginario*z2.getReal()));
        z3.setReal(resultadoReal);
        z3.setImaginario(resultadoImaginario);
        return z3;
    }
    /**
     * @brief Sirve para dividir dos números complejos
     * @param z2 Segundo número complejo
     * @return Regresa el resultado de la operación DIVISION
     * @pre El número real y el número imaginario del segundo número complejo no puede ser 0
     */
    public Complejo DividirComplejo(Complejo z2){
        Complejo z3 = new Complejo();

        double resultadoReal = (this.real*z2.getReal()+this.imaginario+z2.getImaginario())
                / (z2.getReal()*z2.getReal() + z2.getImaginario()*z2.getImaginario());

        double resultadoImaginario = (this.imaginario*z2.getReal() - this.real * z2.getImaginario())
                /(z2.getReal()*z2.getReal()+z2.getImaginario()+ z2.getImaginario());

        z3.setReal(resultadoReal);
        z3.setImaginario(resultadoImaginario);
        return z3;
    }

    /**
     * @brief Sirve para calcular el conjugado de un número complejo
     * @return Regresa el número complejo conjugado
     */
    public Complejo ConjugadoComplejo(){
        Complejo z2 = new Complejo();
        z2.setReal(this.real);
        z2.setImaginario(this.imaginario * -1);
        return z2;
    }

    /**
     * @brief Sirve para calcular el reciproco de un número complejo
     * @return Regresa el número complejo conjugado
     * @pre El número complejo no puede ser 0
     */
    public Complejo ReciprocoComplejo(){
        Complejo z2 = new Complejo();
            z2.setReal(this.real / (this.real * this.real + this.imaginario * this.imaginario));
            z2.setImaginario(-this.imaginario / (this.real * this.real + this.imaginario * this.imaginario));
        return z2;
    }

    /**
     * @brief Calcula la raiz cuadrada de un número complejo
     * @return Regresa la raiz del número complejo
     */
    public Complejo RaizCuadradaComplejo(){
        Complejo z2 = new Complejo();
        double ResultadoReal = 0;
        double ResultadoImaginario = 0;
        if(this.imaginario == 0) {
            if (this.real == 0) {
                ResultadoImaginario = 0;
                ResultadoReal = 0;
            } else if (this.real > 0) {
                ResultadoImaginario = 0;
                ResultadoReal = sqrt(this.real);
            } else if(this.real < 0){
                ResultadoReal = 0;
                ResultadoImaginario = abs(sqrt(this.real));
            }
        }else if(this.imaginario > 0){
            ResultadoReal = sqrt((this.real+sqrt(this.real*this.real+this.imaginario*this.imaginario))/2);
            ResultadoImaginario = sqrt((-this.real+sqrt(this.real*this.real+this.imaginario*this.imaginario))/2);
        }else if(this.imaginario < 0){
            ResultadoReal = sqrt((this.real+sqrt(this.real*this.real+this.imaginario*this.imaginario))/2);
            ResultadoImaginario = -sqrt((-this.real+sqrt(this.real*this.real+this.imaginario*this.imaginario))/2);
        }

        z2.setReal(ResultadoReal);
        z2.setImaginario(ResultadoImaginario);
        return z2;
    }
}
