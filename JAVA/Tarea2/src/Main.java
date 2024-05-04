// Nombre: Tarea 1
// Fecha: 30/10/2020
// Autor: Marco Antonio Guerrero Vasquez : 219202704
// Descripción: Programa que hace operaciones basicas con números complejos
import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        try {
            for (UIManager.LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (Exception e) {
            // If Nimbus is not available, you can set the GUI to another look and feel.
        }
        System.out.println("Imaginarios");

        JFrame window = new ventana();
        window.setVisible(true);
    }
}
