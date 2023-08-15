#ifndef TERM_H_
#define TERM_H_

#include <gtk/gtk.h>

#define CLR_R(x)   (((x) & 0xff0000) >> 16)
#define CLR_G(x)   (((x) & 0x00ff00) >>  8)
#define CLR_B(x)   (((x) & 0x0000ff) >>  0)
#define CLR_16(x)  ((double)(x) / 0xff)
#define CLR_GDK(x) (const GdkRGBA){ .red = CLR_16(CLR_R(x)), \
	.green = CLR_16(CLR_G(x)), \
	.blue = CLR_16(CLR_B(x)), \
	.alpha = 0 }

int run_term(GtkApplication *app, int argc, char *argv[]);

#endif // TERM_H_
