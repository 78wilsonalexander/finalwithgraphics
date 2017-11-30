///-------------------------------------------
// Author: Alexander Wilson
// Date: 10/13/2017
// Assignment: 4 - FunWithShapesGUI
//--------------------------------------------

#include "OSGWidget.h"

#include <osg/Camera>
#include <osg/DisplaySettings>
#include <osg/Geode>
#include <osg/Material>
#include <osg/Shape>
#include <osg/ShapeDrawable>
#include <osg/StateSet>
#include <osgDB/WriteFile>
#include <osgGA/EventQueue>
#include <osgViewer/View>
#include <osgViewer/ViewerEventHandlers>
#include <osg/MatrixTransform>

#include <cassert>
#include <vector>

#include <QKeyEvent>
#include <QPainter>
#include <QWheelEvent>

//OSGWidget::OSGWidget( QWidget* parent, Qt::WindowFlags f ):
//    QOpenGLWidget( parent,f ),
//    mGraphicsWindow{ new osgViewer::GraphicsWindowEmbedded( this->x(),
//                                                            this->y(),
//                                                            this->width(),
//                                                            this->height() ) }
//  , mViewer{ new osgViewer::CompositeViewer }
//{

//    mRoot = new osg::Group;

//    create_box();
//    create_triangle();
//    create_origin();

//    float aspectRatio = static_cast<float>( this->width() ) / static_cast<float>( this->height() );
//    auto pixelRatio   = this->devicePixelRatio();

//    //Set up the camera
//    osg::Camera* camera = new osg::Camera;
//    camera->setViewport( 0, 0, this->width() * pixelRatio, this->height() * pixelRatio );

//    //can modify background color by changing number in front of f
//    camera->setClearColor( osg::Vec4( 0.f, 0.f, 1.f, 1.f ) );
//    camera->setProjectionMatrixAsPerspective( 30.f, aspectRatio, 1.f, 1000.f );
//    camera->setGraphicsContext( mGraphicsWindow );

//    //Set up the view
//    osgViewer::View* view = new osgViewer::View;
//    view->setCamera( camera );
//    view->setSceneData( mRoot.get() );
//    view->addEventHandler( new osgViewer::StatsHandler );

//    //Set up the mouse control
//    mManipulator = new osgGA::TrackballManipulator;
//    mManipulator->setAllowThrow( false );

//    view->setCameraManipulator( mManipulator );
//    mManipulator->setTransformation(osg::Vec3d(2,0,0),osg::Vec3d(0,0,0),osg::Vec3d(0,0,1));

//    mViewer->addView( view );
//    mViewer->setThreadingModel( osgViewer::CompositeViewer::SingleThreaded );
//    mViewer->realize();

//    // Set the focus policy so that this widget will recieve keyboard events.
//    this->setFocusPolicy( Qt::StrongFocus );
//    this->setMinimumSize( 100, 100 );

//    // This allows this widget to get mouse move events.
//    // This is needed with multiple view ports.
//    this->setMouseTracking( true );

//    //Reset the camera
//    go_home();
//}

//OSGWidget::~OSGWidget()
//{
//}


////this function creates the shapes
//void OSGWidget::create_shapes_3D(std::list<Shape*> mList_3D)
//{
//    //be able to add shapes to the list and print

//    //clears the list
//    mRoot->removeChildren(0, mRoot->getNumChildren());

//    for (Shape* shape : mList_3D)
//    {
//        //add box to list
//        Box* box=dynamic_cast<Box*>(shape);
//        if(box)
//        {
//            create_box_wTriangles(box);
//        }

//        //add cone to list
//        Cone* cone=dynamic_cast<Cone*>(shape);
//        if(cone)
//        {
//            create_cone(cone);
//        }

//        //add ellipsoid to list
//        Ellipsoid* ellipsoid=dynamic_cast<Ellipsoid*>(shape);
//        if(ellipsoid)
//        {
//            create_ellipsoid(ellipsoid);
//        }
//    }

//    //makes sure the origin is printed along with each new shape set
//    create_origin();
//}

