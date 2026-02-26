# Installation Instructions

Copyright (C) 1994-1996, 1999-2002, 2004-2017, 2020-2021 Free Software Foundation, Inc.
Copyright (C) 2024 Carlo Baldassi

Copying and distribution of this file, with or without modification, are permitted in any medium without royalty provided the copyright notice and this notice are preserved. This file is offered as-is, without warranty of any kind.

## Basic Installation

Briefly, the following commands should configure, build, and install this package:

```bash
meson setup build
meson compile -C build
meson install -C build
```

The following more-detailed instructions are generic; see the [README.md](README.md) file for instructions specific to this package.

The `meson setup` command attempts to guess correct values for various system-dependent variables used during compilation. It uses those values to create a build directory (e.g. `build`) with the necessary files for building the project.

If you need to do unusual things to compile the package, please try to figure out how to do them with meson options, and mail diffs or instructions to the address given in the [README.md](README.md).

The simplest way to compile this package is:

1. `cd` to the directory containing the package's source code and type `meson setup build` to configure the package for your system.
   
   Running `meson setup` might take a while. While running, it prints some messages telling which features it is checking for.

2. Type `meson compile -C build` to compile the package.

3. Optionally, type `meson test -C build` to run any self-tests that come with the package.

4. Type `meson install -C build` to install the programs and any data files and documentation. When installing into a prefix owned by root, it is recommended that the package be configured and built as a regular user, and only the `meson install` phase executed with root privileges (e.g. `sudo meson install -C build`).

5. You can remove the program binaries and object files from the build directory by removing the build directory itself (`rm -rf build`).

## Compilers and Options

Some systems require unusual options for compilation or linking that the meson setup script does not know about. Run `meson configure` in your build directory for details on the pertinent variables.

You can give `meson setup` initial values for configuration parameters by passing options like `-Doption=value` on the command line.

## Installation Names

By default, `meson install` installs the package's commands under `/usr/local/bin`, include files under `/usr/local/include`, etc. You can specify an installation prefix other than `/usr/local` by giving `meson setup` the option `--prefix=PREFIX`, where PREFIX must be an absolute file name.

In addition, you can give options like `-Dbindir=DIR` to specify different values for particular kinds of files. Run `meson configure` in your build directory for a list of the directories you can set and what kinds of files go in them.

The most portable way to affect installation locations is to pass the correct locations to `meson setup`.

For this specific plugin, you can also use:
- `-Dgimp_plugindir=DIR`: Override plugin installation directory
- `-Dgimp_plugin_datadir=DIR`: Override plugin data installation directory

## Optional Features

Some packages pay attention to `-Dfeature=enabled/disabled` options to `meson setup`, where feature indicates an optional part of the package. The [README.md](README.md) should mention any such options that the package recognizes. Check `meson_options.txt` for available options.
