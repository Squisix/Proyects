// Nombre: PintaPanel.java
// Fecha: 28/11/2020
// Autor: Marco Antonio Guerrero Vasquez : 219202704
// Descripción: Clase que se encarga de leer y dibujar los datos de la gráfica de dispersión

import javax.swing.*;
import java.awt.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

public class PintaPanel extends JPanel {

    private final ArrayList<Double> x = new ArrayList<>();  ///X
    private final ArrayList<Double> y = new ArrayList<>();  ///y
    private final ArrayList<Integer> clase = new ArrayList<>(); //clase

    private Color colorClase1 = Color.red;
    private Color colorClase2 = Color.blue;
    private Color colorClase3 = Color.magenta;
    private boolean vacio1 = false;
    private boolean vacio2 = false;
    private boolean vacio3 = false;
    private double maxX;
    private double maxY;

    public PintaPanel()
    {
        super();
    }

    /**
     * @brief Función que se encarga de leer el color de una clase de datos
     * @param clase valor de la clase de datos a evaluar
     * @return Color de la clase
     */
    public Color leeColor(int clase)
    {
        if (clase == 0){
            return colorClase1;
        }else if(clase == 1){
            return colorClase2;
        }else if(clase == 2){
            return colorClase3;
        }else return colorClase1;

    }

    /**
     * @brief Función que se encarga de verificar si los puntos de cierta clase seran dibujados vacios
     * @param clase Valor de la clase a verificar
     * @param d Estado de dibujo del punto. Si es verdadero el punto se dibuja vacio, en caso contrario se dibuja relleno
     */
    public void puntoVacio(int clase, boolean d){
        if (clase == 0){
            vacio1 = d;
        }else if(clase == 1){
            vacio2 = d;
        }else if(clase == 2){
            vacio3 = d;
        }
        repaint();
    }

    /**
     * @brief Función que se encarga de cambiar el color de los puntos de una clase de datos
     * @param clase Valor de la clase de datos la cual cambiará de color
     * @param color Color Nuevo de clase de datos
     */
    public void cambiaColor(int clase, Color color)
    {
        if (clase == 0){
            colorClase1 = color;
        }else if(clase == 1){
            colorClase2 = color;
        }else if(clase == 2){
            colorClase3 = color;
        }
        repaint();
    }