//void OSGWidget::clear_shape(int index)
//{
//    mRoot->removeChild(index); //clears one shape
//}

//void OSGWidget::paintEvent( QPaintEvent* /* paintEvent */ )
//{
//    this->makeCurrent();

//    QPainter painter( this );
//    painter.setRenderHint( QPainter::Antialiasing );

//    this->paintGL();

//    painter.end();

//    this->doneCurrent();
//}

//void OSGWidget::paintGL()
//{
//    mViewer->frame();
//}

//void OSGWidget::resizeGL( int width, int height )
//{
//    this->getEventQueue()->windowResize( this->x(), this->y(), width, height );
//    mGraphicsWindow->resized( this->x(), this->y(), width, height );

//    this->on_resize( width, height );
//}

//void OSGWidget::keyPressEvent( QKeyEvent* event )
//{
//    QString keyString   = event->text();
//    const char* keyData = keyString.toLocal8Bit().data();

//    if( event->key() == Qt::Key_H )
//    {
//        this->go_home();
//        return;
//    }

//    this->getEventQueue()->keyPress( osgGA::GUIEventAdapter::KeySymbol( *keyData ) );
//}

//void OSGWidget::keyReleaseEvent( QKeyEvent* event )
//{
//    QString keyString   = event->text();
//    const char* keyData = keyString.toLocal8Bit().data();

//    this->getEventQueue()->keyRelease( osgGA::GUIEventAdapter::KeySymbol( *keyData ) );
//}

//void OSGWidget::mouseMoveEvent( QMouseEvent* event )
//{
//    auto pixelRatio = this->devicePixelRatio();

//    this->getEventQueue()->mouseMotion( static_cast<float>( event->x() * pixelRatio ),
//                                        static_cast<float>( event->y() * pixelRatio ) );
//}

//void OSGWidget::mousePressEvent( QMouseEvent* event )
//{
//    // 1 = left mouse button
//    // 2 = middle mouse button
//    // 3 = right mouse button

//    unsigned int button = 0;

//    switch( event->button() )
//    {
//    case Qt::LeftButton:
//        button = 1;
//        break;

//    case Qt::MiddleButton:
//        button = 2;
//        break;

//    case Qt::RightButton:
//        button = 3;
//        break;

//    default:
//        break;
//    }

//    auto pixelRatio = this->devicePixelRatio();

//    this->getEventQueue()->mouseButtonPress( static_cast<float>( event->x() * pixelRatio ),
//                                             static_cast<float>( event->y() * pixelRatio ),
//                                             button );

//}

//void OSGWidget::mouseReleaseEvent(QMouseEvent* event)
//{
//    // 1 = left mouse button
//    // 2 = middle mouse button
//    // 3 = right mouse button

//    unsigned int button = 0;

//    switch( event->button() )
//    {
//    case Qt::LeftButton:
//        button = 1;
//        break;

//    case Qt::MiddleButton:
//        button = 2;
//        break;

//    case Qt::RightButton:
//        button = 3;
//        break;

//    default:
//        break;
//    }

//    auto pixelRatio = this->devicePixelRatio();

//    this->getEventQueue()->mouseButtonRelease( static_cast<float>( pixelRatio * event->x() ),
//                                               static_cast<float>( pixelRatio * event->y() ),
//                                               button );
//}

//void OSGWidget::wheelEvent( QWheelEvent* event )
//{
//    event->accept();
//    int delta = event->delta();

//    osgGA::GUIEventAdapter::ScrollingMotion motion = delta > 0 ?   osgGA::GUIEventAdapter::SCROLL_UP
//                                                                 : osgGA::GUIEventAdapter::SCROLL_DOWN;

//    this->getEventQueue()->mouseScroll( motion );
//}

//bool OSGWidget::event( QEvent* event )
//{
//    bool handled = QOpenGLWidget::event( event );

