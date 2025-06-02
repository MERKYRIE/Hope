#pragma once

namespace NHope::NHope
{
    inline struct STime
    {
        double FLast;
        double FAbsolute;
        double FRelative;

        void IUpdate();
    }
    GTime;
}