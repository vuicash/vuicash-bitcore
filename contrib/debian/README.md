
Debian
====================
This directory contains files used to package vuicashd/vuicash-qt
for Debian-based Linux systems. If you compile vuicashd/vuicash-qt yourself, there are some useful files here.

## vuicash: URI support ##


vuicash-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install vuicash-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your vuicash-qt binary to `/usr/bin`
and the `../../share/pixmaps/bitcoin128.png` to `/usr/share/pixmaps`

vuicash-qt.protocol (KDE)