//    // This ensures that the OSG widget is always going to be
//    // repainted after the user performed some interaction.
//    // Doing this in the event handler ensures
//    // that we don't forget about some event and prevents duplicate code.
//    switch( event->type() )
//    {
//    case QEvent::KeyPress:
//    case QEvent::KeyRelease:
//    case QEvent::MouseButtonDblClick:
//    case QEvent::MouseButtonPress:
//    case QEvent::MouseButtonRelease:
//    case QEvent::MouseMove:
//    case QEvent::Wheel:
//        this->update();
//        break;

//    default:
//        break;
//    }

//    return handled;
//}

//void OSGWidget::create_triangle()
//{
//    //    //Define the geometry of the triangle
//    //    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
//    //    vertices->push_back(osg::Vec3(0,0,0));
//    //    vertices->push_back(osg::Vec3(1,0,0));
//    //    vertices->push_back(osg::Vec3(.5,1,0));

//    //    osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
//    //    normals->push_back(osg::Vec3(0,0,1));
//    //    normals->push_back(osg::Vec3(0,0,1));
//    //    normals->push_back(osg::Vec3(0,0,1));

//    //    osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt( GL_TRIANGLES );
//    //    indices->push_back(0);
//    //    indices->push_back(1);
//    //    indices->push_back(2);


//    //    //Define the triangle color
//    //    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
//    //    colors->push_back( osg::Vec4(1, 0, 1, 1) );


//    //    //Create the osg geometry for the triangle
//    //    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
//    //    geom->setVertexArray( vertices.get() );
//    //    geom->setNormalArray( normals.get() );
//    //    geom->setNormalBinding( osg::Geometry::BIND_PER_VERTEX );
//    //    geom->setColorArray( colors.get() );
//    //    geom->setColorBinding( osg::Geometry::BIND_OVERALL );
//    //    geom->addPrimitiveSet( new osg::DrawArrays(GL_TRIANGLES, 0, 3) );
//    //    geom->addPrimitiveSet( indices.get() );


//    //    //Set material for basic lighting and enable depth tests.
//    //    osg::StateSet* stateSet = geom->getOrCreateStateSet();
//    //    osg::Material* material = new osg::Material;

//    //    material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );
//    //    stateSet->setAttributeAndModes( material, osg::StateAttribute::ON );
//    //    stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );


//    //    //Create the node to hold the triangle
//    //    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
//    //    geode->addDrawable( geom.get() );

//    //    //Create the parent transform node
//    //    osg::MatrixTransform* transform = new osg::MatrixTransform;
//    //    osg::Matrix matrix = osg::Matrix::rotate(osg::DegreesToRadians((float)90),1,0,0);
//    //    transform->setMatrix(matrix);

//    //    //Add the triangle node to the parent
//    //    transform->addChild(geode);

//    //    //Add the transform to the root
//    //    mRoot->addChild(transform);
//}//triangle

////passes in the data from a cone
//void OSGWidget::create_cone(Cone* cone_data)
//{
//    double height{1};
//    double radiusX{1};
//    double radiusY{1};

//    double r{1};
//    double g{1};
//    double b{1};

//    double scale_X{1};
//    double scale_Y{1};
//    double scale_Z{1};

//    double rotate_X{0};
//    double rotate_Y{0};
//    double rotate_Z{0};

//    double translate_x{0}, translate_y{0}, translate_z{0};

//    //gets info from classes using cone_data
//    //since that is the "cone" that is being created by the user
//    cone_data->get_size(height, radiusX, radiusY);
//    cone_data->get_color(r, g, b);
//    cone_data->get_rotation(rotate_X, rotate_Y, rotate_Z);
//    cone_data->get_scale(scale_X, scale_Y, scale_Z);
//    cone_data->get_translation(translate_x, translate_y, translate_z);

//    //Create the cone (center, radius height)
//    //set radius as 1 since there are two pararmeters governing the radius and will be implemented using a scale
//    osg::Cone* cone  = new osg::Cone( osg::Vec3(0.f, 0.f, 0.f ), 1, height);
//    osg::ShapeDrawable* sd = new osg::ShapeDrawable( cone );

