import java.awt.*;
import java.awt.geom.Point2D;

public class Transforma {
    public double xmin, xmax, ymin, ymax;  // Limites de la ventana
    public double umin, umax, vmin, vmax;  // Limites del viewport (canvas)

    /*
     * Constructor
     */
    public Transforma(double x1, double y1, double x2, double y2,
                      double u1, double v1, double u2, double v2)
    {
        // Ventana
        xmin = x1;
        ymin = y1;
        xmax = x2;
        ymax = y2;

        // Viewport
        umin = u1;
        vmin = v1;
        umax = u2;
        vmax = v2;
    }

    /*
     * Proyecta un punto, p, de coordenadas en la ventana a coordenadas
     * en el viewport
     */
    public Point proyectaw2v (double x, double y)
    {
        double u = (umax - umin) * (x - xmin) / (xmax - xmin) + umin;
        double v = vmax - (vmax - vmin) * (y - ymin) / (ymax - ymin);

        return new Point((int) u, (int) v);
    }

    /*
     * Proyecta un punto, p, de coordenadas en el viewport a coordenadas
     * en la ventana
     */

    public Point2D.Double proyectav2w (int u, int v)
    {
        double x = (u - umin) * (xmax - xmin) / (umax - umin) + xmin;
        double y = (vmax - v) * (ymax - ymin) / (vmax - vmin) + ymin;

        return new Point2D.Double(x, y);
    }
}
