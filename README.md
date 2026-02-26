# GIMP LiquidRescale Plug-In

Copyright (C) 2007-2026 Carlo Baldassi <carlobaldassi@gmail.com>  
(implementation based on the GIMP Plug-in Template by Michael Natterer)

This package is a plug-in for GIMP 3.0 or newer. It is a frontend to the LiquidRescale Library (liblqr) which implements the algorithm described in the paper "Seam Carving for Content-Aware Image Resizing" by Shai Avidan and Ariel Shamir, which can be found at <https://faculty.idc.ac.il/arik/SCWeb/imret/imret.pdf>

## Installation

See the file [INSTALL.md](INSTALL.md) for detailed installation instructions. Briefly, use the following commands:

```bash
meson setup build
meson compile -C build
meson install -C build
```

Happy GIMPing,  
--Carlo
