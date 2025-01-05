/*
 * xQueuePlayerPosition.hpp
 *
 *  Created on: Jan 5, 2025
 *      Author: dev
 */

#ifndef XQUEUEPLAYERPOSITION_HPP_
#define XQUEUEPLAYERPOSITION_HPP_
#include "coordinates.hpp"

void xQueuePlayerPosition_init();
void xQueuePlayerPosition_Send(coordinates c);
coordinates xQueuePlayerPosition_lookCurrentData();
void xQueuePlayerPosition_addWatcher();
bool xQueuePlayerPosition_isWatched();

#endif /* XQUEUEPLAYERPOSITION_HPP_ */
