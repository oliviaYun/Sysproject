#include <gtk/gtk.h> 

int main (int argc, char *argv[]){

  GtkWidget *window;

  gtk_init (&argc, &argv);

  window = gtk_window_new ( GTK_WINDOW_TOPLEVEL ) ;
   gtk_window_set_title (GTK_WINDOW (window), "Vertical Toolbar" ) ;
   gtk_widget_set_size_request (window, 450,300 ) ; // works

   GtkWidget * box = gtk_hbox_new (FALSE, 0);
   GtkWidget *n_box = gtk_hbox_new (TRUE, 0);

   GtkWidget * toolbar = gtk_toolbar_new ();
   gtk_widget_set_size_request (box, 30,30 ) ; // doesn't work

   gtk_toolbar_set_orientation( (GtkToolbar *)toolbar ,
                                 GTK_ORIENTATION_VERTICAL ) ;
   gtk_toolbar_set_icon_size ( (GtkToolbar *)toolbar , GTK_ICON_SIZE_SMALL_TOOLBAR ) ;
   gtk_toolbar_set_style ( (GtkToolbar *)toolbar , GTK_TOOLBAR_ICONS ) ;

   GtkToolItem * gtkimg = gtk_tool_button_new_from_stock ( GTK_STOCK_CUT ) ;
   gtk_toolbar_insert( GTK_TOOLBAR(toolbar) , gtkimg , -1 ) ;

   gtkimg = gtk_tool_button_new_from_stock ( GTK_STOCK_COPY ) ;
   gtk_toolbar_insert( GTK_TOOLBAR(toolbar) , gtkimg , -1 ) ;

   gtkimg = gtk_tool_button_new_from_stock ( GTK_STOCK_PASTE ) ;
   gtk_toolbar_insert( GTK_TOOLBAR(toolbar) , gtkimg , -1 ) ;

   gtk_box_pack_start (GTK_BOX (box), toolbar, FALSE,FALSE,4 ) ;
   gtk_box_pack_start_defaults (GTK_BOX (box), n_box ) ;

   gtk_container_add (GTK_CONTAINER (window), box);

   gtk_widget_show_all (window);
   gtk_main ();

return 0;

}
