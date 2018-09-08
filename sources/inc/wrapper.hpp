//
// wrapper.hpp for Wrapper in /home/tristan/projet4x/src
//
// Made by tristan
// Login   <tristan@epitech.net>
//
// Started on  Tue Dec 12 13:02:03 2017 tristan
// Last update Tue Dec 12 13:08:27 2017 tristan
//


#ifndef _WRAPPER_H_
#define _WRAPPER_H_

class wrapper
{
public:
  enum WRAPPER_API =
    {
      SDL,
      VULKAN
    };

  wrapper();
  ~wrapper();
  void	setAPI(WRAPPER_API);
  WRAPPER_API getAPI();
  fenetre createFenetre(/* paramètres */);
  /* others functions */

private:
  WRAPPER_API _API;
  /* others */

}

#endif /* wrapper */
