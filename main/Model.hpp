/*
 * Model.cpp
 *
 *  Created on: Apr 16, 2021
 *      Author: f73377
 */

//------------------------------------------------------------------------------
#ifndef APP_MODEL_HPP_
#define APP_MODEL_HPP_

#include "Types.h"

/** @brief BSP model description and initialization class
 *  @ingroup model_bsp_tree
 */
//------------------------------------------------------------------------------
class Model {
public:

	/** @brief System startup runs this function before static constructors run
	 *  @note  Don't run this method from any other place, for system purpose only.
	 *         All core configurations and HW initializations needed for static constructors should be done inside this method
	 */
	static void preinit();

	/** @brief System startup runs this function after static constructors run
	 *  @note  Don't run this method from any other place, for system purpose only.
	 *         All core configurations and HW initializations which uses static instances should be done inside this method<br>
	 *         <b>All kernel API methods which may invoke context switching mustn't run inside this method</b>
	 */
	static void init();

	/** @brief Logical structure to combine all interfaces needed to work with BSP
	 *  @ingroup model_bsp_tree
	 */
	struct BSPTree {
	};

	/** @brief Returns reference to BSP tree structure which allows to control all BSP parts
	 */
	static BSPTree& getBspTree() {
		static Model instance;
		return instance.bspTree;
	}

private:
	Model();
	BSPTree bspTree;
};

#endif /* APP_MODEL_HPP_ */
