/*!
 * \file   backgroundtexture.h
 * \author Attila Krüpl dr.
 * \date   02/12/2019
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
