#include <gtk/gtk.h>
#include "term.h"

int main(int argc, char *argv[])
{
	GtkApplication app;

	return run_term(&app, argc, argv);
}