//    //!didn't work----try different implementation
//    //    //uses scale to set radii
//    //    osg::MatrixTransform* radius_assignment_transform= new osg::MatrixTransform;
//    //    radius_assignment_transform->setMatrix(osg::Matrix::scale(radiusX, radiusY, 1.f));

//    sd->setColor( osg::Vec4( r, g, b, 1.f ) );
//    sd->setName( "Cone" );

//    //Create the node to hold the cone
//    osg::Geode* geode = new osg::Geode;
//    geode->addDrawable( sd );

//    // Set material for basic lighting and enable depth tests. Else, the cone
//    // will suffer from rendering errors.
//    osg::StateSet* stateSet = geode->getOrCreateStateSet();
//    osg::Material* material = new osg::Material;

//    material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );

//    stateSet->setAttributeAndModes( material, osg::StateAttribute::ON );
//    stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );

//    //Set up transform parent node.
//    //This Transform does scale rotate translate in that order by creating one giant matrix
//    //add other scale in order to incorporate radiusx and y
//    osg::MatrixTransform* transform= new osg::MatrixTransform;
//    transform->setMatrix(/* first scale sets the radii for the cone*/osg::Matrix::scale(radiusX, radiusY, 1.f) *
//                         osg::Matrix::scale(scale_X, scale_Y, scale_Z) * osg::Matrix::rotate(osg::RadiansToDegrees(
//                                                                                                 rotate_X), osg::Vec3(1.f, 0.f, 0.f),
//                                                                                             osg::RadiansToDegrees(rotate_Y), osg::Vec3(0.f, 1.f, 0.f),
//                                                                                             osg::RadiansToDegrees(rotate_Z), osg::Vec3(0.f, 0.f, 1.f)) * osg::Matrix::translate(translate_x, translate_y, translate_z));


//    //Add shape to parent
//    transform->addChild(geode);

//    //Add transform to root
//    mRoot->addChild(transform);

//} //cone

////creates the ellipsoid by using a sphere and adding functionallity to its
//void OSGWidget::create_ellipsoid(Ellipsoid* ellipsoid_data)
//{
//    //add details to create an ellipsoid
//    double radiusX{1};
//    double radiusY{1};
//    double radiusZ{1};

//    double r{1};
//    double g{1};
//    double b{1};

//    double scale_X{1};
//    double scale_Y{1};
//    double scale_Z{1};

//    double rotate_X{0};
//    double rotate_Y{0};
//    double rotate_Z{0};

//    double translate_x{0}, translate_y{0}, translate_z{0};

//    //gets info from classes using ellipsoid_data
//    ellipsoid_data->get_size(radiusX,radiusY , radiusZ);
//    ellipsoid_data->get_color(r, g, b);
//    ellipsoid_data->get_rotation(rotate_X, rotate_Y, rotate_Z);
//    ellipsoid_data->get_scale(scale_X, scale_Y, scale_Z);
//    ellipsoid_data->get_translation(translate_x, translate_y, translate_z);

//    //Create the Ellipsoid using a cone and changing the radii (center, radius height
//    osg::Sphere* ellipsoid  = new osg::Sphere( osg::Vec3(0.f, 0.f, 0.f ), 1.0);
//    osg::ShapeDrawable* sd = new osg::ShapeDrawable( ellipsoid );

//    sd->setColor( osg::Vec4( r, g, b, 1.f ) );
//    sd->setName( "Ellipsoid" );

//    //Create the node to hold the ellipsoid
//    osg::Geode* geode = new osg::Geode;
//    geode->addDrawable( sd );

//    // Set material for basic lighting and enable depth tests. Else, the ellipsoid
//    // will suffer from rendering errors.
//    osg::StateSet* stateSet = geode->getOrCreateStateSet();
//    osg::Material* material = new osg::Material;

//    material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );

//    stateSet->setAttributeAndModes( material, osg::StateAttribute::ON );
//    stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );

