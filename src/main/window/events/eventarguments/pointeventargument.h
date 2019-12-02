/*!
 * \file   pointeventargument.h
 * \author Attila Krüpl dr.
 * \date   02/12/2019
 */

#pragma once

namespace nSdl2Paint::nWindow
{
    class PointEventArgument : public nSdl2Paint::iEventArgument
    {
    private:
        SDL_Point mPoint;

    public:
        inline PointEventArgument( const int aX, const int aY );
        inline PointEventArgument( const SDL_Point aPoint );

    public:
        SDL_Point GetPoint() const;
    };

    inline PointEventArgument::PointEventArgument( const int aX, const int aY )
    {
        mPoint.x = aX;
        mPoint.y = aY;
    }

    inline PointEventArgument::PointEventArgument( const SDL_Point aPoint )
        : mPoint( aPoint )
    {}

    inline SDL_Point PointEventArgument::GetPoint() const
    {
        return mPoint;
    }
}