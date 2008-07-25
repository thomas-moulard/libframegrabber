#ifndef LIBFRAMEGRABBER_FRAMEGRABBER_HH
# define LIBFRAMEGRABBER_FRAMEGRABBER_HH
# include <memory>
# include <string>
# include <utility>

# include <ltdl.h>

# include <framegrabber-fwd.hh>

namespace framegrabber
{
  class Framegrabber
  {
  public:
    typedef size_t size_type;
    typedef unsigned char* bufferPtr_t;
    typedef Plugin* pluginPtr_t;
    typedef unsigned fourcc_t;

    explicit Framegrabber (const std::string);
    ~Framegrabber () throw ();

    size_type getWidth () const throw ();
    size_type getHeight () const throw ();

    // Using fourcc notation.
    fourcc_t getCurrentVideoFormat () const throw ();

    bufferPtr_t grabImage ();
  private:
    lt_dlhandle handle_;
    pluginPtr_t plugin_;
  };
} // end of namespace framegrabber

#endif // !LIBFRAMEGRABBER_FRAMEGRABBER_HH
