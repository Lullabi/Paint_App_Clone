# PaintApp - ahervey

## What I planned to do for Sprint 1:
- I originally planned to finish my undo/redo buttons that I had leftover from Sprint 1. I didn't finish them because I didn't know how to. When Sprint 2 came around, I managed to find a method to get them working. Due to time constraints and other work, those were the only issues I managed to finish.

## What I did not do:
- After finishing the undo/redo, I was assigned two more issues: the text box and updating the brush tool properties (Issues 21/25). I worked on getting the implemented, but had trouble doing so. I couldnot figure out how to get the text bos working properly and did not have time to move on to the brush tool properties. So, those two issues remain to be done for Sprint 3

## Problems that I encountered during production:
- Due to using a stack and not understanding the canvas fully, it was hard to get undo and redo wokring as the previous iterations of the image would be pushed multiple times or not when I wanted them to. It created a lot of trouble in trying to figure out how to get it working which made my code a bit confusing and hard to understand. Redo was the same, and trying to get it to work with undo. I think I managed to get it to work for the most part. It is not undoing/redoing properly in most cases. I beliebe the only cavaet is when someone erases the canvas totally. I do not think I added code to push/add them to the stacks I used. However, it is mostly functional and as such, only minor changes will be required to polish it. I also had trouble with the canvas being completely removed when someone would undo when no changes were pushed onto the stack. However that was an easy fix.

## What I've accomplished in Sprint 1:
- Undo/Redo (Issue #10/11)
- Understanding QStack and QImage
- Connecting the buttons to the functions 
