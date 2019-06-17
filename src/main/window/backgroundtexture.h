/*!
 * \file   backgroundtexture.h
 * \author Attila Kr�pl
 * \date   2019/06/17
 * \info   www.krupl.com
 */

#pragma once

namespace nSdl2Paint::nWindow
{
    class BackgroundTexture : public iRenderable
    {
    public:
        BackgroundTexture();
        virtual ~BackgroundTexture() = default;

    public:
        virtual bool Render() override;
    };
}
