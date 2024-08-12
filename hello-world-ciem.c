/**
 * Adaptado por Oscar Herrera
 * Comentarios traducidos y resumidos por Christian Morga
 * código original en https://calcifer.org/documentos/librognome/gtk-basic-example.html
 * gcc `pkg-config --cflags gtk+-3.0` hello-world.c -o helloworldEXE `pkg-config --libs gtk+-3.0`
 */

#include <gtk/gtk.h>

/* Callback simple, ignora los argumentos de datos */
void hello( GtkWidget *widget, gpointer data )
{
  g_print ("Hello World\n");
}

gint delete_event( GtkWidget *widget,
                   GdkEvent *event,
                   gpointer data )
{
  /* Muestra un mensaje cuando se intenta cerrar la ventana */
  g_print ("Ocurrió el evento delete\n");

  /* Retornar TRUE evita que la ventana se cierre */
  return TRUE;
}

/* Callback para salir de gtk_main */
void destroy( GtkWidget *widget, gpointer data )
{
    gtk_main_quit ();
}

int main( int argc, char *argv[] )
{
  /* Almacena los widgets */
  GtkWidget *window;
  GtkWidget *button;

  /* Inicializa GTK */
  gtk_init (&argc, &argv);

  /* Crea una nueva ventana */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  /* Conecta el evento "delete_event" con su callback */
  g_signal_connect (G_OBJECT (window), "delete_event",
                    G_CALLBACK (delete_event), NULL);

  /* Conecta el evento "destroy" con su callback */
  g_signal_connect (G_OBJECT (window), "destroy",
                    G_CALLBACK (destroy), NULL);

  /* Establece el ancho del borde de la ventana */
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  /* Crea un botón con la etiqueta "Hello World" */
  button = gtk_button_new_with_label ("Christian Morga");

  /* Conecta el evento "clicked" del botón con su callback */
  g_signal_connect (G_OBJECT (button), "clicked",
                    G_CALLBACK (hello), NULL);

  /* Destruye la ventana al hacer clic en el botón */
  g_signal_connect_swapped (G_OBJECT (button), "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            G_OBJECT (window));

  /* Añade el botón a la ventana */
  gtk_container_add (GTK_CONTAINER (window), button);

  /* Muestra el botón */
  gtk_widget_show (button);

  /* Muestra la ventana */
  gtk_widget_show (window);

  /* Entra en el bucle principal de GTK */
  gtk_main ();

  return 0;
}
