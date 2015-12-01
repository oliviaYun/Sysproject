Many people start an application from an absolutely minimal "hello, world" template. I know that some GTK+ developers have been using the simple.c example included in the Gimp distribution, but that example has several problems.

Without further ado, here's helloworld.c:

#include <gtk/gtk.h>

void
hello (void)
{
  g_print ("Hello World\n");
}

void
destroy (void)
{
  gtk_main_quit ();
}

int
main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *button;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_signal_connect (GTK_OBJECT (window), "destroy",
		      GTK_SIGNAL_FUNC (destroy), NULL);
  gtk_container_border_width (GTK_CONTAINER (window), 10);

  button = gtk_button_new_with_label ("Hello World");

  gtk_signal_connect (GTK_OBJECT (button), "clicked",
		      GTK_SIGNAL_FUNC (hello), NULL);
  gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
			     GTK_SIGNAL_FUNC (gtk_widget_destroy),
			     GTK_OBJECT (window));
  gtk_container_add (GTK_CONTAINER (window), button);
  gtk_widget_show (button);

  gtk_widget_show (window);

  gtk_main ();

  return 0;
}
Here's the Makefile you'll need to build it:

GTK_INCLUDE = -I/usr/local/include
GTK_LIB = -L/usr/local/lib
X11_LIB = -L/usr/X11R6/lib
CC = gcc -g -Wall
CFLAGS = $(GTK_INCLUDE)
LDFLAGS = $(GTK_LIB) $(X11_LIB) -lgtk -lgdk -lglib -lX11 -lXext -lm

OBJS = helloworld.o

helloworld:	$(OBJS)
#	$(CC) $(GTK_LIB) $(X11_LIB) $(OBJS) -o helloworld $(LDFLAGS)

clean:
	rm -f *.o *~ helloworld
