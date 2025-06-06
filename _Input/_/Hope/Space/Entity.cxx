#include"Hope.hxx"

namespace NHope::NHope::NSpace
{
    void SEntity::IUpdate()
    {
        GSpace.FImage->ILoad(GVideo.IFont("/Consolas.ttf")->IString("Entity"));
        GSpace.FImage->IDestinationXSquareAbsolute(GSpace.FScaleX * (-GSpace.FX + GSpace.FIterationX));
        GSpace.FImage->IDestinationYSquareAbsolute(GSpace.FScaleY * (-GSpace.FY + GSpace.FIterationY));
        GSpace.FImage->IDestinationWidthSquareAbsolute(GSpace.FScaleX);
        GSpace.FImage->IDestinationHeightSquareAbsolute(GSpace.FScaleY);
        GVideo.IFont("/Consolas.ttf")->IString("Entity")->IDraw(GSpace.FImage->FSource , GSpace.FImage->FDestination);
    }
}