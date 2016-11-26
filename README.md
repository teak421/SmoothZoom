# SmoothZoom
Smooth Zoom Plugin for Unreal Engine 4.14

This plugin provides two additional Blueprint nodes, called SmoothCameraZoom and SetNewSpringArmComponent.  Here's the low down on how to use this plugin.

- Add the Component called AC_SmoothZoom to any Actor / Pawn / Character that has a spring arm / camera attached.
- Create a float variable called ZoomUnits and give it a default value...Suggest 100 to start.
- Click on the AC_SmoothZoom component in the Components list in the top left and set the Camera Zoom values. Suggest 250.0 for Min, 1500 for Max and 9.0 for Smoothness. (But, honestly, you can do anything you want...!) There is also a debug check box that might be helpful...output will be in your log.
- Make sure that you inputs are created in project settings for ZoomIn or ZoomOut.
- From BeginPlay, add the node SetNewSpringArmComponent.  In the NewSpringArm pin attach the spring arm you would like to have the smooth zoom on.
- In the Blueprint with the AC_SmoothZoom component attached, add the necessary input actions, zoomin / zoomout (or whatever you called it).  Attach the ZoomUnits into the ZoomUnits pin. On the ZoomIn, make sure you multiply the ZoomUnits by -1 before going into the ZoomUnits pin.

That's it.  It should work....

 
