// Nombre: Ventana.java
// Fecha: 28/11/2020
// Autor: Marco Antonio Guerrero Vasquez : 219202704
// Descripción: Clase que se encarga de gestionar la ventana del programa
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.*;

public class Ventana extends JFrame {
    private JPanel panelRaiz;
    private JTextField clr_c1;
    private JLabel nClase1;
    private JLabel nClase2;
    private JTextField clr_c2;
    private JTextField clr_c3;
    private JLabel nClase3;
    private JLabel jl1;
    private JLabel jl2;
    private JLabel jl3;
    private JPanel controlPanel;
    private JPanel PanelSuperior;
    private JLabel NombreArchivo;
    private final PintaPanel pintaPanel = new PintaPanel();

    public Ventana()
    {
        super("Gráfica de Dispersión");
        clr_c1.setBackground(pintaPanel.leeColor(0));
        clr_c2.setBackground(pintaPanel.leeColor(1));
        clr_c3.setBackground(pintaPanel.leeColor(2));
        clr_c2.setVisible(false);
        clr_c1.setVisible(false);
        clr_c3.setVisible(false);
        nClase1.setVisible(false);
        nClase2.setVisible(false);
        nClase3.setVisible(false);
        jl1.setVisible(false);
        jl2.setVisible(false);
        jl3.setVisible(false);
        NombreArchivo.setVisible(false);

        JMenuBar barraMenu = new JMenuBar();
        JMenu archivoMenu = new JMenu("Archivo");
        JMenu opciones = new JMenu("Opciones");


        JMenuItem salirItem = new JMenuItem("Salir");
        salirItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_Q, InputEvent.ALT_DOWN_MASK));
        salirItem.addActionListener(e -> System.exit(0));

        JMenuItem abrirArchivoItem = new JMenuItem("Abrir archivo", KeyEvent.VK_F);
        abrirArchivoItem.setIcon(new ImageIcon("open-icon-16.png"));
        abrirArchivoItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_A, InputEvent.ALT_DOWN_MASK));
        abrirArchivoItem.addActionListener(e -> abreArchivo());

        // Elementos Clases
        JMenu clase1 = new JMenu("Clase 1");
        JMenu clase2 = new JMenu("Clase 2");
        JMenu clase3 = new JMenu("Clase 3");

        //Clase 1
                                /* Cambiar color */
        JMenuItem cambiaColorItem1 = new JMenuItem("Cambia color");
        cambiaColorItem1.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_C, InputEvent.ALT_DOWN_MASK));
        cambiaColorItem1.addActionListener(e -> cambiaColor(0));

                                /* Punto Relleno / Vacio */
        JCheckBox Vacio1 = new JCheckBox("Punto Vacio");
        Vacio1.addItemListener(e -> pintaPanel.puntoVacio(0, e.getStateChange() == ItemEvent.SELECTED));


        //Clase 2
                            /* Cambiar color */
        JMenuItem cambiaColorItem2 = new JMenuItem("Cambia color");
        cambiaColorItem2.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_C, InputEvent.ALT_DOWN_MASK));
        cambiaColorItem2.addActionListener(e -> cambiaColor(1));

                            /* Punto Relleno / Vacio */
        JCheckBox Vacio2 = new JCheckBox("Punto Vacio");
        Vacio2.addItemListener(e -> pintaPanel.puntoVacio(1, e.getStateChange() == ItemEvent.SELECTED));
        //Clase 3
                            /* Cambiar color */
        JMenuItem cambiaColorItem3 = new JMenuItem("Cambia color");
        cambiaColorItem3.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_C, InputEvent.ALT_DOWN_MASK));
        cambiaColorItem3.addActionListener(e -> cambiaColor(2));

        /* Punto Relleno / Vacio */
        JCheckBox Vacio3 = new JCheckBox("Punto Vacio");
        Vacio3.addItemListener(e -> pintaPanel.puntoVacio(2, e.getStateChange() == ItemEvent.SELECTED));
        archivoMenu.add(abrirArchivoItem);
        archivoMenu.add(new JSeparator());
        archivoMenu.add(salirItem);

        barraMenu.add(archivoMenu);

        barraMenu.add(opciones);
        opciones.add(clase1);
        opciones.add(clase2);
        opciones.add(clase3);

        clase1.add(cambiaColorItem1);clase1.add(Vacio1);
        clase2.add(cambiaColorItem2);clase2.add(Vacio2);
        clase3.add(cambiaColorItem3);clase3.add(Vacio3);
        setJMenuBar(barraMenu);

        setLayout(new BorderLayout());
        add(panelRaiz, BorderLayout.NORTH);
        add(pintaPanel, BorderLayout.CENTER);
        setSize(800, 800);
        setLocation(200, 50);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

    /**
     * @brief Función que gestiona el proceso de cambiar de color una clase de puntos
     * @param clase Valor de la clase que será cambiada de color
     */
    private void cambiaColor(int clase) {

        Color color = JColorChooser.showDialog(null,
                "Seleccional color", pintaPanel.leeColor(clase));
        if (color != null) {
            if(clase == 0){
                clr_c1.setBackground(color);
                pintaPanel.cambiaColor(clase, color);
            }else if(clase == 1){
                clr_c2.setBackground(color);
                pintaPanel.cambiaColor(clase, color);
            }else if(clase == 2){
                clr_c3.setBackground(color);
                pintaPanel.cambiaColor(clase, color);
            }
        }
    }

    /**
     * @brief Función que gestiona el proceso de abrir un archivo para graficar
     */
    private void abreArchivo()
    {
        JFileChooser chooser = new JFileChooser("");
        FileNameExtensionFilter filter = new FileNameExtensionFilter(
                "dat y txt", "dat", "txt");
        chooser.setFileFilter(filter);
        int valor = chooser.showOpenDialog(null);
        if (valor == JFileChooser.APPROVE_OPTION) {
            assert false;
            pintaPanel.cambiaDatos(chooser.getSelectedFile().getAbsolutePath());
            NombreArchivo.setText(chooser.getName(chooser.getSelectedFile()));
            clr_c1.setVisible(true);
            clr_c2.setVisible(true);
            clr_c3.setVisible(true);
            nClase1.setText(Integer.toString(pintaPanel.contadorPuntos(0)));
            nClase2.setText(Integer.toString(pintaPanel.contadorPuntos(1)));
            nClase3.setText(Integer.toString(pintaPanel.contadorPuntos(2)));
            nClase1.setVisible(true);
            nClase2.setVisible(true);
            nClase3.setVisible(true);
            jl1.setVisible(true);
            jl2.setVisible(true);
            jl3.setVisible(true);
            NombreArchivo.setVisible(true);

        }
    }
}
