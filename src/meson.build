sources = [
  'main.c',
  'interface.c',
  'interface_I.c',
  'interface_aux.c',
  'layers_combo.c',
  'render.c',
  'preview.c',
  'io_functions.c',
  'altsizeentry.c',
  'altcoordinates.c',
]

headers = [
  'main.h',
  'interface.h',
  'interface_I.h',
  'interface_aux.h',
  'layers_combo.h',
  'render.h',
  'preview.h',
  'io_functions.h',
  'altsizeentry.h',
  'altcoordinates.h',
  'compat.h',
  'main_common.h',
  'plugin-intl.h',
]

# Create the plugin executable
plugin = executable('gimp-lqr-plugin',
  sources,
  include_directories : [
    include_directories('.'),
    include_directories('..'),
  ],
  dependencies : [gimp_dep, gimpui_dep, lqr_dep],
  install : true,
  install_dir : bindir
) 