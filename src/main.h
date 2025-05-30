
#ifndef __MAIN_H__
#define __MAIN_H__

#include "main_common.h"


/*  Local function prototypes  */

static gint32 layer_from_name(gint32 image_ID, gchar *name);

static void set_aux_layer_name(GimpLayer *layer, gboolean status, gchar *name);

static void save_vals(void);

static void retrieve_vals(void);

static void retrieve_vals_use_aux_layers_names(gint32 image_ID);

static void noninteractive_read_vals(GimpProcedureConfig *config, GimpImage *image);

static void install_custom_signals();

static void cancel_work_on_aux_layer(void);

#if defined(G_OS_WIN32)
static gchar * get_gimp_share_directory_on_windows();
#endif

static GimpProcedure *create_procedure(GimpPlugIn *plug_in,
                                       const gchar *name);

static GimpValueArray *lqr_run(GimpProcedure *procedure,
                               GimpRunMode run_mode,
                               GimpImage *image,
//                                  gint                  n_drawables,
                               GimpDrawable **drawables,
                               GimpProcedureConfig *config,
                               gpointer run_data);



/* Additional responses for dialog */

#define RESPONSE_REFRESH (1)
#define RESPONSE_FEAT_REFRESH (2)
#define RESPONSE_ADV_REFRESH (3)
#define RESPONSE_RESET (4)
#define RESPONSE_WORK_ON_AUX_LAYER (5)
#define RESPONSE_INTERACTIVE (6)
#define RESPONSE_NONINTERACTIVE (7)
#define RESPONSE_FATAL (8)
#define STD_SET_I18N set_i18n

typedef enum {
    AUX_LAYER_PRES,
    AUX_LAYER_DISC,
    AUX_LAYER_RIGMASK,
} AuxLayerType;

/* Structs for parameters */

typedef struct {
    gint32 image_ID;
} PlugInImageVals;

typedef struct {
    gint32 layer_ID;
} PlugInDrawableVals;

typedef struct {
    gboolean chain_active;
    gboolean pres_status;
    gboolean disc_status;
    gboolean rigmask_status;
    gint last_used_width;
    gint last_used_height;
    gint32 last_layer_ID;
    gboolean seams_control_expanded;
    gboolean operations_expanded;
    gboolean dlg_has_pos;
    gint dlg_x;
    gint dlg_y;
    gint32 layer_on_edit_ID;
    AuxLayerType layer_on_edit_type;
    gboolean layer_on_edit_is_new;
} PlugInUIVals;

#define PLUGIN_UI_VALS(data) ((PlugInUIVals*)data)

typedef struct {
    gdouble r1;
    gdouble g1;
    gdouble b1;
    gdouble r2;
    gdouble g2;
    gdouble b2;
} PlugInColVals;

typedef struct {
    gboolean has_pos;
    gint x;
    gint y;
} PlugInDialogVals;

#define PLUGIN_DIALOG_VALS(data) ((PlugInDialogVals*)data)


/* Output target */

enum _OutputTarget {
    OUTPUT_TARGET_SAME_LAYER,
    OUTPUT_TARGET_NEW_LAYER,
    OUTPUT_TARGET_NEW_IMAGE
};

typedef enum _OutputTarget OutputTarget;


/* Scaleback modes */

enum _ScalebackMode {
    SCALEBACK_MODE_LQRBACK,
    SCALEBACK_MODE_STD,
    SCALEBACK_MODE_STDW,
    SCALEBACK_MODE_STDH
};

typedef enum _ScalebackMode ScalebackMode;


/*  Default values  */

extern const PlugInVals default_vals;
extern const PlugInUIVals default_ui_vals;
extern const PlugInColVals default_col_vals;


/* Convenience macros for checking */

#define IMAGE_CHECK_ACTION(image_ID, action, ret_val) G_STMT_START { \
  if (!gimp_image_is_valid_id (image_ID)) \
    { \
      g_message (_("Error: invalid image")); \
      action; \
      return ret_val; \
    } \
  } G_STMT_END

#define IMAGE_CHECK(image_ID, ret_val) IMAGE_CHECK_ACTION (image_ID, , ret_val)

#define LAYER_CHECK_ACTION(layer_ID, action, ret_val) G_STMT_START { \
  if (!gimp_drawable_is_valid_id(layer_ID)) \
    { \
      g_message (_("Error: invalid layer")); \
      action; \
      return ret_val; \
    } \
  } G_STMT_END

#define LAYER_CHECK(layer_ID, ret_val) LAYER_CHECK_ACTION (layer_ID, , ret_val)

#define LAYER_CHECK0(layer_ID, ret_val) if (layer_ID) LAYER_CHECK (layer_ID, ret_val)

#define AUX_LAYER_STATUS(layer_ID, status) G_STMT_START { \
  if ((layer_ID == -1) || (status == FALSE)) \
    { \
      layer_ID = 0; \
    } \
  } G_STMT_END

#endif /* __MAIN_H__ */
