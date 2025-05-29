#ifndef __MAIN_COMMON_H__
#define __MAIN_COMMON_H__

/*  Constants  */

#define PLUG_IN_NAME   "plug-in-lqr"

#define DATA_KEY_VALS    "plug_in_lqr"
#define DATA_KEY_UI_VALS "plug_in_lqr_ui"
#define DATA_KEY_COL_VALS "plug_in_lqr_col"
#define PARASITE_KEY     "plug_in_lqr_options"

#define VALS_MAX_NAME_LENGTH (1024)
#define MAX_STRING_SIZE   (2048)

typedef struct
{
  gint new_width;
  gint new_height;
  gint32 pres_layer_ID;
  gint pres_coeff;
  gint32 disc_layer_ID;
  gint disc_coeff;
  gfloat rigidity;
  gint32 rigmask_layer_ID;
  gint delta_x;
  gfloat enl_step;
  gboolean resize_aux_layers;
  gboolean resize_canvas;
  gint32 output_target;
  gboolean output_seams;
  gint nrg_func;
  gint res_order;
  gint mask_behavior;
  gboolean scaleback;
  gint scaleback_mode;
  gboolean no_disc_on_enlarge;
  gchar pres_layer_name[VALS_MAX_NAME_LENGTH];
  gchar disc_layer_name[VALS_MAX_NAME_LENGTH];
  gchar rigmask_layer_name[VALS_MAX_NAME_LENGTH];
  gchar selected_layer_name[VALS_MAX_NAME_LENGTH];
} PlugInVals;

/* GIMP 3.0 compatibility helpers */
static inline void
lqr_image_set_active_layer (GimpImage *image, GimpDrawable *drawable)
{
//  GimpImage *image = gimp_image_get_by_id (image_id);
//  GimpLayer *layer = gimp_layer_get_by_id (layer_id);
  if (image && drawable)
    {
      const GimpLayer **layers = g_new (const GimpLayer *, 1);
      layers[0] = drawable;
      gimp_image_set_selected_layers (image, layers);
      g_free (layers);
    }
}

#endif /* __MAIN_COMMON_H__ */
