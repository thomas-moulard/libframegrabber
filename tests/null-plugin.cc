#include <iostream>

#include <framegrabber.hh>

int main ()
{
  using namespace framegrabber;

  Framegrabber fg ("null://");

  unsigned char* img = fg.grabImage ();
  delete[] img;

  std::cout << "width: " << fg.getWidth ()
            << "height: " << fg.getHeight ();
}
