/* pidginTeX.h 
 * Copyright 2008 Mikael Öhman
 * Initially based on the pidgin-latex plugin
 *
 * This file is part of pidginTeX.
 *
 * pidginTeX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * pidginTeX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with pidginTeX. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PIDGINTEX_H
#define PIDGINTEX_H

#include <glib/gstdio.h>
#include <string.h>
#include <purple.h>
#include <gtkplugin.h>
#include <gtkconv.h>
#include <gtkimhtml.h>

#ifdef ENABLE_NLS
# include <locale.h>
# include <libintl.h>
# define _(String) dgettext(PLUGIN_NAME, String)
# define LOCALEDIR "locale"
#else
# define _(String) (String)
#endif

#ifdef G_OS_WIN32
# include <windows.h>
# define WEXITSTATUS(S) (S)
# define __GNUC_PREREQ(a,b) 0
# define g_file_get_contents g_file_get_contents_utf8
#else
# include <sys/wait.h>
#endif

// It's actually not a core plugin, but it's kept like this for historical reasons.
// (in order to keep old settings from when pidgintex was a core plugin)
// Changing it is no big deal, but users might complain. Your call.
#define PREFS_BASE       "/plugins/core/" PLUGIN_NAME
#define PREFS_SENDIMAGE  (PREFS_BASE "/sendimage")
#define PREFS_PREPEND    (PREFS_BASE "/prepend")
#define PREFS_RENDERER   (PREFS_BASE "/renderer")
#define PREFS_PRINTEXPR  (PREFS_BASE "/printexpr")
#define PREFS_NEGATE     (PREFS_BASE "/negate")
#define PREFS_SMASH      (PREFS_BASE "/smash")
#define PREFS_STYLE      (PREFS_BASE "/style")
#define PREFS_FONT_SIZE  (PREFS_BASE "/fontsize")
#define PREFS_FONT_COLOR (PREFS_BASE "/fontcolor")
#define TEX_DELIMITER    "$$"

/* font sizes for mathTeX */
static char* mathfont[] = {"tiny","footnotesize","normalsize","large",
                 "Large","LARGE","huge","Huge"};

/* variables for callback functions */
static gboolean modoff;
static gchar *originalmsg;
static gchar *modifiedmsg;
static GList *imageref;

/* to intercept signals */
static void message_send(PurpleAccount *account, gchar *recipient, gchar **message);
static void deleting_conv(PurpleConversation *conv);
static void history_write(PurpleConversation *c);
static gboolean displaying_msg(PurpleAccount *account, const char *who,
    char **message, PurpleConversation *conv, PurpleMessageFlags flags);

/** 
  * latex_to_image creates an image from a LaTeX expression.
  * Image must be deleted and string must be freed by caller
  * @param[in] latex Latex expression to be rendered.
  * @param[out] filedata Image data as any format supported by libpurple.
  * @param[out] size Size of image data in bytes.
  * @return TRUE on success, false otherwise
  */
static gboolean latex_to_image(gchar *latex, gchar **filedata, gsize* size);

/**
  * Transform LaTeX parts of message into <img="number">.
  * @param[in] msg Original message.
  * @param[out] outmsg Newly allocated nesssage with images if successfull, otherwise untouched.
  * @return TRUE on success, FALSE otherwise
  */
static gboolean analyse(const gchar *msg, gchar **outmsg);

#endif
