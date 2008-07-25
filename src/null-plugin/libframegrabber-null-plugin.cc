#include <framegrabber-plugin.hh>

namespace framegrabber
{
  class NullPlugin : public Plugin
  {
  public:
    static const unsigned width = 640;
    static const unsigned height = 480;

    NullPlugin (const std::string)
    {}

    ~NullPlugin () throw ()
    {}

    virtual size_type getWidth () const throw ()
    {
      return width;
    }
    virtual size_type getHeight () const throw ()
    {
      return height;
    }

    virtual fourcc_t getCurrentVideoFormat () const
    {
      return 0x32424752; // RGB
    }

    virtual bufferPtr_t grabImage ()
    {
      return new unsigned char [width*height];
    }
  };
}; // end of namespace framegrabber

extern "C"
{

  framegrabber::Plugin* create (const char* arg)
  {
    return new framegrabber::NullPlugin (arg);
  }

  void destroy (framegrabber::Plugin* p)
  {
    delete p;
  }

  unsigned version ()
  {
    return framegrabber::Plugin::PLUGIN_INTERFACE_VERSION;
  }
}
