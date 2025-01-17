// SPDX-FileCopyrightText: 2021 Stiliyan Varbanov <https://www.fiverr.com/stilvar>
// SPDX-FileCopyrightText: 2022 Geoffrey D. Bennett <g@b4.vu>
// SPDX-License-Identifier: LGPL-3.0-or-later

/*
 * A Dial widget for GTK-4 similar to GtkScale.
 * 2021 Stiliyan Varbanov www.fiverr.com/stilvar
 */

#ifndef __GTK_DIAL_H__
#define __GTK_DIAL_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GTK_TYPE_DIAL            (gtk_dial_get_type ())
#define GTK_DIAL(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_DIAL, GtkDial))
#define GTK_DIAL_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_DIAL, GtkDialClass))
#define GTK_IS_DIAL(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_DIAL))
#define GTK_IS_DIAL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_DIAL))
#define GTK_DIAL_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_DIAL, GtkDialClass))

typedef struct _GtkDial              GtkDial;
typedef struct _GtkDialClass         GtkDialClass;

struct _GtkDialClass
{
  GtkWidgetClass parent_class;

  void (* value_changed)    (GtkDial     *dial);

  /* action signals for keybindings */
  void (* move_slider)      (GtkDial     *dial,
                             GtkScrollType scroll);

  gboolean (*change_value) (GtkDial     *dial,
                             GtkScrollType scroll,
                             double        new_value);
};

typedef char * (*GtkDialFormatValueFunc) (GtkDial *dial,
                                           double    value,
                                           gpointer  user_data);

GDK_AVAILABLE_IN_ALL
GType             gtk_dial_get_type           (void) G_GNUC_CONST;
GDK_AVAILABLE_IN_ALL
GtkWidget       * gtk_dial_new                (GtkAdjustment   *adjustment);
GDK_AVAILABLE_IN_ALL
GtkWidget       * gtk_dial_new_with_range     (double           min,
                                                double           max,
                                                double           step);
GDK_AVAILABLE_IN_ALL
void              gtk_dial_set_has_origin     (GtkDial        *dial,
                                                gboolean         has_origin);
GDK_AVAILABLE_IN_ALL
gboolean          gtk_dial_get_has_origin     (GtkDial        *dial);

GDK_AVAILABLE_IN_ALL
void              gtk_dial_set_adjustment     (GtkDial        *dial,
                                               GtkAdjustment  *adj);

GDK_AVAILABLE_IN_ALL
GtkAdjustment*    gtk_dial_get_adjustment     (GtkDial        *dial);

GDK_AVAILABLE_IN_ALL
double            gtk_dial_get_value             (GtkDial      *dial);

GDK_AVAILABLE_IN_ALL
void            gtk_dial_set_value             (GtkDial      *dial,
                                                  double        value);
GDK_AVAILABLE_IN_ALL
void               gtk_dial_set_round_digits              (GtkDial      *dial,
                                                            int            round_digits);
GDK_AVAILABLE_IN_ALL
int                 gtk_dial_get_round_digits              (GtkDial      *range);
GDK_AVAILABLE_IN_ALL
void               gtk_dial_set_zero_db              (GtkDial      *dial,
                                                            double         zero_db);
GDK_AVAILABLE_IN_ALL
double              gtk_dial_get_zero_db              (GtkDial      *range);

/**
 * @brief Set the colors which this dial uses. String codes can be one of the following:
 *     A standard name (Taken from the X11 rgb.txt file)
 *     A hexadecimal value in the form “#rgb”, “#rrggbb”, “#rrrgggbbb” or ”#rrrrggggbbbb”
 *     A RGB color in the form “rgb(r,g,b)” (In this case the color will have full opacity)
 *     A RGBA color in the form “rgba(r,g,b,a)”
 *     NULL if the color is to remain unchanged
 *
 * @param dial: The dial
 * @param trough_border: String code for trough border color
 * @param trough_bg: String code for trough background color
 * @param trough_fill: String code for trough fill color
 * @return TRUE if all the colors were set successfully, FALSE otherwise
 */
gboolean gtk_dial_set_style(GtkDial *dial,
                        const char *trough_border,
                        const char *trough_bg,
                        const char *trough_fill,
                        const char *pointer);
G_END_DECLS

#endif