//    //Set up transform parent node.
//    //This Transform does scale rotate translate in that order by creating one giant matrix
//    //add other scale in order to incorporate radiusx and y
//    osg::MatrixTransform* transform= new osg::MatrixTransform;
//    transform->setMatrix(/* first scale sets the radii for the cone*/osg::Matrix::scale(radiusX, radiusY, radiusZ) *
//                         osg::Matrix::scale(scale_X, scale_Y, scale_Z) * osg::Matrix::rotate(
//                             osg::RadiansToDegrees(rotate_X), osg::Vec3(1.f, 0.f, 0.f),
//                             osg::RadiansToDegrees(rotate_Y), osg::Vec3(0.f, 1.f, 0.f),
//                             osg::RadiansToDegrees(rotate_Z), osg::Vec3(0.f, 0.f, 1.f)) *
//                         osg::Matrix::translate(translate_x, translate_y, translate_z));

//    //Add shape to parent
//    transform->addChild(geode);

//    //Add transform to root
//    mRoot->addChild(transform);

//} //ellipsoid

//void OSGWidget::create_box_wTriangles(Box* box_data)
//{
//    //add details to create an ellipsoid
//    double Height{1.0};
//    double Width{1.0};
//    double Depth{1.0};

//    double r{1};
//    double g{1};
//    double b{1};

//    double scale_X{1};
//    double scale_Y{1};
//    double scale_Z{1};

//    double rotate_X{0};
//    double rotate_Y{0};
//    double rotate_Z{0};

//    double translate_x{0}, translate_y{0}, translate_z{0};

//    //gets info from classes using cone_data
//    //since that is the "cone" that is being created by the user
//    box_data->get_size(Height, Width, Depth);
//    box_data->get_color(r, g, b);
//    box_data->get_rotation(rotate_X, rotate_Y, rotate_Z);
//    box_data->get_scale(scale_X, scale_Y, scale_Z);
//    box_data->get_translation(translate_x, translate_y, translate_z);

//    //Define the geometry of the triangle
//    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;

//    //Front
//    vertices->push_back(osg::Vec3(1,0,0));//1==2
//    vertices->push_back(osg::Vec3(1,1,0));//2==3
//    vertices->push_back(osg::Vec3(0,1,0));//3==4

//    vertices->push_back(osg::Vec3(0,1,0));//4==4
//    vertices->push_back(osg::Vec3(0,0,0));//5==1
//    vertices->push_back(osg::Vec3(1,0,0));//6==2

//    //Left
//    vertices->push_back(osg::Vec3(0,0,0));//7==1
//    vertices->push_back(osg::Vec3(0,1,0));//8==4
//    vertices->push_back(osg::Vec3(0,0,1));//9==8

//    vertices->push_back(osg::Vec3(0,0,1));//10==8
//    vertices->push_back(osg::Vec3(0,1,0));//11==4
//    vertices->push_back(osg::Vec3(0,1,1));//12==7

//    //Bottom
//    vertices->push_back(osg::Vec3(1,0,1));//13==5
//    vertices->push_back(osg::Vec3(1,0,0));//14==2
//    vertices->push_back(osg::Vec3(0,0,0));//15==1

//    vertices->push_back(osg::Vec3(0,0,0));//16==1
//    vertices->push_back(osg::Vec3(0,0,1));//17==8
//    vertices->push_back(osg::Vec3(1,0,1));//18==5

//    //Right
//    vertices->push_back(osg::Vec3(1,1,1));//19==6
//    vertices->push_back(osg::Vec3(1,0,0));//20==2
//    vertices->push_back(osg::Vec3(1,0,1));//21==5

//    vertices->push_back(osg::Vec3(1,1,1));//22==6
//    vertices->push_back(osg::Vec3(1,1,0));//23==3
//    vertices->push_back(osg::Vec3(1,0,0));//24==2

//    //Top
//    vertices->push_back(osg::Vec3(0,1,1));//25==7
//    vertices->push_back(osg::Vec3(1,1,0));//26==3
//    vertices->push_back(osg::Vec3(1,1,1));//27==6

//    vertices->push_back(osg::Vec3(0,1,1));//28==7
//    vertices->push_back(osg::Vec3(0,1,0));//29==4
//    vertices->push_back(osg::Vec3(1,1,0));//30==3

