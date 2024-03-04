#include "Shape.h"

bool Shape_isValid(const Shape* s)
{
    return s->ShapeType!=ST_INVALID;
}
bool Shape_intersects(const Shape* a,const Shape* b)
{
    //Simplest case: both shapes have the same center
    Point2D aCenter=Shape_Center(a);
    Point2D bCenter=Shape_Center(b);
    if(Point2D_cmp(&aCenter,&bCenter)==0) return true;

    //otherwise, check if edges overlap
    Vector2D dir=Point2D_getDirection(&aCenter,&bCenter);
    double dist=Point2D_dist(a,b);
    double extA=Shape_Extent(a,dir);
    double extB=Shape_Extent(b,dir);

    return dist<=(extA+extB);

}