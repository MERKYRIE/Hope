#include"Hope.hxx"

namespace NHope::NHope::NSpace
{
    void SPartition::IUpdate()
    {
        FTerrain->IUpdate();
        if(FEntity)
        {
            FEntity->IUpdate();
        }
    }
}