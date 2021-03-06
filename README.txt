This is Route Generator version 1.7.1

Route Generator can be used to generate route maps to be used in video editing
software.

Copyright (C) 2008-2016 Michiel Jansen.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

LICENSE
Route Generator is developed using the GPL version of Qt 4.7.3
(Copyright (C)) 2008-2010 Nokia Corporation), which can be
downloaded from: http://qt.nokia.com/downloads

This means that Route Generator should also be distributed as GPL software and
can be used for free. As a result the source code of Route Generator is also
available on http://sourceforge.net/projects/routegen.

For more details about GPL see the LICENSE file

VERSION HISTORY
1.0   -Initial version
1.1   -Added custom vehicle icons by adding icons (image files, e.g. *.png,
       *.jpg, etc.) to the vehicles sub-folder of routegen.
      -Added custom color selection for route path.
1.2   -Vehicle icon now rotates with route direction
      -Added vehicle angle correction spinbox and preview
      -Animated vehicle icons
      -Showing scrollbars for large input maps
      -Added stop button while playing back
1.2.1 -Bugfix in route width initialization (not released on SourceForge)
1.2.2 -Error checking and logging of bmp2avi execution (bmp2avi.log)
1.2.3 -Bugfix in frame naming, causing routes over 1000 frames to be added
       in wrong order in AVI file (during bmp2avi conversion)
1.3   -Route interpolation and variable route speed.
      -Preferences (bmp2avi)
      -Undo buffer
      -Route style selection
1.3.1 -Smooth curves experiment disabled (buggy) (see new RGRoute constructor)
      -Added advanced tab to settings dialog to:
        -Enable the buggy smooth curves code
        -Change radius of curves
        -Modify vehicle orientation parameters
      -Automatically disable draw mode, when user clicks Preview or
       Generate route.
      -Show first route point as will after first click (interpolation mode)
1.4   -Import from Google Maps
1.5   -Route generation improvements (smooth route, using bezier curves)
      -Start new route button on toolbar
      -Vehicle orientation and settings improved
      -Generate iconless begin/end frames checkbox moved to preferences dialog
      -Google maps importer fix (map scrollable and zoomable)
1.6   -Route editable (selected points can be moved or deleted)
      -Redo buffer
      -Codec selection for video encoding under linux 
      -Installation command for linux
	  -Improvements of edit dialog for vehicle settings
      -Vehicle orientation (yes/no) is now a setting
      -Deleting files in directory when not empty (when generating movie)
      -Adding custom vehicles from vehicle settings dialog
1.7   -Using ffmpeg codec on Windows
      -URL format of new version of google maps now supported
      -Line width and style saved again
      -Option to add N seconds still frame before/after movie
1.7.1 -FFmpeg for Windows is now distributed with the Windows version of
         Route Generator and will be selected as the default at installation.
         The Zeranoe FFmpeg Windows builds are provided by Kyle Schwarz from:
		 http://ffmpeg.zeranoe.com/builds/
		 NOTE: To safe space the executables ffplay.exe and ffprobe.exe are
		            removed from the distribution.
	  
	  
INSTALLATION
On Windows, you don't need to install it, you can just unzip everything in a directory of
your choice. After that you can execute routegen.exe or create a shortcut to it
from your desktop.

HOWTO USE ROUTE GENERATOR?
Route Generator is very easy to use, but you can find a step-by-step Tutorial
from the Help menu.

Essentially this is all the information you should need to run
Route Generator. However, you're allowed to continue reading ;-)

WHAT IS ROUTE GENERATOR
Route Generator is a tool to draw routes on a map and generate a movie from it.
This movie can be imported in your video editing software, so you can add it to
your own movies.
I started developing this as a hobby project, because I could not find any
free route generation software available. I've already used it successfully for
a few of my own video editing projects and I think it works quite well. So I
thought that others might find it useful as well and I decided to make it
available on my website.

Route Generator is developed using the GPL version of Qt 4.7, which can be
downloaded from: http://qt.nokia.com/downloads

On Linux, Route Generator makes use of a 3rdparty tool:
FFmpeg licensed under the LGPLv2.1.
This tool is not included in the source, so you will have to install it on
your computer before running Route Generator. Make sure it is installed if you
want to be able to generate a movie.

As of version 1.7.1 FFmpeg for Windows is also distributed with Route Generator
and will be selected as the default at installation.
The Zeranoe FFmpeg Windows builds are provided by Kyle Schwarz from:
http://ffmpeg.zeranoe.com/builds

On Windows, Route Generator can also make use of a freeware 3rdparty tool:
Bmp2Avi (Copyright (C) Paul Roberts 1996 - 1998)
This tool is available in the subdirectory bmp2avi. By default Route Generator
tries to find bmp2avi.exe in that directory, so you can leave it there.
Route Generator will automatically check for bmp2avi.exe in this directory
when it starts up. If it cannot find it in the default location, it will ask
you to browse to a different location.
Bmp2Avi can freely be re-distributed as long as you provide the documentation
with it (also located in the bmp2avi sub-directory).

AVAILABILTY
I've only build the executable version of Route Generator for Windows, because
I'm using Pinnacle Studio as video editing software, which is only available
for windows.
However, it's developed using Trolltechs's cross-platform GUI toolkit, Qt,
which is also available for other OS's, like Linux. So it is also possible
to build and run Route Generator on Linux as well, but you have to build it
yourself from the source code (see building instructions below).
NOTE: Route Generator makes use of a video encoder (Bmp2Avi on Windows and 
ffmpeg on linux)! However, the video encoder is not required to run Route
Generator. The only thing that will not work without the video encoder is the
last stage of the generation process:converting a list of bmp files to an avi
file.

BUILDING ROUTE GENERATOR FROM THE SOURCE CODE
Since version 1.6 Route Generator should be built using Qt 4.6 or higher. 
So Qt 4.6 or higher should be downloaded and installed. 
After your Qt build environment is setup correctly, all you need to do is:
-unzip the source code in a new directory
-open a command shell with the Qt build environment correctly set-up
-cd to the the directory where you unzipped the source code
 (e.g. cd routegen/src)
-execute the following commands:
   *qmake routegen.pro
    (or: qmake -tp vc routegen.pro to generate a MSVC2008 *.vcproj)
   
   *nmake (on Windows, when using MS Visual C++)
    OR
    make/gmake (on Linux)
    OR
    whatever build command on other OS's

INSTALLATION UNDER LINUX
Since version 1.6 Route GENERATOR can be installed after building process, 
using this command as root:
   *make install

CONTACT
If you have any more questions about or problems with using and or building
Route Generator, you can contact me at: info@routegenerator.net
Of course, suggestions for improvement are also welcome!

Michiel Jansen
