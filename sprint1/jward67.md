# PaintApp - jward67

## What I planned to do for Sprint 1:
- Create a brush tool {issue #5}
  - When button is clicked, the user is able to draw or create strokes with cursor
- Brush Tool: Class Brush - Color Value {issue #15}
  - Make it so we can use different colors at once when using brush tool (may be too advanced...).
- Implement zoom-in/zoom-out menu buttons that allow user to zoom in on some segment of an image. {issue #16}

## What I did not do:
- Implement following tools and menu buttons:
  - Multi-brush feature {issue #15}
    - It would appear that a multi-brush feature would be too advanced for someone like me to handle, especially since the UI will mostly be done via coding (and not the built-in ui developer tools).  
  - Zoom-in/Zoom-out functionality {issue #16}
    - I was unable to actually do some coding for the zoom-in/out buttons due to the compiler throwing out "no such slot" errors. More about that in next segment.

## Problems that I encountered during production:
- Installing Qt-Library and X code onto personal computers
- Accessing PaintApp repo via git bash on personal terminal.
  - skyla had to help me get my git bash set up so that I could access the PaintApp repo via a personal github token.
- Compiling new additional Qt SLOTS in moc_misc_paint.cpp file
  - Despite following the procedures to creating new slots and functions for the PaintApp, Qt Creator refused to acknowledge that the new slots for functions like zoomIn/Out, undo, & redo existed in the header file. This tremendously hindered our progress in developing edit buttons and GUI for PaintApp.

## What I've accomplished in Sprint 1:
- Created a canvas every time the program runs.
  - Made it so that we create new projects and/or open existing .bmp/.png files (we can save some canvas in any format we choose). {issue #8, #9, #12}
  - Made a brush that allows user to change the color and width of the brush/pen. {issue #5, #7}
- Files that I've worked on (mostly all within paint_app_tut dierectory):
  - misc_paint.h
  - scribblearea.h
  - main.cpp
  - misc_paint.cpp
  - scribblearea.cpp
- Note: I have done most of the work for the group while they were getting used to the Qt set-up. All of the group's progress was made possible thanks to Derek Banas' tutorial video: [Qt Tutorial 4: C++ Paint App](https://www.youtube.com/watch?v=uzgU2XzhnHY)
