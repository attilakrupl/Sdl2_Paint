/*!
 * \file   ieventargument.h
 * \author Attila Krüpl dr.
 * \date   02/12/2019
 */

#pragma once

namespace nSdl2Paint
{
    class iEventArgument
    {
    private:
        iEventArgument( const iEventArgument& aEvent )            = delete;
        iEventArgument& operator=( const iEventArgument& aEvent ) = delete;

        iEventArgument( iEventArgument&& aEvent )            = delete;
        iEventArgument& operator=( iEventArgument&& aEvent ) = delete;

    protected:
        iEventArgument() = default;

    public:
        virtual ~iEventArgument() = default;
    };

}