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

#ifndef _QMMM_SETUP_HPP_

#define _QMMM_SETUP_HPP_

#include <string>   // for string
#include <vector>   // for vector

namespace engine
{
    class QMMMMDEngine;   // forward declaration
}

namespace setup
{
    void setupQMMM(engine::QMMMMDEngine &);

    /**
     * @class QMSetup
     *
     * @brief Setup QM
     *
     */
    class QMMMSetup
    {
       private:
        engine::QMMMMDEngine &_engine;

       public:
        explicit QMMMSetup(engine::QMMMMDEngine &engine) : _engine(engine){};

        void             setup();
        void             setupQMCenter();
        void             setupQMOnlyList();
        void             setupMMOnlyList();
        std::vector<int> parseSelection(const std::string &selection, const std::string &key);
        std::vector<int> parseSelectionNoPython(
            const std::string &selection,
            const std::string &key
        );
    };

}   // namespace setup

#endif   // _QMMM_SETUP_HPP_