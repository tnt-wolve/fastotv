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

#include "server/user_state_info.h"

#include <stddef.h>  // for NULL

#include "server/user_info.h"  // for user_id_t

#include "third-party/json-c/json-c/json_object.h"  // for json_object, json...

namespace fasto {
namespace fastotv {
namespace server {

UserStateInfo::UserStateInfo() : user_id_(), device_id_(), connected_(false) {}

UserStateInfo::UserStateInfo(const user_id_t& uid, const device_id_t& device_id, bool connected)
    : user_id_(uid), device_id_(device_id), connected_(connected) {}

user_id_t UserStateInfo::GetUserId() const {
  return user_id_;
}

bool UserStateInfo::IsConnected() const {
  return connected_;
}

bool UserStateInfo::Equals(const UserStateInfo& state) const {
  return user_id_ == state.user_id_ && connected_ == state.connected_ && device_id_ == state.device_id_;
}

common::Error UserStateInfo::SerializeImpl(serialize_type* deserialized) const {
  json_object* obj = json_object_new_object();
  json_object_object_add(obj, USER_STATE_INFO_USER_ID_FIELD, json_object_new_string(user_id_.c_str()));
  json_object_object_add(obj, USER_STATE_INFO_CONNECTED_FIELD, json_object_new_boolean(connected_));
  json_object_object_add(obj, USER_STATE_INFO_DEVICE_ID_FIELD, json_object_new_string(device_id_.c_str()));

  *deserialized = obj;
  return common::Error();
}

common::Error UserStateInfo::DeSerialize(const serialize_type& serialized, value_type* obj) {
  if (!serialized || !obj) {
    return common::make_error_value("Invalid input argument(s)", common::Value::E_ERROR);
  }

  UserStateInfo inf;
  json_object* jid = NULL;
  json_bool jid_exists = json_object_object_get_ex(serialized, USER_STATE_INFO_USER_ID_FIELD, &jid);
  if (jid_exists) {
    inf.user_id_ = json_object_get_string(jid);
  }

  json_object* jcon = NULL;
  json_bool jcon_exists = json_object_object_get_ex(serialized, USER_STATE_INFO_CONNECTED_FIELD, &jcon);
  if (jcon_exists) {
    inf.connected_ = json_object_get_boolean(jcon);
  }

  json_object* jdevice = NULL;
  json_bool jdevice_exists = json_object_object_get_ex(serialized, USER_STATE_INFO_CONNECTED_FIELD, &jdevice);
  if (jdevice_exists) {
    inf.device_id_ = json_object_get_string(jdevice);
  }

  *obj = inf;
  return common::Error();
}
}  // namespace server
}  // namespace fastotv
}  // namespace fasto
