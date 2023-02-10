# Sprint 3
* Name: Jiawei L. Wu
* Github ID: leoked 
* Group Name: PaintApp

### What you planned to do
* Able to set the value of the second color
* Create a spray tool as a new brush type
* Create a squiggly line tool

### What you did not do
* During this sprint I am more focus on the spray tool than the squiggly line. I did not realize how hard the spray tool could be, so in the end I did not have time left to the squiggly line, and still a little left on the spray tool.

### What problems you encountered
* The problem for this sprint is that there is not a onhold function for the mouse, so the mouse event couldn't update the image while the mouse is pressed-and-hold. I have digged throught the library and found that it might able to implement it with QTimer. 
* Overestimate the time to complete the spray tool，so I did not get a chance to start on the squiggley line. For the next sprint, I will finish up the spray tool and the squiggle line tool.

### What you accomplished
* I create a button for the first color and the second color. Once the button is pressed, the user could change the color value according to the color on the button.
* I fixed the bug in the shape tool. Now, the app will not draw an extra line while creating the shape.
* I updated the shape tool so that the shape tool could create a shape with the second color(right-click).
* I created the randompoint generator, so that the points could generate with in the circle for the spray tool. 

### Issues you worked on
* Issues: [#37](https://github.com/utk-cs340-spring22/PaintApp/issues/37) [#36](https://github.com/utk-cs340-spring22/PaintApp/issues/36) [#31](https://github.com/utk-cs340-spring22/PaintApp/issues/31) [#28](https://github.com/utk-cs340-spring22/PaintApp/issues/28) 

### Files you worked on
* [main/paint_app_tut/misc_paint.cpp](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/misc_paint.cpp)
* [main/paint_app_tut/misc_paint.h](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/misc_paint.h)
* [main/paint_app_tut/scribblearea.cpp](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/scribblearea.cpp)
* [main/paint_app_tut/scribblearea.h](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/scribblearea.h)
* [main/paint_app_tut/winsize.cpp](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/winsize.cpp)
* [main/paint_app_tut/winsize.h](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/winsize.h)
* [main/paint_app_tut/winsize.ui](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/winsize.ui)
