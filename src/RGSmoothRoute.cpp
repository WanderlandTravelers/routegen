/*
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <RGSmoothRoute.h>
#include <math.h>
#include <QDebug>

//Smooth Path using bezier curves

QPainterPath RGSmoothRoute::SmoothRoute(QList<QPoint> RawRoute, int dsmooth)
{

  if(RawRoute.size()<=1)
    return QPainterPath();
  QPainterPath newPath(RawRoute.at(0));
  QPoint A=RawRoute.at(0),B=RawRoute.at(1),p1,c1,p2,c2,sc2;
  int dist1=0;
  bool haveP2=false;
  double dAB=sqrt(pow((B-A).x(), 2) + pow((B-A).y(), 2));
  c1=B;
  if(dAB > dsmooth) {
    p1=getPointAtLength(B,A,dsmooth);
  }
  else{
    p1=getPointAtLength(A,B,1);//line one point before connect(path)
  }
  newPath.lineTo(p1);

  for (int i=1;i<RawRoute.count()-1;++i)
  {
    A=RawRoute.at(i);
    B=RawRoute.at(i+1);
    dAB=sqrt(pow((B-A).x(), 2) + pow((B-A).y(), 2));
    if (haveP2) {
      dist1+= (int) dAB;
      if (dist1>=dsmooth){
        sc2=getPointAtLength(B,A,dist1-dsmooth);
        c2=2*p2-sc2;
        newPath.connectPath(pathLineCubic(p1,(c1-p1)/4+p1,(c2-p2)/4+p2,p2));
        p1=p2;
        c1=2*p1-c2;
        if (dAB>dsmooth){
          haveP2=false;
          p2=getPointAtLength(A,B,dsmooth);
          c2=A;
          newPath.connectPath(pathLineCubic(p1,(c1-p1)/4+p1,(c2-p2)/4+p2,p2));
          dist1=dAB-dsmooth;
          p1=p2;
          c1=2*p1-c2;
          if(dAB>2*dsmooth){
            p1=getPointAtLength(B,A,dsmooth);
            newPath.lineTo(p1);
            c1=B;
            dist1=0;
          }
        }
        else {
          p2=c1;
          dist1=sqrt(pow((B-p2).x(), 2) + pow((B-p2).y(), 2));
        }
      }
    }
    else {
      if(dAB>=2*dsmooth) {
        c1=A;
        p2=getPointAtLength(A,B,dsmooth);
        newPath.connectPath(pathLineQuad(p1,c1,p2));
        //newPath.addRect(c1.x(),c1.y(),2,2);
        p1=getPointAtLength(B,A,dsmooth);
        newPath.lineTo(p1);
        c1=B;
      }
      else {
        dist1+= (int) dAB;
        if (dist1>=dsmooth){
          p2=getPointAtLength(B,A,dist1-dsmooth);
          haveP2=true;
          dist1=sqrt(pow((B-p2).x(), 2) + pow((B-p2).y(), 2));
        }
      }
    }
  }
  if(dAB>=dsmooth)
    newPath.lineTo(B);
  else
    newPath.connectPath(pathLineCubic(p1,(c1-p1)/4+p1,(A-B)/4+B,B));
  return newPath;
}

QPoint RGSmoothRoute::getPointAtLength(QPoint start,QPoint end,int length)
{
  QPoint dv = end-start;
  double totlength=sqrt(pow((end-start).x(), 2) + pow((end-start).y(), 2));
  return QPoint(start+length/totlength*dv);
}

QPainterPath RGSmoothRoute::pathLineQuad(QPoint start,QPoint coef, QPoint end)
{
  QPainterPath curvePath(start),linearPath(start);
  curvePath.quadTo(coef,end);
  int nbPoints = (int) curvePath.length()/4;
  for (int i=0;i<nbPoints;i++)
  {
    linearPath.lineTo(curvePath.pointAtPercent(i*1.0/nbPoints));
  }
  linearPath.lineTo(end);
  //qDebug()<<"d of quad:"<<curvePath.length();
  return linearPath;
}

QPainterPath RGSmoothRoute::pathLineCubic(QPoint start,QPoint coef1,QPoint coef2, QPoint end)
{
  QPainterPath curvePath(start),linearPath(start);
  curvePath.cubicTo(coef1,coef2,end);
  int nbPoints = (int) curvePath.length()/4;
  for (int i=0;i<nbPoints;i++)
  {
    linearPath.lineTo(curvePath.pointAtPercent(i*1.0/nbPoints));
  }
  linearPath.lineTo(end);
  //qDebug()<<"d of quad:"<<curvePath.length();
  return linearPath;
}

