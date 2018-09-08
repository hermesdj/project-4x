//
// wrapper.cpp for Wrapper C++ API in /home/tristan/projet4x/src
//
// Made by tristan
// Login   <tristan@epitech.net>
//
// Started on  Tue Dec 12 13:05:16 2017 tristan
// Last update Tue Dec 12 13:11:49 2017 tristan
//

#include "wrapper.hpp"

wrapper::wrapper()
{
  this.setAPI(wrapper::SDL);
  std::cout << "Création d'un wrapper terminé" << std::endl;
  return ();
}

wrapper::~wrapper()
{
}

void	wrapper::setAPI(wrapper::WRAPPER_API API)
{
  this._API = API;
}

int	wrapper::changeAPI(wrapper::WRAPPER_API API)
{
  oldAPI = this._API;
  if (oldAPI == API)
    return (-1);
  /* changement d'API */
  /* quitte l'ancienne fenêtre */
  /* libère la mémoire etc... */
  return (0);
}
