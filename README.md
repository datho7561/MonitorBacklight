# MonitorBacklight

A simple `ncurses` based program that can be run in your terminal emulator in
order to use your monitor as a backlight.

## Building

These steps have only been tested under Fedora Linux
 * Install the `ncurses` library development files, `gcc`, and `make`
 * Run `make` in the project directory
 * The binary executable `MonitorBacklight` is generated

## Using

Requires a terminal emulator with 256 colour support.

There are no command line arguments as of now.

Use the vim keys (`h`, `j` ,`k`, `l`) in order to select 1 of the 16 available
colours in a 4x4 grid.
The colours range from red to orange with different brightness levels.
Horizontal movement changes hue, vertical changes brightness (roughly).
