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

#include "timer.hpp"

#include <algorithm>   // for ranges::sort
#include <ranges>      // for ranges::sort

#include "exceptions.hpp"
#include "timingsSettings.hpp"

using namespace timings;

/*
 * @brief constructor
 */
Timer::Timer(const std::string_view name) : _name(name) {}

/**
 * @brief get timings details
 *
 */
std::vector<TimingsSection> Timer::getTimingDetails() const
{
    return _timingDetails;
}

/**
 * @brief calculates the elapsed time in ms
 *
 */
double Timer::calculateElapsedTime() const
{
    auto elapsedTime = 0;

    for (const auto& timing : _timingDetails)
        elapsedTime += timing.calculateElapsedTime();

    return elapsedTime;
}

/**
 * @brief calculates the loop time in s
 *
 */
double Timer::calculateLoopTime() const
{
    auto loopTime = 0.0;

    for (const auto& timing : _timingDetails)
        loopTime += timing.calculateLoopTime();

    return loopTime;
}

/**
 * @brief get TimingsSection by name
 *
 */
TimingsSection Timer::getTimingsSection(const std::string_view name) const
{
    const auto index = findTimingsSectionIndex(name);

    if (index == _timingDetails.size())
        throw customException::CustomException("Timer not found");

    return _timingDetails[index];
}

/**
 * @brief starts a new timer with default name
 *
 */
void Timer::startTimingsSection()
{
    const auto index = findTimingsSectionIndex(_name);

    if (index == _timingDetails.size())
    {
        _timingDetails.emplace_back(_name);
        _timingDetails.back().beginTimer();
    }
    else
        _timingDetails[index].beginTimer();
}

/**
 * @brief starts a new timer
 *
 */
void Timer::startTimingsSection(const std::string_view name)
{
    const auto index = findTimingsSectionIndex(name);

    if (index == _timingDetails.size())
    {
        _timingDetails.emplace_back(name);
        _timingDetails.back().beginTimer();
    }
    else
        _timingDetails[index].beginTimer();
}

/**
 * @brief stops a timer with default name
 *
 */
void Timer::stopTimingsSection()
{
    const auto index = findTimingsSectionIndex(_name);

    if (index == _timingDetails.size())
        throw customException::CustomException("Timer not found");

    _timingDetails[index].endTimer();
}

/**
 * @brief stops a timer
 *
 */
void Timer::stopTimingsSection(const std::string_view name)
{
    const auto index = findTimingsSectionIndex(name);

    if (index == _timingDetails.size())
        throw customException::CustomException("Timer not found");

    _timingDetails[index].endTimer();
}

/**
 * @brief find timeManager by name
 *
 */
size_t Timer::findTimingsSectionIndex(const std::string_view name) const
{
    for (size_t i = 0; i < _timingDetails.size(); ++i)
        if (_timingDetails[i].getName() == name)
            return i;

    return _timingDetails.size();
}

/**
 * @brief sort the timings sections
 *
 */
void Timer::sortTimingsSections()
{
    std::ranges::sort(
        _timingDetails,
        [](const TimingsSection& a, const TimingsSection& b)
        { return a.calculateElapsedTime() > b.calculateElapsedTime(); }
    );
}