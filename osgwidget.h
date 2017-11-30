///-------------------------------------------
// Author: Alexander Wilson
// Date: 10/13/2017
// Assignment: 4 - FunWithShapesGUI
//--------------------------------------------


//  ***********************************
//  This class is a used to display 
//  Openscenegraph in a Qt window.
//  
//  This is based upon the work of
//  https://github.com/Submanifold/QtOSG.git
//
//  The was created for
//  MEEN / CEEN 570 - Brigham Young University
//  by Prof. Corey McBride
//  ***********************************

//#ifndef MEEN_570_OSGWIDGET
//#define MEEN_570_OSGWIDGET

//#include <QOpenGLWidget>

//#include <osg/ref_ptr>
//#include <osgViewer/GraphicsWindow>
//#include <osgViewer/CompositeViewer>
//#include <osgGA/TrackballManipulator>
//#include <osgText/Text>

//class files
//#include "box.h"
//#include "ellipsoid.h"
//#include "cone.h"

//class OSGWidget : public QOpenGLWidget
//{
//    Q_OBJECT

//public:
//    OSGWidget( QWidget* parent = 0,
//               Qt::WindowFlags f = 0 );

//    virtual ~OSGWidget();

//    //create set shapes function; pass in list; clear list removeChildren from mRoot; add shapes to list
//    //calls create_cone etc.
//    void create_shapes_3D(std::list<Shape*> mList_3D);

//    //clears a shape from the window using the index in the combo box
//    void clear_shape(int index);

//protected:

//    virtual void paintEvent( QPaintEvent* paintEvent );
//    virtual void paintGL();
//    virtual void resizeGL( int width, int height );

//    virtual void keyPressEvent( QKeyEvent* event );
//    virtual void keyReleaseEvent( QKeyEvent* event );

//    virtual void mouseMoveEvent( QMouseEvent* event );
//    virtual void mousePressEvent( QMouseEvent* event );
//    virtual void mouseReleaseEvent( QMouseEvent* event );
//    virtual void wheelEvent( QWheelEvent* event );

//    virtual bool event( QEvent* event );

//    //creates a cone
//    void create_cone(Cone* cone_data);

//    //creates an ellipsoid
//    void create_ellipsoid(Ellipsoid* ellipsoid_data);

//    //creates a box using triangles
//    void create_box_wTriangles(Box* box_data);

//    //sets up an origin
//    void create_origin();

//private:

//    //created by Dr. McBride
//    void create_box();
//    void create_triangle();

//    virtual void go_home();
//    virtual void on_resize( int width, int height );

//    osgGA::EventQueue* getEventQueue() const;

//    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> mGraphicsWindow;
//    osg::ref_ptr<osgViewer::CompositeViewer> mViewer;
//    osg::ref_ptr<osg::Group> mRoot;
//    osg::ref_ptr<osgGA::TrackballManipulator> mManipulator;
//};

//#endif
