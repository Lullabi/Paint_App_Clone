# PaintApp

![alt text](https://github.com/utk-cs340-spring22/PaintApp/blob/main/PaintAppLogo.png)

PaintApp is a painting tool built in Qt Creator that allows you to use different pen colors and sizes to draw whatever you want; you can even draw on any images on your computer!

Authors' note: PaintApp is a school project that is meant to teach us the basics in managing business products that are meant to solve certain problems in everyday life. In this case, our group's goal is to create an art application that is more advance than Microsoft Paint, but not too advance like Clip Studio Paint. As such, this build is more experimental than it is a final product meant to be sold on the internet.

## How to get PaintApp
For Windows users, you may copy the Demo folder to your local machine and run the standalone excutable titled 'paint_app_tut.exe.' As of now, the only way to run PaintApp on your Mac is to download QT Creator off the web and use it to execute the build. To install Qt, click on the following link, go to their download page, and follow the steps to download the version that says "downloads for open source users". 
- [Qt Creator](https://www.qt.io/product/development-tools)

Note: it is important that you choose one Qt component under the Qt subfolder when installing (ex: when you need to "Select Components" for your Qt Creator application, go into "Qt" and select the lastest version available (i.e., 6.2.4). Be sure that your choices are set to default before choosing the latest version of Qt). 

**More info regarding how to install PainApp will be given at a later date**

To run the application, go to Qt to open a project, navigate to the PaintApp folder, open the paint_app_tut subfolder, and click on paint_app_tut.user.pro to build the application. After everything finishes building upon initialization, you click on the green play button in the lower left hand corner of the site to execute it.

## How to use PaintApp
Upon opening PaintApp, a canvas will immediately open for you to paint on. Simply hold left-click to start painting with color 1 (C1) and right-click to paint with color 2 (C2). Most of the basic functionality from Microsoft paint can be found in PaintApp, including (but not limited to):
- Importing/Exporting files (in toolbar/menubar of app under "File")
- Changing pen color/width (in toolbar/menubar of app under "Options")
- Printing images (if you're connected to a printer; found under "File")
- Clearing the screen (**Ctrl+l on Windows, Command+l on Mac**; found under "Options")
- Undo **(Ctrl+z)** and Redo **(Ctrl+y)** paint strokes (Found under "Edit")
- Creating lines and shapes on canvas
- Decreasing **(Ctrl+-)** and Increasing **(Ctrl+Shift+=)** the opacity of the brush (found under "Edit")
- Different types of brushes (Round & Marker)
- Eraser tool (Found under "Edit")

If you wish to change the color of the canvas, first select "New File" in the header of PaintApp; you'll find a RGB color slider for the canvas as well as the option to change the width and height of your canvas (limits as of now are 600 x 600 for the minimum and 1440 x 800 for the maximum). Altermatively you can open whatever image you have on your computer and start drawing however you like. 

### RGB Pen Color Sliders
In addition to changing the color of your brush using the color buttons on the top of the canvas, you can also use the "RGB Pen Color" sliders found in the toolbox underneath the buttons to change your selected brush to whatever color you want. 

### Tool Buttons: 
- When selecting "Line", your brush will automatically generate straight lines from one point to the next. **Press the line button again to exit line mode**
- Selecting "Shape" gives you a list of all the currently available shapes you can plaster onto the canvas.
- "Color Picker" allows you to click on whatever color is available on the canvas and assigns it to the brush, allowing you to paint with that color.
- **IMPORTANT: The "Select" button that you'll find along with the rest of the tools does not work; it is meant to experiment on how to create filled squares/rectangles. Because of this, the "Select" button is merely a placeholder.**

### Pen Types:
- Pressing C1 and C2 will allow you to switch between your left-click and right-click brush colors; this enables you to change the currently assigned brush's color whenever you want.
- "Round" and "Marker" are the only pen types that are available in PaintApp. Selecting either will change your brush to that type (Default type is Round).

There isn't a whole lot of features that come with the application but it's a solid program that follows a blueprint similar to MS Paint well. For the most part, the program is self explanatory.

### MAJOR BUGS
- There are some bugs with the undo/redo buttons which involve the memory management for shapes and brush strokes. If you were to undo/redo too much while after using the app's tools too many times, the program **WILL** crash. Proceed with extreme caution when using too many tools (shapes, lines, erase tool) at once!
- Be careful when using the shape tool: If you adjust the preview in such a way that the color does not show up, the memory of the application (brush strokes and shapes generated) gets corrupted a little and everything gets erased prematurely.

## Our Group (w/ Github repos):
- Jonathan Ward (jward67)
- Skyla (swebb37)
- Leo (leoked)
- Payton Chaz Creech (chazthecodder)
- AJ (Lullabi)

## License information
See the [LICENSE.txt](https://github.com/utk-cs340-spring22/PaintApp/blob/84c07d9f4808d717b1f08ec380e37895f506b4b3/LICENSE.txt) file for the licensing information for this project.