    /**
     * @brief Función que se encarga de cambiar los datos que se dibujaran al leer un archivo
     * @param archivo Nombre del archivo que se utilizará
     */
    public void cambiaDatos(String archivo)
    {
        x.clear();
        y.clear();
        clase.clear();

        try {
            BufferedReader handle = new BufferedReader(new FileReader(archivo));

            maxX = Double.NEGATIVE_INFINITY;
            maxY = Double.NEGATIVE_INFINITY;
            String linea;
            while ((linea = handle.readLine()) != null) {
                String[] datos = linea.trim().split("\\s+");
                double x1 = Double.parseDouble(datos[0]);
                double y1 = Double.parseDouble(datos[1]);
                int nClase = Integer.parseInt(datos[2]);
                if (x1 > maxX) {
                    maxX = x1;
                }
                if (y1 > maxY) {
                    maxY = y1;
                }
                x.add(x1);
                y.add(y1);
                clase.add(nClase);

            }

            repaint();

            handle.close();
        }
        catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Error",
                    e.getMessage(), JOptionPane.ERROR_MESSAGE);
        }
    }

    /**
     * @brief Función que se encarga de pintar la grafica
     * @param g Componente grafico a usar
     */
    public void paint(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        if (maxX == 0) {
            return;
        }

        int ancho = getWidth();
        int alto = getHeight();


        // Limpiar la pantalla
        g2.setColor(getBackground());
        g2.fillRect(0, 0, ancho, alto);

        // Puntos

        Transforma transforma = new Transforma((double)(-(int)maxX/ancho)-((int)maxX/7.5),
                (double)(-(int)maxY/alto)-((int)maxY/7.5), (int)maxX+1+((int)maxX/7.5),
                (int)maxY+1+((int)maxY/7.5),
                0, 0, ancho, alto);
        for (int i = 0; i < x.size(); i++) {
            Point p = transforma.proyectaw2v(x.get(i), y.get(i));
            if(clase.get(i) == 0){
                g2.setColor(colorClase1);
                if(vacio1){
                    g2.drawOval(p.x,p.y,4,4);
                }else{
                    g2.fillOval(p.x,p.y, 4, 4);
                }
            }else if(clase.get(i) == 1){
                g2.setColor(colorClase2);
                if(vacio2){
                    g2.drawOval(p.x,p.y,4,4);
                }else{
                    g2.fillOval(p.x,p.y, 4, 4);
                }
            }else if(clase.get(i) == 2){
                g2.setColor(colorClase3);
                if(vacio3){
                    g2.drawOval(p.x,p.y, 4, 4);
                }else{
                    g2.fillOval(p.x,p.y, 4, 4);
                }
            }



        }

        // Ejes
        g2.setColor(Color.black);
        g2.setStroke(new BasicStroke(2));
        // Eje X
        Point p = transforma.proyectaw2v(0, 0);
        Point q = transforma.proyectaw2v((int)maxX + 1, 0);
        g2.drawLine(p.x, p.y, q.x, q.y);
        // Eje Y
        q = transforma.proyectaw2v(0, (int)maxY +1);
        g2.drawLine(p.x, p.y, q.x, q.y);
        Color NegroTransparente = new Color(0,0,0,40);

        int divisionesX, divisionesY;
        divisionesX = getDivisionesX((int)maxX);
        divisionesY = getDivisionesX((int)maxY);
        //Divisiones en X
          for(int i = divisionesX; i <= (int)maxX+1; i+=divisionesX){
              g2.setStroke(new BasicStroke(2));
              g2.setColor(Color.black);
              p = transforma.proyectaw2v(i,-.07);
              q = transforma.proyectaw2v(i,0.07);
              g2.drawLine(p.x, p.y, q.x, q.y);

              g2.setColor(NegroTransparente);
              p = transforma.proyectaw2v(i,0);
              q = transforma.proyectaw2v(i,(int)maxY+1);
              g2.drawLine(p.x, p.y, q.x, q.y);
        }
          //Divisiones en Y
        for(int i = divisionesY; i <= (int)maxY+1; i+=divisionesY){
            g2.setColor(Color.black);
            g2.setStroke(new BasicStroke(2));
            p = transforma.proyectaw2v(-.05,i);
            q = transforma.proyectaw2v(.05,i);
            g2.drawLine(p.x, p.y, q.x, q.y);

            g2.setColor(NegroTransparente);
            p = transforma.proyectaw2v(0,i);
            q = transforma.proyectaw2v((int)maxX+1,i);
            g2.drawLine(p.x, p.y, q.x, q.y);
        }

        g2.setStroke(new BasicStroke(1));
        //y
        int auxDivX = divisionesX, auxDivY = divisionesY, cifrasX = 0, cifrasY = 0;
        while(auxDivX!=0){
            auxDivX = auxDivX/10;
            cifrasX++;
        }
        double decimalesX = divisionesX / Math.pow(10,cifrasX);
        while(auxDivY!=0){
            auxDivY = auxDivY/10;
            cifrasY++;
        }
        double decimalesY = divisionesY / Math.pow(10,cifrasY);

        for(double i = decimalesY; i <= (int)maxY+1; i+=decimalesY ){
            g2.setColor(Color.black);
            p = transforma.proyectaw2v(-.02,i);
            q = transforma.proyectaw2v(.02,i);
            g2.drawLine(p.x, p.y, q.x, q.y);

            g2.setColor(NegroTransparente);
            p = transforma.proyectaw2v(0,i);
            q = transforma.proyectaw2v((int)maxX+1,i);
            g2.drawLine(p.x, p.y, q.x, q.y);
        }
        //x
        for(double i = decimalesX; i <= (int)maxX+1; i+=decimalesX ){
            g2.setColor(Color.black);
            p = transforma.proyectaw2v(i,-0.03);
            q = transforma.proyectaw2v(i,0.03);
            g2.drawLine(p.x, p.y, q.x, q.y);

            g2.setColor(NegroTransparente);
            p = transforma.proyectaw2v(i,0);
            q = transforma.proyectaw2v(i,(int)maxY+1);
            g2.drawLine(p.x, p.y, q.x, q.y);
        }


        g2.setColor(Color.black);



        // Etiquetas de valores
        g2.setFont(new Font("Helvetica", Font.PLAIN, 15));
        for (int i = divisionesX; i <= (int)maxX+1; i+=divisionesX) {
            p = transforma.proyectaw2v(i-0.075, -(maxY/14));
            g2.drawString(""+i+"", p.x, p.y);
        }
        for (int i = divisionesY; i <= (int)maxY+1; i+=divisionesY) {
            p = transforma.proyectaw2v(-(maxX/14), i-0.075);
            g2.drawString(""+i+"", p.x, p.y);
        }
        p = transforma.proyectaw2v((int)maxX+1.1, 0);
        g2.drawString("X",p.x,p.y);
        p = transforma.proyectaw2v(0, (int)maxY+1.1);
        g2.drawString("Y",p.x,p.y);
    }

    /**
     * @brief Función privada auxiliar para obtener las divisiones de la grafica de acuerdo a el valor maximo en X o Y
     * @param maxXY Valor máximo en X o Y
     * @return Número de divisiones
     */
    private int getDivisionesX(int maxXY) {
        int divisiones = 0;
        if(maxXY +1 < 10){
            divisiones = 1;
        }else {
            if ((maxXY + 1) % 2 == 0) divisiones = 2 * ((maxXY + 1) % 10);
            else if ((maxXY + 1) % 2 != 0) divisiones = 2 * ((maxXY + 1) % 10) + 1;
        }
        return divisiones;
    }

    /**
     * @brief Función que se encarga de contar cuantos puntos hay de una clase determinada
     * @param cls Valor se la clase a la cual se obtendran los datos
     * @return Número de puntos de la clase escogida
     */
    public int contadorPuntos(int cls){
        int c1=0,c2=0,c3=0;
        for (Integer integer : clase) {
            if (integer == 0) c1++;
            else if (integer == 1) c2++;
            else if (integer == 2) c3++;
        }
        if(cls == 0) return c1;
        else if(cls == 1) return c2;
        else if(cls == 2) return c3;
        return 0;
    }
}
