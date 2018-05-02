#include "vrplotitem.h"
#include <QDebug>

VRPlotItem::VRPlotItem( QQuickItem* parent ) : QQuickPaintedItem( parent ), itsCustomPlot( nullptr )
{
    setFlag( QQuickItem::ItemHasContents, true );
    // setRenderTarget(QQuickPaintedItem::FramebufferObject);
    // setAcceptHoverEvents(true);
    setAcceptedMouseButtons( Qt::AllButtons );

    connect( this, &QQuickPaintedItem::widthChanged, this, &VRPlotItem::updateCustomPlotSize );
    connect( this, &QQuickPaintedItem::heightChanged, this, &VRPlotItem::updateCustomPlotSize );
}

VRPlotItem::~VRPlotItem()
{
    delete itsCustomPlot;
    itsCustomPlot = nullptr;
}

void VRPlotItem::initCustomPlot(VRThemeData* themeData)
{
    itsCustomPlot = new QCustomPlot();

    updateCustomPlotSize();

    setupPlot(itsCustomPlot, themeData);

    connect( itsCustomPlot, &QCustomPlot::afterReplot, this, &VRPlotItem::onCustomReplot );

    itsCustomPlot->replot();

}

void VRPlotItem::paint( QPainter* painter )
{
    if (itsCustomPlot)
    {
        QPixmap    picture( boundingRect().size().toSize() );
        QCPPainter qcpPainter( &picture );

        itsCustomPlot->toPainter( &qcpPainter );

        painter->drawPixmap( QPoint(), picture );
    }
}

void VRPlotItem::mousePressEvent( QMouseEvent* event )
{
    routeMouseEvents( event );
}

void VRPlotItem::mouseReleaseEvent( QMouseEvent* event )
{
    routeMouseEvents( event );
}

void VRPlotItem::mouseMoveEvent( QMouseEvent* event )
{
    routeMouseEvents( event );
}

void VRPlotItem::mouseDoubleClickEvent( QMouseEvent* event )
{
    routeMouseEvents( event );
}

void VRPlotItem::graphClicked( QCPAbstractPlottable* plottable )
{
    qDebug() << Q_FUNC_INFO << QString( "Clicked on graph '%1 " ).arg( plottable->name() );
}

void VRPlotItem::routeMouseEvents( QMouseEvent* event )
{
    if (itsCustomPlot)
    {
        QMouseEvent* newEvent = new QMouseEvent( event->type(), event->localPos(), event->button(), event->buttons(), event->modifiers() );
        QCoreApplication::postEvent( itsCustomPlot, newEvent );
    }
}

void VRPlotItem::updateCustomPlotSize()
{
    if (itsCustomPlot)
    {
        itsCustomPlot->setGeometry( 0, 0, width(), height() );
    }
}

void VRPlotItem::onCustomReplot()
{
    update();
}
