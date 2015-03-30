

#include <QtWidgets>
#include "robot.h"

RobotPart::RobotPart(QGraphicsItem *parent)
    : QGraphicsObject(parent), color(Qt::lightGray), dragOver(false)
{
    setAcceptDrops(true);
}

RobotTorso::RobotTorso(QGraphicsItem *parent)
    : RobotPart(parent)
{
}

QRectF RobotTorso::boundingRect() const
{
    return QRectF(0, 0, 0, 0);
}

void RobotTorso::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(dragOver ? color.light(130) : color);
    painter->drawEllipse(0, 0, 10, 10);
}

RobotLimb::RobotLimb(QGraphicsItem *parent, int link)
    : RobotPart(parent)
{
   this->link = link;
}

QRectF RobotLimb::boundingRect() const
{


    if(link == 1){
        return QRectF(-5, -5, 150, 10);
    }
    if(link == 2){
        return QRectF(-5, -5, 100, 10);
    }
    if(link == 3){
        return QRectF(-5, -5, 50, 10);
    }
}

void RobotLimb::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

   // painter->setBrush(dragOver ? color.light(130) : color);
   // painter->drawRoundedRect(boundingRect(), 50, 50, Qt::RelativeSize);
    //painter->drawEllipse(-5, -5, 10, 10);
    if(link == 1){
        painter->drawRect(0, 0, 150, 10);
    }
    if(link == 2){
        painter->drawRect(0, 0, 100, 10);
    }
    if(link == 3){
        painter->drawRect(0, 0, 50, 10);
    }
}


Robot::Robot(QGraphicsItem *parent)
    : RobotPart(parent)
{
    setFlag(ItemHasNoContents);
    torsoItem = new RobotTorso(this);
    Link1 = new RobotLimb(torsoItem,1);
    torsoItem2 = new RobotTorso(Link1);
    Link2 = new RobotLimb(torsoItem2,2);
    torsoItem3 = new RobotTorso(Link2);
    Link3 = new RobotLimb(torsoItem3,3);
    //Link4 = new RobotLimb(Link3,4);

    //auto pos = mapToScene(0,0);
    torsoItem->setPos(0,0);
    torsoItem->setTransformOriginPoint(5,5);
    torsoItem->setRotation(-90);
    Link1->setPos(10,0);
    Link1->setRotation(0);
    torsoItem2->setPos(150,0);
    torsoItem2->setTransformOriginPoint(5,5);
    torsoItem2->setRotation(0);
    Link2->setPos(10, 0);
    Link2->setRotation(0);
    torsoItem3->setPos(100,0);
    torsoItem3->setTransformOriginPoint(5,5);
    torsoItem3->setRotation(0);
    Link3->setPos(10,0);
    Link3->setRotation(0);
}


QRectF Robot::boundingRect() const
{
    return QRectF();
}

void Robot::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

