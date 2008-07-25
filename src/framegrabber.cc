#include "framegrabber.hh"

namespace framegrabber
{
  Framegrabber::Framegrabber (const std::string) throw ()
    : plugin_ ()
  {
    static const std::string separator = "://";
  }

  Framegrabber::~Framegrabber () throw ()
  {}

  Framegrabber::size_type
  Framegrabber::getWidth () const throw ()
  {
    return plugin->getWidth ();
  }

  Framegrabber::size_type
  Framegrabber::getHeight () const throw ()
  {
    return plugin->getHeight ();
  }

  Framegrabber::fourcc_t
  Framegrabber::getCurrentVideoFormat () const throw ()
  {
    return plugin->getCurrentVideoFormat ();
  }

  Framegrabber::bufferPtr_t
  Framegrabber::grabImage ()
  {
    return plugin->grabImage ();
  }
} // end of namespace framegrabber
