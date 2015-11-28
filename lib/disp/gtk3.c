#include <gtk/gtk.h>
#include <gtkmm.h>
#include <glib.h>
#include <cstring>
#include <cstdlib>

//#include "cv.h"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>

using namespace std;
using namespace cv;

GtkWidget *window, *image;
GtkWidget *vbox, *valign, *hbox, *halign;
GtkWidget *expression_label;

char* get_file()
{
    GtkWidget *dialog = gtk_file_chooser_dialog_new("Open File", (GtkWindow *) window, GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);

    if(gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        char *filename;

        filename = gtk_file_chooser_get_filename( GTK_FILE_CHOOSER(dialog) );
        gtk_widget_destroy(dialog);

        return filename;
    }

}

void load_file(GtkWidget *widget, gpointer data)
{
    g_print("Loading file\n");
    char *file = get_file();

    Mat img = imread(file);
    //imshow("Opencv image", img);

    image = gtk_image_new_from_file(file);

    gtk_widget_queue_draw(image);
    //  gtk_box_pack_start(GTK_BOX(vbox), image, FALSE, FALSE, 0);

    gtk_label_set_text(GTK_LABEL(expression_label), "Image Loaded");    
g_print("File Loaded\n");
g_print("%s\n", file);

}


void get_expression(GtkWidget *widget, gpointer data)
{
    gtk_label_set_text(GTK_LABEL(expression_label), "Expression Detected"); 
}   


int main(int argc, char* argv[])
{

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "FEAR");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 1100, 1100);
    gtk_window_set_resizable(GTK_WINDOW(window), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    vbox = gtk_vbox_new(FALSE, 5);

    hbox = gtk_hbox_new(TRUE, 3);

    GtkWidget *load_button = gtk_button_new_with_label("Load");
    GtkWidget *run_button = gtk_button_new_with_label("Run");
    gtk_widget_set_size_request(load_button, 70, 30);
    gtk_widget_set_size_request(run_button, 70, 30);

    gtk_container_add(GTK_CONTAINER(hbox), load_button);
    gtk_container_add(GTK_CONTAINER(hbox), run_button);

    expression_label = gtk_label_new("Expression");

    //image = gtk_image_new();

    //Display placeholder image    
    image = gtk_image_new_from_file("../sample.jpg");

    gtk_box_pack_start(GTK_BOX(vbox), image, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), expression_label, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(window), vbox);

    int load_handler_id = g_signal_connect(G_OBJECT(load_button), "clicked", G_CALLBACK(load_file), NULL);

    g_signal_connect(G_OBJECT(run_button), "clicked", G_CALLBACK(get_expression), NULL);


    g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();


    return 0;
}
