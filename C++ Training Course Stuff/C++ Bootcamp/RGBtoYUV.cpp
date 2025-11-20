#include <cassert>
#include <cstdlib>

#include <vector>

struct YUV;
struct RGB
{
    float R, G, B;
    operator YUV() const noexcept;
};

struct YUV
{
    float Y, U, V;
};

RGB::operator YUV() const noexcept
{
    YUV ret;
    ret.Y = 0.299 * R + 0.587 * G + 0.114*B;
    ret.U = 0.492*(B - ret.Y);
    ret.V = 0.877*(R - ret.Y);

    return ret;
}

template<typename PixelType>
class Image
{
public:
    explicit Image(size_t w, size_t h) :
        width(w), height(h)
    {
        pixels.resize(w*h);
    }

    PixelType& operator()(size_t x, size_t y) noexcept
    {
        assert(x < width && "X out of range");
        assert(y < height);
        return pixels[y*width + x];
    }

    const PixelType& operator()(size_t x, size_t y) const noexcept
    {
        assert(x < width && "X out of range");
        assert(y < height);
        return pixels[y*width + x];
    }

    template<typename RetTy>
    Image<RetTy> convert() const
    {
        Image<RetTy> ret(width, height);
        //auto &self = *this;
        for (unsigned x = 0; x < width; ++x)
            for (unsigned y = 0; y < height; ++y)
                ret(x, y) = (*this)(x, y);
                // ret(x, y) = self(x, y);
                // ret(x, y) = this->operator()(x, y);
        return ret;
    }

    const size_t width, height;

private:
    std::vector<PixelType> pixels;
};

template<typename PixelType>
class SquareImage : public Image<PixelType>
{
public:
    explicit SquareImage(size_t dim) : Image<PixelType>(dim, dim) {}
};

using RGBImage = Image<RGB>;
using YUVImage = Image<YUV>;

int main(int, char**)
{
    RGBImage rgb(1024, 1024);
    YUVImage yuv(1024, 1024);

#if 0
    for (unsigned x = 0; x < rgb.width; ++x)
        for (unsigned y = 0; y < rgb.height; ++y)
            yuv(x, y) = rgb(x, y);
#endif
    auto converted = rgb.convert<YUV>();
    //RGBImage other = yuv.convert<RGB>();
}