//    //Back
//    vertices->push_back(osg::Vec3(1,1,1));//31==6
//    vertices->push_back(osg::Vec3(0,0,1));//32==8
//    vertices->push_back(osg::Vec3(0,1,1));//33==7

//    vertices->push_back(osg::Vec3(1,1,1));//34==6
//    vertices->push_back(osg::Vec3(1,0,1));//35==5
//    vertices->push_back(osg::Vec3(0,0,1));//36==8
    
//    //need one for each triangle
//    osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;

//    //Front
//    for(int i{0}; i < 6; i++)
//    {
//        normals->push_back(osg::Vec3(0,0,-1));
//    }

//    //Left
//    for(int i{0}; i < 6; i++)
//    {
//        normals->push_back(osg::Vec3(-1,0,0));
//    }

//    //Bottom
//    for(int i{0}; i < 6; i++)
//    {
//        normals->push_back(osg::Vec3(0,-1,0));
//    }

//    //Right
//    for(int i{0}; i < 6; i++)
//    {
//        normals->push_back(osg::Vec3(1,0,0));
//    }

//    //Top
//    for(int i{0}; i < 6; i++)
//    {
//        normals->push_back(osg::Vec3(0,1,0));
//    }

//    //Back
//    for(int i{0}; i < 6; i++)
//    {
//        normals->push_back(osg::Vec3(0,0,1));
//    }

//    //can do forloop if in the right order
//    osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt( GL_TRIANGLES );

//    for(int i{0}; i < 36 ; i++)
//    {
//        indices->push_back(i);
//    }
//    //    indices->push_back(0);
//    //    indices->push_back(1);
//    //    indices->push_back(2);

//    //!don't change after this

//    //Define the triangle color
//    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
//    colors->push_back( osg::Vec4(r, g, b, 1) );


//    //Create the osg geometry for the triangle
//    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
//    geom->setVertexArray( vertices.get() );
//    geom->setNormalArray( normals.get() );
//    geom->setNormalBinding( osg::Geometry::BIND_PER_VERTEX );
//    geom->setColorArray( colors.get() );
//    geom->setColorBinding( osg::Geometry::BIND_OVERALL );
//    geom->addPrimitiveSet( new osg::DrawArrays(GL_TRIANGLES, 0, 3) );
//    geom->addPrimitiveSet( indices.get() );


//    //Set material for basic lighting and enable depth tests.
//    osg::StateSet* stateSet = geom->getOrCreateStateSet();
//    osg::Material* material = new osg::Material;

//    material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );
//    stateSet->setAttributeAndModes( material, osg::StateAttribute::ON );
//    stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );

//    //Create the node to hold the triangle
//    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
//    geode->addDrawable( geom.get() );

//    //implemented below
//    //    //Create the parent transform node
//    //    osg::MatrixTransform* transform = new osg::MatrixTransform;
//    //    osg::Matrix matrix = osg::Matrix::rotate(osg::DegreesToRadians((float)90),1,0,0);
//    //    transform->setMatrix(matrix);
//    osg::MatrixTransform* transform= new osg::MatrixTransform;
//    transform->setMatrix(osg::Matrix::translate(-0.5, -0.5, -0.5) * osg::Matrix::scale(Height, Width, Depth)*
//                         osg::Matrix::scale(scale_X, scale_Y, scale_Z) * osg::Matrix::rotate(
//                             osg::RadiansToDegrees(rotate_X), osg::Vec3(1.f, 0.f, 0.f),
//                             osg::RadiansToDegrees(rotate_Y), osg::Vec3(0.f, 1.f, 0.f),
//                             osg::RadiansToDegrees(rotate_Z), osg::Vec3(0.f, 0.f, 1.f)) *
//                         osg::Matrix::translate(translate_x, translate_y, translate_z));

//    //Add the triangle node to the parent
//    transform->addChild(geode);

//    //Add the transform to the root
//    mRoot->addChild(transform);
    
