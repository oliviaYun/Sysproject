#include <gtk/gtk.h>

int
main (int   argc,
char *argv[])
{
 GtkWidget *plot;
  GtkWidget *window;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

 plot = gtk_image_new_from_file("result.png");
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  gtk_widget_show (window);
 gtk_widget_show(iam)
  gtk_main ();

  return 0;
}
