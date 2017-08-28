#ifndef MAPPOINT_H
#define MAPPOINT_H

#include "common_include.h"


class Frame;
class MapPoint
{
public:
    typedef shared_ptr<MapPoint>  Ptr;
    unsigned long                 mId;                   /*ID*/
    static unsigned long          mFactory_id;           /*Factory ID*/
    bool                          mbGood;                 /*weather a good point*/
    Vector3d                      mPos;                  /*Position in world*/
    Vector3d                      mNorm;                 /*Normal of viewing direction*/
    vector<int32_t>               mvDescriptor;           /*Descriptor for matching format:d1-->d8*/

    list<Frame*>                  mObserved_frames;      /*key-frames that can be observe this point*/

    int                           mMatched_times;        /*being an inliner in pose estimation*/
    int                           mVisible_times;        /*being visible in current frame*/


public:
    MapPoint();
    MapPoint(long id,
             const Eigen::Vector3d &position,
             const Eigen::Vector3d &norm,
             Frame* frame = nullptr,
             const vector<int32_t> &mDescriptor = vector<int32_t>(8)
             );

    inline cv::Point3f getPositionCV() const {
        return cv::Point3f(mPos(0,0), mPos(1,0), mPos(2,0));
    }
    static MapPoint::Ptr createMapPoint();

    static MapPoint::Ptr createMapPoint(
            const Vector3d &pos_world,
            const Vector3d &Norm,
            const vector<int32_t> &Descriptor,
            Frame* frame
            );


    inline std::vector<int32_t> getDescriptor()
    {
        return mvDescriptor;
    }

};



#endif // MAPPOINT_H