/**
* @file    Application.cpp
* @author  osh@ektos.net (EKTOS D/S)
* @date    created on Dec 12, 2017
* @version 1.0
* @brief   Application source file
* @note    Belongs to esb project
*/

//------------------------------------------------------------------------------
#include "Application.hpp"

//------------------------------------------------------------------------------
static Application app;

//------------------------------------------------------------------------------
Application::Application() : bsp(Model::getBspTree()) {
	bsp = Model::getBspTree();
}

