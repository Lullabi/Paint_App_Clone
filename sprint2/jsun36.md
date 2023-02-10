# Sprint 2
* Name: Jiawei L. Wu
* Github ID: leoked 
* Group Name: PaintApp

### What you planned to do
* Creating a new file window: The new file allows the user to get a clean new canvas with provided height and weight.
* Paint with second color using right-click: when the user is right-clicked the brush will paint the canvas with a second color instead of the first color(left_click)
* Finishing up the export button that will export the image in the canvas into some image file on desktop.

### What you did not do
* Most of my tasks in this sprint are complete, but there is one thing I did not get the time to do it. It is the color change action for the second color(right-click) brush.

### What problems you encountered
* When creating a new file the user needs to input two values: height and width. However, the qt's defualt input box, Qdialog, only allows one input at a time, so I had to create a widget for getting the two user inputs at once.
* When I first get the new file widget to show the "get width and height" function didn't wait for the user inputs, so I had to do some research on how to make the function wait for the user input first then execute. 

### What you accomplished
* I finished up the implementation of the export button
* I have created the ui of the get width and height widget and give them some functionality. 
  * since I didn't code that instead of using the qt designer for the ui, I did not include the winsize.ui in the commit.txt file.
* The canvas now is able to create a new file by getting the user inputs of height and width and create a height * width pixel canvas.
* I have made the second color for the brush. Normally the brush paints with one color at a time but now the brush can have two colors at the same time: one by left-clicking and one by right-clicking

### Issues you worked on
* Issues: [#8](https://github.com/utk-cs340-spring22/PaintApp/issues/8) [#15](https://github.com/utk-cs340-spring22/PaintApp/issues/15) [#18](https://github.com/utk-cs340-spring22/PaintApp/issues/18) [#20](https://github.com/utk-cs340-spring22/PaintApp/issues/20) 

### Files you worked on
* [main/paint_app_tut/misc_paint.cpp](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/misc_paint.cpp)
* [main/paint_app_tut/misc_paint.h](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/misc_paint.h)
* [main/paint_app_tut/scribblearea.cpp](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/scribblearea.cpp)
* [main/paint_app_tut/scribblearea.h](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/scribblearea.h)
* [main/paint_app_tut/winsize.cpp](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/winsize.cpp)
* [main/paint_app_tut/winsize.h](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/winsize.h)
* [main/paint_app_tut/winsize.ui](https://github.com/utk-cs340-spring22/PaintApp/blob/main/paint_app_tut/winsize.ui)
