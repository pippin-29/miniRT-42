# change-logs

## Versions

* X.00 (X changes on massive change)
* 0.xx (X changes on incremental change)

## 0.00

* Parser Is functional, and will fit the needs of the program to be designed.
* General Structure of program devised, with structs and struct arrays created for RT\_objects(camera, light, ambient) and scene\_objects(cylinders, spheres, planes)
* Makefile designed to create individual object files, and then links all program objects and library archives.
  * libs can be remade with `make libs` (I switch architecture between school/home).
  * objects are contained in separate folder, and are not recompiled.

## 1.00

* Set up functions to free memory allocations.
* Fixed Initialisation problems, which wouldn't allow memory free on exit.
* Allocates objects on a first run of file read.
* Parses on second run.

## 1.01

* types changed to a standardised format
* window creation
* header files rename, inclusion of miniRT\_draw.h and miniRT\_math.h
* Makefile altered to automate set of test scenes

## 1.02

* source now contains directories for respective headers
* makefile changed to suit
