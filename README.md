# Readme

USAGE: ./greyifypdf pdffile cpagesfile

Recreates pdffile with a defined set of color pages. Pages not
included in this set are converted to greyscale.

The file cpagesfile is a simple file that contains the color pages
(one page number per line).

# Dependencies

* pdftk
* ghostscript
