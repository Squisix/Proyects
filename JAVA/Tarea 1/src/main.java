// Nombre: Tarea 1
// Fecha: 14/09/2020
// Autores:
//      Marco Antonio Guerrero Vasquez : 219202704
//      Luis Héctor Aguilar Valenzuela : 219207216
//      Santiago Valdenebro Campa      : 219222604
// Descripción: Programa que se encarga de trasnformar números binarios a números reales
//                  números reales a binarios, sumar los digitos de un número y capitalizar
//                      palabras.



public class main {

    public static double bin2Dec(double bin)
    {


        int enteroBin = (int)bin;
        String numero = String.valueOf(bin);
        String[] parts = numero.split("\\.");
        double digito;
        int enteroDecimal = 0;
        double fraccionDecimal = 0.0;
        int fraccionBin = Integer.parseInt(parts[1]);
        if(enteroBin !=0) {

            for (int i = 0; enteroBin != 0; ++i) {
                digito = enteroBin % 10;
                enteroDecimal += digito * (int) Math.pow(2, i);
                enteroBin /= 10;
            }
        }
        //Parte fraccionaria
        int contador = parts[1].length();
       if(fraccionBin != 0 ){
           for (int i = 0; fraccionBin != 0 ; ++i) {
               digito = fraccionBin % 10;
               fraccionDecimal += digito * Math.pow(2,-contador + i);
               fraccionBin = fraccionBin /10;
           }
       }

        return enteroDecimal+fraccionDecimal;


    }

    public static double dec2Bin(double dec)
    {
        String numero = String.valueOf(dec);
        String[] partes = numero.split("\\.");
        int enteroDecimal = Integer.parseInt(partes[0]);
        double enteroFracionario = Double.parseDouble(partes[1]);
        double digito, enteroBinario = 0.0;

        for(int i = 0; enteroDecimal != 0; ++i){
            digito = enteroDecimal % 2;
            enteroBinario += digito * Math.pow(10,i);
            enteroDecimal /= 2;
        }

        //parte fraccionaria
        enteroFracionario *= Math.pow(10,-(partes[1].length()));
        double binarioFraccionario = 0;

        for(int i = 0; enteroFracionario != 0; --i){
            enteroFracionario *= 2;
            digito = (int)enteroFracionario;
            enteroFracionario -=digito;
            binarioFraccionario += digito * Math.pow(10,i-1);
        }


        return enteroBinario+binarioFraccionario;

    }

    public static int sumaDigitos(int num)
    {
        int resultado = 0;
        while(num > 0) {
            resultado += num % 10;
            num = num / 10;
        }
        return resultado;
    }

    public static String capitaliza(String str)
    {

        String[] separadaPorEspacios = str.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int indice = 0; indice < separadaPorEspacios.length; indice++) {
            String palabra = separadaPorEspacios[indice];
            char primeraLetra = palabra.charAt(0);
            sb.append(Character.toUpperCase(primeraLetra));
            sb.append(palabra.substring(1));
            if (indice < separadaPorEspacios.length - 1)
                sb.append(" ");
        }
        return sb.toString();
    }

    public static void main(String[] args)
    {
        double bin = 111.010110011;
        double dec = bin2Dec(bin);
        System.out.println("Bin: " + bin + ", Dec: " + dec);

        dec = 7.35;
        bin = dec2Bin(dec);
        System.out.println("Dec: " + dec + ", Bin: " + bin);

        int num = 749;
        int sum = sumaDigitos(num);
        System.out.println("Num: " + num + ", Suma: " + sum);

        String str = "La patita va al mercado con rebozo de bolitas";
        String cap = capitaliza(str);
        System.out.println("String original: " + str + ", String capitalizado: " + cap);

    }
}
