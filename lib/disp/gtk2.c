#include <gtk/gtk.h>

int gtk2(int argc, char *argv[]) {
    
  GtkWidget *box = gtk_box_new(0,0);
  GtkWidget *window;
  GtkWidget *image;
  GtkWidget *image2;
  GError *error=NULL;
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "Bode plot");

  image = gtk_image_new_from_file("bodeplot-mag.png");
  image2= gtk_image_new_from_file("bodeplot-phase.png");

 // image = gtk_image_new_from_file_at_size("result2.png",100,100,&error);
//  image2= gtk_image_new_from_file_at_size("plot.png",100,100,&error);

  
  gtk_container_add(GTK_CONTAINER(box),image);
  gtk_container_add(GTK_CONTAINER(box),image2);
  gtk_container_add(GTK_CONTAINER(window),box);
//  gtk_container_add(GTK_CONTAINER(window), image);

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
