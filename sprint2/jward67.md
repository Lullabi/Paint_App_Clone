# PaintApp - jward67

## What I planned to do for Sprint 2:
- Generate smoother brush strokes with the brush tool {[issue #19](https://github.com/utk-cs340-spring22/PaintApp/issues/19#issue-1179836315)}
  - While the brush tool does work as intended, painting in fast strokes causes the lines to become jagged when forming curves. My original plan of action was to find a way to ensure that the lines I create get updated more frequently than the default set up (down to about a milli-second or a nano-second if I can pull it off somehow).
- Implement a color picker tool {[Issue #26](https://github.com/utk-cs340-spring22/PaintApp/issues/26#issue-1188436955)}
  - Make it so we can pick a pixel that has a color on the canvas.
- Write the Top README.md and LICENSE.txt files for the PaintApp project {[issue #23](https://github.com/utk-cs340-spring22/PaintApp/issues/23#issue-1188408225)}
  - This doesn't count as committing source code for the project, but devoting myself to drafting a README.md file for this project will allow others to focus on other issues that were assigned to them. Technically, it counts as an excuse for me to contribute to the project in some way if I don't find the time to implmenet any of the above issues.

## What I did not do:
- Update lines in brush strokes to make them smoother {issue #19}
  - Due to the complexity behind the periodic updates in-between line segments and the workload in my other courses, I deemed it necessary to move this issue to my back-log for sprint 3 and work on it when I manage to finish my other issues in sprint 3. There will be a good chance that I will need to work with my group to get this issue sorted out before the next demo.

## Problems that I encountered during production:
- Pulling in new changes from group before and after stashing my changes.
  - Being able to get new changes from my group members tended to be problematic for me as we always have to deal with the fact that some of our files (namely paint_app_tut.pro.user) could be overwritten upon merging. Of course, our group realized early on that trying to push or pull any changes made in github overwrites any work that we have individually done in the past, so we made it an effort to back-up any files we work on before pulling. 
    - Note: When I try to pull from github, I save some time by removing the file that's preventing me from pulling changes. Files such as paint_app_tut.pro.user don't mean much since it's technically a build for the project, but I make sure to  create back-up files for .cpp and .h files that I have edited on before deleting them.

## What I've accomplished in Sprint 2:
- Built a color picker tool to "collect" color from pixels on canvas. {Issue #26}
  - Note: This tool has a bug that prohibits the user from picking colors on canvas after clicking on the button for said tool. To "pick" different colors off of the canvas and assign the pen to a new color, one needs to click on a particular color first and then press the "color picker" button to switch to that color. There is also a small chance of missing the color and collecting a white pixel instead. This bug shouldn't be much of an issue so long as the user gets used to the functionality, but I need to find a way to tell the program to wait until the user picks a particular pixel on the canvas AFTER pressing the button for the tool.
    - In addition to the color picker tool, I've also implemented a widget that applies whatever color you want on your brush with slider functionality. Credit goes to Miroslav Bendik for his tutorial video on how to implement a basic "color picker" slider widget: [Creating color picker in Qt Creator](https://youtu.be/mZ7wBUA04CI). While the widget does work (after following the video carefully), our group is still having trouble figuring out how to add widgets to PaintApp without covering the canvas and preventing users from drawing something. As such, I've removed it from the build in Qt creator, but it's still in the github repo should we decide to implement it somehow.
- Create a first draft for the Top README.md file for this project. {Issue #23}
  - The final draft for the README file is not finished yet as it's still missing a graphic for the application and needs to be updated on a constant basis to inform other users on what works and what doesn't. I've still yet to obtain a license for the LICENSE.txt file but I'll be sure to work on it as well as revising a few things on the README.md file at a later date.
- Files that I've worked on (details found in jward67.commits.txt):
  - paint_app_tut/colorselector.cpp
  - paint_app_tut/colorselector.h
  - paint_app_tut/colorselector.ui (doesn't count in creating source code since it's built from a ui creator in Qt, so it doesn't show up in jward67.commits.txt)
  - paint_app_tut/misc_paint.h
  - paint_app_tut/scribblearea.h
  - paint_app_tut/misc_paint.cpp
  - paint_app_tut/scribblearea.cpp

In summary, while I wasn't able to commit more useful code for this sprint due to classwork and other factors outside this course, I can say that I made some progress and contributed a little to the project if not a lot. I intend to finish the rest of the license and README files in Sprint 3 as well as work on implementing a feature where the user can choose a default color upon creating a new file. If all goes well I plan on commiting more code in the next sprint.
