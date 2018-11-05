
Debian
====================
This directory contains files used to package eblockcoind/eblockcoin-qt
for Debian-based Linux systems. If you compile eblockcoind/eblockcoin-qt yourself, there are some useful files here.

## eblockcoin: URI support ##


eblockcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install eblockcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your eblockcoinqt binary to `/usr/bin`
and the `../../share/pixmaps/eblockcoin128.png` to `/usr/share/pixmaps`

eblockcoin-qt.protocol (KDE)

