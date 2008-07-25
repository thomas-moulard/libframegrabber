#include <stdexcept>
#include <sstream>

#include "framegrabber.hh"
#include "framegrabber-plugin.hh"

namespace framegrabber
{
  Framegrabber::Framegrabber (const std::string ds)
    : handle_ (),
      plugin_ ()
  {
    typedef Plugin* create_t (const char*);
    typedef unsigned version_t ();
    static const std::string separator = "://";
    size_type res = ds.find (separator);

    if (!res || res >= ds.size ())
      throw std::runtime_error ("Invalid device string.");

    const std::string plugin = ds.substr (0, res);
    const std::string arg = ds.substr (res + separator.size ());

    if (lt_dlinit () > 0)
      throw std::runtime_error ("Failed to initialize libltdl.");

    std::stringstream ss;
    ss << "libframegrabber-" << plugin << "-plugin";
    handle_ = lt_dlopenext (ss.str ().c_str ());
    if (!handle_)
      throw std::runtime_error ("Failed to load plug-in.");

    version_t* v =
      reinterpret_cast<version_t*> (lt_dlsym (handle_, "version"));
    if (!v)
      throw std::runtime_error ("Failed to get plug-in interface version.");

    if (v () != Plugin::PLUGIN_INTERFACE_VERSION)
      throw std::runtime_error ("Failed to load incompatible plug-in.");

    create_t* c =
      reinterpret_cast<create_t*> (lt_dlsym (handle_, "create"));
    if (!c)
      throw std::runtime_error ("Failed to initialize plug-in.");

    plugin_ = c (arg.c_str ());
  }

  Framegrabber::~Framegrabber () throw ()
  {
    //FIXME: check errors.

    typedef void destroy_t (Plugin*);
    destroy_t* fct =
      reinterpret_cast<destroy_t*> (lt_dlsym (handle_, "destroy"));
    if (fct)
      {
        fct (plugin_);
        plugin_ = 0;
      }

    lt_dlclose (handle_);
    lt_dlexit ();
  }

  Framegrabber::size_type
  Framegrabber::getWidth () const throw ()
  {
    return plugin_->getWidth ();
  }

  Framegrabber::size_type
  Framegrabber::getHeight () const throw ()
  {
    return plugin_->getHeight ();
  }

  Framegrabber::fourcc_t
  Framegrabber::getCurrentVideoFormat () const throw ()
  {
    return plugin_->getCurrentVideoFormat ();
  }

  Framegrabber::bufferPtr_t
  Framegrabber::grabImage ()
 {
    return plugin_->grabImage ();
  }
} // end of namespace framegrabber
