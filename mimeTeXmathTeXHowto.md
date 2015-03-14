It is highly recommended to use the any version of mimeTeX or mathTeX you might find in your Linux systems package manager.

# mimeTeX #
mimeTeX might be in some repositories, but that might be an old version (usually 1.50).
In order to use colors and some other things you need 1.64.

Make sure the binary is named mimetex and that it's placed in some directory included in your path.
  * Download mimetex.zip from www.forkosh.com
  * Unzip into a folder (warning for zip-bomb)
  * Compile with cc -DAA -DGIF -lm mimetex.c gifsave.c -o mimetex
  * Move mimetex to folder within PATH.

For a global installation of mimetex in Linux you can do the following sequence as root:
```
mkdir tempdir
cd tempdir
wget http://www.forkosh.com/mimetex.zip
unzip mimetex.zip
cc -DAA -DGIF -lm mimetex.c gifsave.c -o /usr/local/bin/mimetex
cd ..
rm -r tempdir
```

# mathTeX #
Make sure the binary is named mathtex and that it's placed in some directory included in your path.
  * Download mathtex.zip from www.forkosh.com
  * Unzip into a folder (warning for zip-bomb)
  * Compile with dvipng (strongly recommended) or
  * Compile with dvips and convert (see below for more detail)
  * Move mathtex to folder within PATH.


For a global installation of mathtex in Linux you can do the follow sequence as root, using dvipng (make sure you have latex and dvipng installed):
```
mkdir tempdir
cd tempdir
wget http://www.forkosh.com/mathtex.zip
unzip mathtex.zip
cc -DLATEX=\"`which latex`\" -DDVIPNG=\"`which dvipng`\" mathtex.c -o /usr/local/bin/mathtex
cd ..
rm -r tempdir
```

The following will not produce pictures with an alpha channel, they will be antialiased to a white background with #FFFFFF as transparent.

For a global installation of mathtex in Linux you can do the follow sequence as root, using dvips and convert (make sure you latex and ImageMagick installed):
```
mkdir tempdir
cd tempdir
wget http://www.forkosh.com/mathtex.zip
unzip mathtex.zip
cc -DLATEX=\"`which latex`\" -DDVIPS=\"`which dvips`\" -DCONVERT=\"`which convert`\" mathtex.c -o /usr/local/bin/mathtex
cd ..
rm -r tempdir
```