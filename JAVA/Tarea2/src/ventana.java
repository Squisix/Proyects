// Nombre: Tarea 2
// Fecha: 30/10/2020
// Autor: Marco Antonio Guerrero Vasquez : 219202704
// Descripción: Clase que contiene los elementos de la ventana del programa, asi como sus acciones

import javax.swing.*;
import java.awt.event.*;

import static java.lang.Math. *;

public class ventana extends JFrame{


    private JPanel mainPanel;
    private JTextField tf_a;
    private JComboBox cb_signo1;
    private JTextField tf_b;
    private JPanel pnl_ni1;
    private JPanel pnl_ni2;
    private JTextField tf_c;
    private JTextField tf_d;
    private JComboBox cb_signo2;
    private JButton btn_info;
    private JComboBox comboBox1;
    private JButton btn_limpiar1;
    private JButton btn_limpiar2;
    private JButton btn_limpiarTodo;
    private JButton btn_calcular;
    private JTextArea txtA_resultado;


    // Ventana del programa
    public ventana(){
        super("Números Complejos");

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setContentPane(mainPanel);
        setSize(425,420);
        setLocation(200,50);

        /*              Eventos de la ventana                   */

        // Boton calcular
        btn_calcular.addActionListener(e -> {
            try {
                Operaciones(); /* Llama a la función Operaciones */
            }catch (Exception ev) {
                JOptionPane.showMessageDialog(null,
                        "Ocurrió un error, revise la entrada",
                        "Error", JOptionPane.ERROR_MESSAGE);
            }
        });

        // Combobox con las operaciones
        comboBox1.addActionListener(e -> {
            switch(comboBox1.getSelectedIndex()){
                case 0, 1, 2, 3 -> pnl_ni2.setVisible(true);
                case 4, 5, 6 -> pnl_ni2.setVisible(false);

            }
        });

        /*               Pone un 0 de manera automatica en las celdas si no hay escrito nada             */
        tf_a.addFocusListener(new FocusAdapter() {
            @Override
            public void focusLost(FocusEvent e) {
                super.focusLost(e);
                if(tf_a.getText().equals("")){
                    tf_a.setText("0");
                }
            }
        });
        tf_b.addFocusListener(new FocusAdapter() {
            @Override
            public void focusLost(FocusEvent e) {
                super.focusLost(e);
                if(tf_b.getText().equals("")){
                    tf_b.setText("0");
                }
            }
        });
        tf_c.addFocusListener(new FocusAdapter() {
            @Override
            public void focusLost(FocusEvent e) {
                super.focusLost(e);
                if(tf_c.getText().equals("")){
                    tf_c.setText("0");
                }
            }
        });
        tf_d.addFocusListener(new FocusAdapter() {
            @Override
            public void focusLost(FocusEvent e) {
                super.focusLost(e);
                if(tf_d.getText().equals("")){
                    tf_d.setText("0");
                }
            }
        });

        /* //////////////////////////////////////////////////////////////////////////////////////////////////// */
        /*                      Botones que limpian las celdas                                 */
        btn_limpiar1.addActionListener(e -> {
            tf_a.setText("0");
            tf_b.setText("0");
            cb_signo1.setSelectedIndex(0);
        });
        btn_limpiar2.addActionListener(e -> {
            tf_c.setText("0");
            tf_d.setText("0");
            cb_signo2.setSelectedIndex(0);
        });
        btn_limpiarTodo.addActionListener(e -> {
            tf_a.setText("0");
            tf_b.setText("0");
            tf_c.setText("0");
            tf_d.setText("0");
            cb_signo1.setSelectedIndex(0);
            cb_signo2.setSelectedIndex(0);
        });
        /* //////////////////////////////////////////////////////////////////////////////////////////////////////// */
        /* Información del programa */
        btn_info.addActionListener(e -> JOptionPane.showMessageDialog(null,"Programa que te permite hacer operaciones basicas \n" +
                "con números complejos de forma binomial: (a+bi)\n\n" +
                "*Introduce la parte real en los cuadros de la parte\n" +
                "izquierda y la parte imaginaria en la parte derecha.\n\n" +
                "*Selecciona el simbolo de la parte imaginaria,\n" +
                "elige una operación y da click en CALCULAR\n\n" +
                "Programa elaborado con fines educativos para \n" +
                "la UNIVERSIDAD DE SONORA (UNISON)\n" +
                        "Elaborado por: Marco Antonio Guerrero Vasquez",
                "INFO",JOptionPane.INFORMATION_MESSAGE));
        /* //////////////////////////////////////////////////////////////////////////////////////////////////////// */
        /* Cambia a un elemento vació si el campo de texto es igual a 0 */
        tf_a.addFocusListener(new FocusAdapter() {
            @Override
            public void focusGained(FocusEvent e) {
                super.focusGained(e);
                if(tf_a.getText().equals("0")){
                    tf_a.setText("");
                }
            }
        });
        tf_b.addFocusListener(new FocusAdapter() {
            @Override
            public void focusGained(FocusEvent e) {
                super.focusGained(e);
                if(tf_b.getText().equals("0")){
                    tf_b.setText("");
                }
            }
        });
        tf_c.addFocusListener(new FocusAdapter() {
            @Override
            public void focusGained(FocusEvent e) {
                super.focusGained(e);
                if(tf_c.getText().equals("0")){
                    tf_c.setText("");
                }
            }
        });
        tf_d.addFocusListener(new FocusAdapter() {
            @Override
            public void focusGained(FocusEvent e) {
                super.focusGained(e);
                if(tf_d.getText().equals("0")){
                    tf_d.setText("");
                }
            }
        });
        /* ///////////////////////////////////////////////////////////////////////////////////////////////////// */
        /*              Restringe el uso de caracteres en los campos de texto            */
        tf_a.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                super.keyTyped(e);
                char validar = e.getKeyChar();
                if(Character.isLetter(validar)){
                    e.consume();
                    JOptionPane.showMessageDialog(rootPane, "Ingrese números solamente");
                }
            }
        });
        tf_b.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                super.keyTyped(e);
                char validar = e.getKeyChar();
                if(Character.isLetter(validar)){
                    e.consume();
                    JOptionPane.showMessageDialog(rootPane, "Ingrese números solamente");
                }else if(validar == '-'){
                    e.consume();
                    JOptionPane.showMessageDialog(rootPane, "Por favor, use el símbolo del panel");
                }
            }
        });
        tf_c.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                super.keyTyped(e);
                char validar = e.getKeyChar();
                if(Character.isLetter(validar)){
                    e.consume();
                    JOptionPane.showMessageDialog(rootPane, "Ingrese números solamente");
                }
            }
        });
        tf_d.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                super.keyTyped(e);
                char validar = e.getKeyChar();
                if(Character.isLetter(validar)){
                    e.consume();
                    JOptionPane.showMessageDialog(rootPane, "Ingrese números solamente");
                }else if(validar == '-'){
                    e.consume();
                    JOptionPane.showMessageDialog(rootPane, "Por favor, use el símbolo del panel");
                }
            }
        });
        //*********************************************************************************************************//
    }

    // Función que se encarga de administrar las operaciones
    private void Operaciones(){
        int operacion = comboBox1.getSelectedIndex();
        int signo1;
        int signo2;
        Complejo z1 = new Complejo();
        Complejo z2 = new Complejo();
        Complejo z3 = new Complejo();
        switch (operacion) {
            // 0 - Suma
            // 1 - Resta
            // 2 - Multiplicación
            // 3 - División
            case 0, 1, 2, 3 -> {
                z1.setReal(Double.parseDouble(tf_a.getText()));
                signo1 = cb_signo1.getSelectedIndex();
                if (signo1 == 0) {
                    z1.setImaginario(Double.parseDouble(tf_b.getText()));
                } else if (signo1 == 1) {
                    z1.setImaginario(-Double.parseDouble(tf_b.getText()));
                }
                z2.setReal(Double.parseDouble(tf_c.getText()));
                signo2 = cb_signo2.getSelectedIndex();
                if (signo2 == 0) {
                    z2.setImaginario(Double.parseDouble(tf_d.getText()));
                } else if (signo2 == 1) {
                    z2.setImaginario(-Double.parseDouble(tf_d.getText()));
                }
            }
            // 4 - Conjugado
            // 5 - Reciproco
            // 6 - Raíz Cuadrada
            case 4, 5, 6 -> {
                z1.setReal(Double.parseDouble(tf_a.getText()));
                signo1 = cb_signo1.getSelectedIndex();
                if (signo1 == 0) {
                    z1.setImaginario(Double.parseDouble(tf_b.getText()));
                } else if (signo1 == 1) {
                    z1.setImaginario(-Double.parseDouble(tf_b.getText()));
                }
            }
        }

        switch (operacion) {
            case 0 -> {
                z3 = z1.SumarComplejo(z2);
                txtA_resultado.setText(EscribirResultado(z3));// 0 - Suma
            }
            case 1 -> {
                z3 = z1.RestarComplejo(z2);
                txtA_resultado.setText(EscribirResultado(z3));      // 1 - Resta
            }
            case 2 -> {
                z3 = z1.MultiplicarComplejo(z2);
                txtA_resultado.setText(EscribirResultado(z3));// 2 - Multiplicación
            }
            case 3 -> {
                if(z2.getReal() == 0 && z2.getImaginario() == 0){
                    JOptionPane.showMessageDialog(null,
                            "No se puede dividir entre 0",
                            "Error", JOptionPane.ERROR_MESSAGE);
                } else {
                    z3 = z1.DividirComplejo(z2);
                    txtA_resultado.setText(EscribirResultado(z3));
                } // 3 - División
            }
            case 4 -> {
                z2 = z1.ConjugadoComplejo();
                txtA_resultado.setText(EscribirResultado(z2));// 4 - Conjugado
            }
            case 5 -> {
                if(z1.getReal() == 0 && z1.getImaginario() == 0){
                    JOptionPane.showMessageDialog(null,
                            "0 no tiene reciproco",
                            "Error", JOptionPane.ERROR_MESSAGE);
                } else {
                    z2 = z1.ReciprocoComplejo();
                    txtA_resultado.setText(EscribirResultado(z2));
                }// 5 - Reciproco
            }
            case 6 -> {
                z2 = z1.RaizCuadradaComplejo();

                String Resultado = "";
                if(z2.getReal() != 0){
                    if(z2.getImaginario() == 0 && z2.getReal() < 0){
                        Resultado = String.format("+ ( %.4f i)\n- (%.4f i)", abs(z2.real),abs(z2.real));
                    } else if(z2.getImaginario() < 0) {
                        Resultado = String.format("+ (%.4f - %.4f i)\n- (%.4f - %.4f i)", z2.real,abs(z2.imaginario),z2.real,abs(z2.imaginario));
                    } else if(z2.getImaginario() > 0){
                        Resultado = String.format("+ (%.4f + %.4f i)\n- (%.4f + %.4f i)", z2.real,abs(z2.imaginario),z2.real,abs(z2.imaginario));
                    } else if(z2.getImaginario() == 0){
                        Resultado = String.format("+ %.4f\n- %.4f", abs(z2.real),abs(z2.real));
                    }
                }else if(z2.getReal() == 0){
                    if(z2.getImaginario() != 0) {
                        Resultado = String.format("+ (%.4f i)\n- (%.4f i)", z2.imaginario,z2.imaginario);
                    } else if(z2.getImaginario() == 0){
                        Resultado = "0";
                    }
                }
                txtA_resultado.setText(Resultado);

            }// 6 - Raíz Cuadrada
        }
    }


    // Función que se encarga de dar formato al resultado del número complejo
    private String EscribirResultado(Complejo z){
        String Resultado = "";
        if(z.getReal() != 0){
            if(z.getImaginario() < 0) {
                Resultado = String.format("%.4f - %.4f i", z.real,abs(z.imaginario));
            } else if(z.getImaginario() > 0){
                Resultado = String.format("%.4f + %.4f i", z.real,abs(z.imaginario));
            } else if(z.getImaginario() == 0){
                Resultado = String.format("%.4f", z.real);
            }
        }else if(z.getReal() == 0){
            if(z.getImaginario() < 0) {
                Resultado = String.format(" - %.4f i",abs(z.imaginario));
            } else if(z.getImaginario() > 0){
                Resultado = String.format("%.4f i",abs(z.imaginario));
            } else if(z.getImaginario() == 0){
                Resultado = "0";
            }
        }
        return Resultado;
    }

}
