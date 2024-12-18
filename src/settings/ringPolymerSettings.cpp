/*****************************************************************************
<GPL_HEADER>

    PQ
    Copyright (C) 2023-now  Jakob Gamper

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

<GPL_HEADER>
******************************************************************************/

#include "ringPolymerSettings.hpp"

using settings::RingPolymerSettings;

/**
 * @brief set number of beads for ring polymer md
 *
 * @param numberOfBeads
 */
void RingPolymerSettings::setNumberOfBeads(const size_t numberOfBeads)
{
    _numberOfBeads    = numberOfBeads;
    _numberOfBeadsSet = true;
}

/**
 * @brief get number of beads for ring polymer md
 *
 * @return size_t
 */
size_t RingPolymerSettings::getNumberOfBeads() { return _numberOfBeads; }

/**
 * @brief check if number of beads for ring polymer md is set
 *
 * @return bool
 */
bool RingPolymerSettings::isNumberOfBeadsSet() { return _numberOfBeadsSet; }