/*
 * Model.cpp
 *
 *  Created on: Apr 16, 2021
 *      Author: f73377
 */

#include "Model.hpp"

void Model::preinit() {
}

void Model::init() {
}

//------------------------------------------------------------------------------
Model::Model() {
	//---------------------BSP----------------------------------
	BSPTree tree = {
//    {&bldrInfo, &appInfo},
//    &heartBitPin,
//    {&com1Rx, &com1Tx, &com1Ctrl},
//    {&com2Rx, &com2Tx, &com2Ctrl},
//    {&com3Rx, &com3Tx, &com3Ctrl},
//    {&com4Rx, &com4Tx, &com4Ctrl},
//    {&com5Rx, &com5Tx, &com5Ctrl},
			};

	bspTree = tree;
}

//------------------------------------------------------------------------------
