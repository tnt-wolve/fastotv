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

#include "client/simple_player.h"

namespace fasto {
namespace fastotv {
namespace client {

SimplePlayer::SimplePlayer(const PlayerOptions& options) : ISimplePlayer(options), stream_url_() {}

std::string SimplePlayer::GetCurrentUrlName() const {
  std::string url_str = stream_url_.Url();
  return url_str;
}

void SimplePlayer::SetUrlLocation(stream_id sid,
                                  const common::uri::Uri& uri,
                                  core::AppOptions opt,
                                  core::ComplexOptions copt) {
  stream_url_ = uri;
  ISimplePlayer::SetUrlLocation(sid, uri, opt, copt);
}

}  // namespace client
}  // namespace fastotv
}  // namespace fasto
