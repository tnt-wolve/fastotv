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

#include <stdint.h>  // for int32_t, uint16_t

#include <SDL2/SDL_keyboard.h>

#include "client/core/events/events_base.h"

namespace fasto {
namespace fastotv {
namespace client {
namespace core {
namespace events {

struct KeyPressInfo {
  KeyPressInfo(bool pressed, SDL_Keysym ks);

  bool is_pressed;
  SDL_Keysym ks;
};

struct KeyReleaseInfo {
  KeyReleaseInfo(bool pressed, SDL_Keysym ks);

  bool is_pressed;
  SDL_Keysym ks;
};

typedef EventBase<KEY_PRESS_EVENT, KeyPressInfo> KeyPressEvent;
typedef EventBase<KEY_RELEASE_EVENT, KeyReleaseInfo> KeyReleaseEvent;

}  // namespace events
}  // namespace core
}  // namespace client
}  // namespace fastotv
}  // namespace fasto
