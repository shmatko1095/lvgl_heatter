/**
* @file    Application.hpp
* @author  osh@ektos.net (EKTOS D/S)
* @date    created on Dec 12, 2017
* @version 1.0
* @brief   Application header file
* @note    Belongs to esb project
*/

#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

//------------------------------------------------------------------------------
#include "Model.hpp"

//------------------------------------------------------------------------------
class Application {

public:
  Application();

  static const char *getProjectName();

private:
  Model::BSPTree &bsp;

};

#endif /* APPLICATION_HPP_ */
