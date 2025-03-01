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

#ifndef _ATOM_NUMBER_MAP_HPP_

#define _ATOM_NUMBER_MAP_HPP_

#include <map>
#include <string>

namespace constants
{
    /**
     * @brief Map of atom names to atomic numbers
     *
     * @note special atom names are:
     *
     * d deuterium
     * t tritium
     *
     * q with atomic number 999
     * x with atomic number 999
     * cav with atomic number 1000
     * sup with atomic number 1000000
     * dum with atomic number 1
     */
    const std::map<std::string, int> atomNumberMap = {
        {"h", 1},   {"d", 1},    {"t", 1},      {"he", 2},        {"li", 3},
        {"be", 4},  {"b", 5},    {"c", 6},      {"n", 7},         {"o", 8},
        {"f", 9},   {"ne", 10},  {"na", 11},    {"mg", 12},       {"al", 13},
        {"si", 14}, {"p", 15},   {"s", 16},     {"cl", 17},       {"ar", 18},
        {"k", 19},  {"ca", 20},  {"sc", 21},    {"ti", 22},       {"v", 23},
        {"cr", 24}, {"mn", 25},  {"fe", 26},    {"co", 27},       {"ni", 28},
        {"cu", 29}, {"zn", 30},  {"ga", 31},    {"ge", 32},       {"as", 33},
        {"se", 34}, {"br", 35},  {"kr", 36},    {"rb", 37},       {"sr", 38},
        {"y", 39},  {"zr", 40},  {"nb", 41},    {"mo", 42},       {"tc", 43},
        {"ru", 44}, {"rh", 45},  {"pd", 46},    {"ag", 47},       {"cd", 48},
        {"in", 49}, {"sn", 50},  {"sb", 51},    {"te", 52},       {"i", 53},
        {"xe", 54}, {"cs", 55},  {"ba", 56},    {"la", 57},       {"ce", 58},
        {"pr", 59}, {"nd", 60},  {"pm", 61},    {"sm", 62},       {"eu", 63},
        {"gd", 64}, {"tb", 65},  {"dy", 66},    {"ho", 67},       {"er", 68},
        {"tm", 69}, {"yb", 70},  {"lu", 71},    {"hf", 72},       {"ta", 73},
        {"w", 74},  {"re", 75},  {"os", 76},    {"ir", 77},       {"pt", 78},
        {"au", 79}, {"hg", 80},  {"tl", 81},    {"pb", 82},       {"bi", 83},
        {"po", 84}, {"at", 85},  {"rn", 86},    {"fr", 87},       {"ra", 88},
        {"ac", 89}, {"th", 90},  {"pa", 91},    {"u", 92},        {"np", 93},
        {"pu", 94}, {"am", 95},  {"cm", 96},    {"bk", 97},       {"cf", 98},
        {"es", 99}, {"fm", 100}, {"md", 101},   {"no", 102},      {"lr", 103},
        {"q", 999}, {"x", 999},  {"cav", 1000}, {"sup", 1000000}, {"dum", 1}
    };

}   // namespace constants

#endif   // _ATOM_NUMBER_MAP_HPP_