//    //Other way of making a box
//    //    //!This code does not use triangles---------------------------------------------------------------------

//    //    //Create the box
//    //    osg::Box* box    = new osg::Box( osg::Vec3( 0.f, 0.f, 0.f ),Height, Width, Depth );
//    //    osg::ShapeDrawable* sd = new osg::ShapeDrawable( box );
//    //    sd->setColor( osg::Vec4(r, g, b, 1.f ) );
//    //    sd->setName( "Box" );

//    //    //Create the node to hold the box
//    //    osg::Geode* geode = new osg::Geode;
//    //    geode->addDrawable( sd );

//    //    // Set material for basic lighting and enable depth tests. Else, the box
//    //    // will suffer from rendering errors.
//    //    osg::StateSet* stateSet = geode->getOrCreateStateSet();
//    //    osg::Material* material = new osg::Material;

//    //    material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );

//    //    stateSet->setAttributeAndModes( material, osg::StateAttribute::ON );
//    //    stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );

//    //    //    //Set up transform parent node.
//    //    //    osg::MatrixTransform* transform= new osg::MatrixTransform;
//    //    //    transform->setMatrix(osg::Matrix::translate(10,1,1));

//    //Set up transform parent node.
//    //This Transform does scale rotate translate in that order by creating one giant matrix
//    //add other scale in order to incorporate radiusx and y

//    //    osg::MatrixTransform* transform= new osg::MatrixTransform;
//    //    transform->setMatrix(
//    //                         osg::Matrix::scale(scale_X, scale_Y, scale_Z) * osg::Matrix::rotate(
//    //                             osg::RadiansToDegrees(rotate_X), osg::Vec3(1.f, 0.f, 0.f),
//    //                             osg::RadiansToDegrees(rotate_Y), osg::Vec3(0.f, 1.f, 0.f),
//    //                             osg::RadiansToDegrees(rotate_Z), osg::Vec3(0.f, 0.f, 1.f)) *
//    //                         osg::Matrix::translate(translate_x, translate_y, translate_z));

//    //            //Add shape to parent
//    //            transform->addChild(geode);

//    //    //Add transform to root
//    //    mRoot->addChild(transform);
//    //    //!This code does not use triangles---------------------------------------------------------------------

//}//box w/ triangles


////creates an origin in order to see where the other shapes are in space
//void OSGWidget::create_origin()
//{
//    double Height{10};
//    double Width{.05};
//    double Depth{.05};

//    //Create the box
//    osg::Box* box1    = new osg::Box( osg::Vec3( 5.f, 0.f, 0.f ),Height, Width, Depth );
//    osg::ShapeDrawable* sd1 = new osg::ShapeDrawable( box1 );
//    sd1->setColor( osg::Vec4( 0.f, 0.f, 1.f, 1.f ) );
//    sd1->setName( "Box1" );

//    Height = .05;
//    Width = 10;
//    Depth = .05;

//    osg::Box* box2    = new osg::Box( osg::Vec3( 0.f, 5.f, 0.f ),Height, Width, Depth );
//    osg::ShapeDrawable* sd2 = new osg::ShapeDrawable( box2 );
//    sd2->setColor( osg::Vec4( 1.f, 1.f, 0.f, 1.f ) );
//    sd2->setName( "Box2" );

//    Height = .05;
//    Width = .05;
//    Depth = 10;

//    osg::Box* box3    = new osg::Box( osg::Vec3( 0.f, 0.f, 5.f ),Height, Width, Depth );
//    osg::ShapeDrawable* sd3 = new osg::ShapeDrawable( box3 );
//    sd3->setColor( osg::Vec4( 0.f, 1.f, 0.f, 1.f ) );
//    sd3->setName( "Box3" );

//    //Create the node to hold the box
//    osg::Geode* geode1 = new osg::Geode;
//    geode1->addDrawable( sd1 );
//    //Create the node to hold the box
//    osg::Geode* geode2 = new osg::Geode;
//    geode2->addDrawable( sd2 );
//    //Create the node to hold the box
//    osg::Geode* geode3 = new osg::Geode;
//    geode3->addDrawable( sd3 );

