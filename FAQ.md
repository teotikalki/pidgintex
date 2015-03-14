# General #
### Why doesn't sending images work? ###
_It will work on any protocol that supports sending images. It's as simple as that.
However, very few protocols support this (currently only ICQ using Direct IM mode, wich is commonly never used (see conversation menu))._

### Should I use mimeTeX or mathTeX? ###
_If you don't want to install latex and dvipng use mimeTeX.
If you have latex then install dvipng and mathTeX since it renders better images
and supports the PNG-format instead of only GIF_

### Will the person I'm talking to see the rendered expression? ###
_Yes if he/she has a similiar plugin installed or if you send the image._

### Why wouldn't I want to send the image? ###
_The person you are talking to might have another background color or have some other settings for the image that he/she prefers.
You also need to be in ICQ using Direct IM mode in order to send images inside message. Even if the protocol supports this feature many do not use IM-clients that support drawing any kind of image, making it very impossible.
You most likely do not want to select this option._

# mimeTeX #
### It's not working ###
_Check to see that mimeTeX is installed.
You should get a gif image from_
`$ mimetex "x^2" -e test.gif`
_If not, get mimetex or make sure the binary is in some directory that's included in your PATH._

### Colors aren't working ###
_You need at least a version higher than 1.50. It should work in 1.64. You can check your version by running_
`mimetex`

# mathTeX #
### It's not working ###
_Check to see that mathTeX is installed.
You should get a png image named test.png from_
`$ mathtex "\\png x^2" -o test `
_If not, get mathTeX or make sure the binary is in some directory that's included in your PATH._

More to come.