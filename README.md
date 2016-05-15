# Readme

USAGE: ./greyifypdf pdffile cpagesfile

Recreates pdffile with a defined set of color pages. Pages not
included in this set are converted to greyscale.

The file cpagesfile is a simple file that contains the color pages
(one page number per line).

# Dependencies

* pdftk
* ghostscript
* cmake

# Installation

0. Make sure the dependencies are satisfied.
1. Clone the git repository into some directory *gitclone*.
2. Create a build directory and build the code.
```
mkdir build
cmake -DCMAKE_INSTALL_PREFIX=/opt /path/to/gitclone
make
```
3. Install the binaries (to /opt/bin/, if you followed the steps above)
```
make install
```