//    // Set material for basic lighting and enable depth tests. Else, the box
//    // will suffer from rendering errors.
//    osg::StateSet* stateSet1 = geode1->getOrCreateStateSet();
//    osg::Material* material1 = new osg::Material;
//    osg::StateSet* stateSet2 = geode2->getOrCreateStateSet();
//    osg::Material* material2 = new osg::Material;
//    osg::StateSet* stateSet3 = geode3->getOrCreateStateSet();
//    osg::Material* material3 = new osg::Material;

//    material1->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );
//    material2->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );
//    material3->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );

//    stateSet1->setAttributeAndModes( material1, osg::StateAttribute::ON );
//    stateSet1->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );
//    stateSet2->setAttributeAndModes( material2, osg::StateAttribute::ON );
//    stateSet2->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );
//    stateSet3->setAttributeAndModes( material3, osg::StateAttribute::ON );
//    stateSet3->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );

//    //Set up transform parent node.
//    osg::MatrixTransform* transform1= new osg::MatrixTransform;
//    transform1->setMatrix(osg::Matrix::translate(0,0,0));
//    //Set up transform parent node.
//    osg::MatrixTransform* transform2= new osg::MatrixTransform;
//    transform2->setMatrix(osg::Matrix::translate(0,0,0));
//    //Set up transform parent node.
//    osg::MatrixTransform* transform3= new osg::MatrixTransform;
//    transform3->setMatrix(osg::Matrix::translate(0,0,0));

//    //Add shape to parent
//    transform1->addChild(geode1);
//    transform2->addChild(geode2);
//    transform3->addChild(geode3);

//    //Add transform to root
//    mRoot->addChild(transform1);
//    mRoot->addChild(transform2);
//    mRoot->addChild(transform3);

//} //origin


//void OSGWidget::create_box(/*pass in a box*/)
//{
//    //    //Create the box
//    //    osg::Box* box_original    = new osg::Box( osg::Vec3( 0.f, 0.f, 0.f ), 0.25f );
//    //    osg::ShapeDrawable* sd = new osg::ShapeDrawable( box_original );
//    //    sd->setColor( osg::Vec4( 0.f, 1.f, 0.f, 1.f ) );
//    //    sd->setName( "Box" );

//    //    //Create the node to hold the box
//    //    osg::Geode* geode = new osg::Geode;
//    //    geode->addDrawable( sd );

//    //    // Set material for basic lighting and enable depth tests. Else, the box
//    //    // will suffer from rendering errors.
//    //    osg::StateSet* stateSet = geode->getOrCreateStateSet();
//    //    osg::Material* material = new osg::Material;

//    //    material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );

//    //    stateSet->setAttributeAndModes( material, osg::StateAttribute::ON );
//    //    stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );

//    //    //Set up transform parent node.
//    //    osg::MatrixTransform* transform= new osg::MatrixTransform;
//    //    transform->setMatrix(osg::Matrix::translate(10,1,1));

//    //    //Add shape to parent
//    //    transform->addChild(geode);

//    //    //Add transform to root
//    //    mRoot->addChild(transform);
//}



//void OSGWidget::go_home()
//{
//    osgViewer::ViewerBase::Views views;
//    mViewer->getViews( views );

//    for(osgViewer::View* view:views)
//    {
//        view->home();
//    }
//}

//void OSGWidget::on_resize( int width, int height )
//{
//    std::vector<osg::Camera*> cameras;
//    mViewer->getCameras( cameras );

//    auto pixelRatio = this->devicePixelRatio();

//    cameras[0]->setViewport( 0, 0, width * pixelRatio, height * pixelRatio );
//}

//osgGA::EventQueue* OSGWidget::getEventQueue() const
//{
//    osgGA::EventQueue* eventQueue = mGraphicsWindow->getEventQueue();

//    if( eventQueue )
//        return eventQueue;
//    else
//        throw std::runtime_error( "Unable to obtain valid event queue");
//}

