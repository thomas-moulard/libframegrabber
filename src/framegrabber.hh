#ifndef LIBFRAMEGRABBER_FRAMEGRABBER_HH
# define LIBFRAMEGRABBER_FRAMEGRABBER_HH
# include <memory>
# include <string>
# include <utility>

namespace framegrabber
{
  class Framegrabber
  {
  public:
    typedef size_t size_type;
    typedef unsigned char* bufferPtr_t;
    typedef Plugin* pluginPtr_t
    typedef unsigned fourcc_t;

    explicit Framegrabber (const std::string) throw ();
    ~Framegrabber () throw ();

    size_type getWidth () const throw ();
    size_type getHeight () const throw ();

    // Using fourcc notation.
    fourcc_t getCurrentVideoFormat () const;

    bufferPtr_t grabImage ();
  private:
    pluginPtr_t plugin_;
  };
} // end of namespace framegrabber

#endif // !LIBFRAMEGRABBER_FRAMEGRABBER_HH
