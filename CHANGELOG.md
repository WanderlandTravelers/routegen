1.7.1 (2016-03-05)
==================

- FFmpeg for Windows is now distributed with the Windows version of Route Generator and will be selected as the default at installation. The Zeranoe FFmpeg Windows builds are provided by Kyle Schwarz from: http://ffmpeg.zeranoe.com/builds/ NOTE: To safe space the executables ffplay.exe and ffprobe.exe are removed from the distribution.


1.7 (2015-02-02)
================
- Using ffmpeg codec on Windows
- URL format of new version of google maps now supported
- Line width and style saved again
- Option to add N seconds still frame before/after movie


1.6 (2012-04-28)
================

- Route editable (selected points can be moved or deleted)
- Redo buffer
- Codec selection for video encoding under linux 
- Installation command for linux
- Improvements of edit dialog for vehicle settings
- Vehicle orientation (yes/no) is now a setting
- Deleting files in directory when not empty (when generating movie)
- Adding custom vehicles from vehicle settings dialog


1.5 (2011-01-16)
================

- Route generation improvements (smooth route, using bezier curves)
- Start new route button on toolbar
- Vehicle orientation and settings improved
- Generate iconless begin/end frames checkbox moved to preferences dialog
- Google maps importer fix (map scrollable and zoomable)


1.4
===

- Import from Google Maps


1.3.1
=====

- Smooth curves experiment disabled (buggy) (see new RGRoute constructor)
- Added advanced tab to settings dialog to:
    - Enable the buggy smooth curves code
    - Change radius of curves
    - Modify vehicle orientation parameters
- Automatically disable draw mode, when user clicks Preview or Generate route.
- Show first route point as will after first click (interpolation mode)


1.3
===

- Route interpolation and variable route speed.
- Preferences (bmp2avi)
- Undo buffer
- Route style selection


1.2.3
=====

- Bugfix in frame naming, causing routes over 1000 frames to be added in wrong order in AVI file (during bmp2avi conversion)


1.2.2
=====

- Error checking and logging of bmp2avi execution (bmp2avi.log)


1.2.1
=====

- Bugfix in route width initialization (not released on SourceForge)


1.2
===

- Vehicle icon now rotates with route direction
- Added vehicle angle correction spinbox and preview
- Animated vehicle icons
- Showing scrollbars for large input maps
- Added stop button while playing back


1.1
===

- Added custom vehicle icons by adding icons (image files, e.g. *.png, *.jpg, etc.) to the vehicles sub-folder of routegen.
- Added custom color selection for route path.


1.0
===

- Initial version