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

#include "mathUtilities.hpp"

using namespace linearAlgebra;

/**
 * @brief specializing of template function compare with tolerance
 *
 * @param a
 * @param b
 * @param tolerance
 * @return true
 * @return false
 */
bool utilities::compare(const Vec3D &a, const Vec3D &b, const double &tolerance)
{
    auto isEq = true;
    isEq      = isEq && compare<double>(a[0], b[0], tolerance);
    isEq      = isEq && compare<double>(a[1], b[1], tolerance);
    isEq      = isEq && compare<double>(a[2], b[2], tolerance);

    return isEq;
}

/**
 * @brief specializing of template function compare
 *
 * @param a
 * @param b
 * @return true
 * @return false
 */
bool utilities::compare(const Vec3D &a, const Vec3D &b)
{
    auto isEq = true;
    isEq      = isEq && compare<double>(a[0], b[0]);
    isEq      = isEq && compare<double>(a[1], b[1]);
    isEq      = isEq && compare<double>(a[2], b[2]);

    return isEq;
}

/**
 * @brief Kronecker delta function
 *
 * @param i
 * @param j
 * @return size_t
 */
size_t utilities::kroneckerDelta(const size_t i, const size_t j)
{
    return i == j ? 1 : 0;
}