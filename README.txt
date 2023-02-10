Qt Design Studio README
=======================

Qt Bridge
---------

Since Qt Design Studio 1.5, the Qt Bridge for Adobe Photoshop and
Qt Bridge for Sketch are not part of the Qt Design Studio package
anymore. License holders can install them by using Qt Online
Installer. Licenses can be purchased from Qt Marketplace.

Qt Online Installer copies the Qt Bridge installation packages
to the QtDesignStudio\photoshop_bridge and QtDesignStudio\sketch_bridge
folders in the Qt installation folder.

Since Qt Design Studio 2.1, the Qt Bridge also includes support for Figma.
The Figma plugin can be found in QtDesignStudio\figma_bridge.

Since Qt Design Studio 2.3, the Qt Bridge also includes support for Adobe XD.
The Adobe XD plugin can be found in QtDesignStudio\xd_bridge.

The officially supported versions for the Qt Bridges are
Photoshop 23.0.1 and Sketch 72.2.

See the product documentation for more information:
https://doc.qt.io/qtdesignstudio/qtbridge-overview.html

Known Issues in Qt Design Studio 3.0
------------------------------------

- Wizards that do not open files trigger error messages (GridView wizards):
  QDS-241 - Wizards show an error message if no file is defined as the file to open.
- If using WebGL streaming (-platform webgl), then
  'QMLSCENE_CORE_PROFILE: "true"' has to be removed from .qmlproject.
- Qt 6 does not support WebGL streaming. If you want to use WebGL streaming choose a Qt 5 kit.
- Components like Arc require refreshing Form Editor if the size is changed.
- Effects are not rendered in Form Editor unless they are dragged into a component.
- Effects not supported with Qt 6: Blend, InnerShadow, and all blur effects
  besides FastBlur (GaussianBlur, MaskedBlur, RecursiveBlur, DirectionalBlur,
  RadialBlur, ZoomBlur).
- Effect properties cannot be directly animated. You can  work around this limitation
  by moving the effect into a separate component and binding to a new property defined
  in the root element of the component.
- FlowView is not yet supported with Qt 6
- The Iso Icon is not supported with Qt 6.
- The Cluster Tutorial, Highend IVI System and Digital Cluster examples do not work with Qt 6.
- Projects created with Qt Design Studio 2.1 do not work with a Qt 6 kit in Qt Design Studio 2.2.
