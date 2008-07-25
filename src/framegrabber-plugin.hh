#ifndef LIBFRAMEGRABBER_FRAMEGRABBER_PLUGIN_HH
# define LIBFRAMEGRABBER_FRAMEGRABBER_PLUGIN_HH
# include <memory>
# include <string>

# include <framegrabber.hh>

namespace framegrabber
{
  class Plugin
  {
  public:
    static const unsigned PLUGIN_INTERFACE_VERSION = 1;

    typedef Framegrabber::size_t size_type;
    typedef Framegrabber::bufferPtr_t bufferPtr_t;
    typedef Framegrabber::fourcc_t fourcc_t;

    virtual size_type getWidth () const throw () = 0;
    virtual size_type getHeight () const throw () = 0;

    virtual fourcc_t getCurrentVideoFormat () const = 0;

    virtual bufferPtr_t grabImage () = 0;
  private:
  };
} // end of namespace framegrabber

#endif // !LIBFRAMEGRABBER_FRAMEGRABBER_PLUGIN_HH
