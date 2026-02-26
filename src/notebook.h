/* GIMP LiquidRescale Plug-in
* Copyright (C) 2007-2026 Carlo Baldassi and contibutors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef GIMP_LQR_PLUGIN_NOTEBOOK_H
#define GIMP_LQR_PLUGIN_NOTEBOOK_H

#include <gtk/gtk.h>
#include <libgimp/gimp.h>
#include <libgimp/gimpui.h>

typedef struct {
    GtkWidget *notebook;
    GtkWidget *features_page;
    GtkWidget *advanced_page;
    gint features_page_ID;
    gint advanced_page_ID;
    GtkWidget *label;
    gint32 image_ID;
    gint32 layer_ID;
} NotebookData;

#define NOTEBOOK_DATA(data) ((NotebookData*)data)

#endif //GIMP_LQR_PLUGIN_NOTEBOOK_H
