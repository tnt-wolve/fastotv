/*  Copyright (C) 2014-2017 FastoGT. All right reserved.

    This file is part of FastoTV.

    FastoTV is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastoTV is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastoTV. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <string>  // for string

#include "client/core/events/events_base.h"  // for EventBase, EventsType::L...

enum LircCode {
  LIRC_KEY_OK = 0,
  LIRC_KEY_LEFT,
  LIRC_KEY_UP,
  LIRC_KEY_RIGHT,
  LIRC_KEY_DOWN,
  LIRC_KEY_EXIT,
  LIRC_KEY_MUTE
};

namespace common {
std::string ConvertToString(LircCode value);
bool ConvertFromString(const std::string& from, LircCode* out);
}  // namespace common

namespace fasto {
namespace fastotv {
namespace client {
namespace core {
namespace events {

struct LircPressInfo {
  LircCode code;
};
typedef EventBase<LIRC_PRESS_EVENT, LircPressInfo> LircPressEvent;

}  // namespace events
}  // namespace core
}  // namespace client
}  // namespace fastotv
}  // namespace fasto
