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

#include <common/libev/io_loop.h>         // for IoLoop
#include <common/libev/tcp/tcp_client.h>  // for TcpClient

namespace common {
namespace libev {
class IoLoopObserver;
}
}  // namespace common
namespace common {
namespace net {
class socket_info;
}
}  // namespace common

namespace fasto {
namespace fastotv {
namespace client {
namespace inner {

class InnerTcpServer : public common::libev::IoLoop {
 public:
  explicit InnerTcpServer(common::libev::IoLoopObserver* observer);
  virtual const char* ClassName() const override;

 protected:
  virtual common::libev::tcp::TcpClient* CreateClient(const common::net::socket_info& info) override;
};

}  // namespace inner
}  // namespace client
}  // namespace fastotv
}  // namespace fasto
