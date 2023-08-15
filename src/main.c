#include <stdio.h>
#include <gtk/gtk.h>
#include <vte/vte.h>

#define CLR_R(x)   (((x) & 0xff0000) >> 16)
#define CLR_G(x)   (((x) & 0x00ff00) >>  8)
#define CLR_B(x)   (((x) & 0x0000ff) >>  0)
#define CLR_16(x)  ((double)(x) / 0xff)
#define CLR_GDK(x) (const GdkRGBA){ .red = CLR_16(CLR_R(x)), \
	.green = CLR_16(CLR_G(x)), \
	.blue = CLR_16(CLR_B(x)), \
	.alpha = 0 }

static void child_ready(VteTerminal *terminal, GPid pid, GError *error, gpointer user_data)
{
	if (!terminal) {
		return;
	}
	if (pid == -1) {
	exit(1);
	}
}

static void activate(GtkApplication *app, gpointer udata)
{
	// gtk_init();

	// Set up Gtk window
	GtkWidget *term = vte_terminal_new();
	GtkWidget *win = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(win), "it's terminal");
	gtk_window_set_default_size(GTK_WINDOW(win), 800, 400);

	// Set up terminal
	gchar **envp = g_get_environ();
	gchar **cmd = (gchar *[]){
		g_strdup(g_environ_getenv(envp, "SHELL")),
		NULL
	};
	g_strfreev(envp);
	vte_terminal_spawn_async(
		VTE_TERMINAL(term),
		VTE_PTY_DEFAULT,
		NULL,         // Working directory
		cmd,          // Command to run i.e. current shell
		NULL,         // Environment
		0,            // Spawn flags
		NULL, NULL,   // Child setup
		NULL,         // Child pid
		-1,           // Timeout
		NULL,         // Cancellable
		child_ready,  // Callback
		NULL          // user_data
	);

	// Set terminal colors
	vte_terminal_set_colors(VTE_TERMINAL(term),
						 &CLR_GDK(0xffffff),
						 &(GdkRGBA){ .alpha = 0.85 },
						 (const GdkRGBA[]){
						 CLR_GDK(0x111111),
						 CLR_GDK(0xd36265),
						 CLR_GDK(0xaece91),
						 CLR_GDK(0xe7e18c),
						 CLR_GDK(0x5297cf),
						 CLR_GDK(0x963c59),
						 CLR_GDK(0x5E7175),
						 CLR_GDK(0xbebebe),
						 CLR_GDK(0x666666),
						 CLR_GDK(0xef8171),
						 CLR_GDK(0xcfefb3),
						 CLR_GDK(0xfff796),
						 CLR_GDK(0x74b8ef),
						 CLR_GDK(0xb85e7b),
						 CLR_GDK(0xA3BABF),
						 CLR_GDK(0xffffff)
						 }, 16);

	// Add term to the win and show the win
	gtk_window_set_child(GTK_WINDOW(win), term);
	gtk_widget_set_visible(win, true);
}

int main(int argc, char *argv[])
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("rs.dxt.super", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}

