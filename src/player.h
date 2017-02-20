#pragma once

#include "video_state_handler.h"

#include "url.h"

#include <common/smart_ptr.h>
#include <common/url.h>

namespace core {
struct AppOptions;
}
namespace core {
struct ComplexOptions;
}

class VideoState;

struct PlayerOptions {
  PlayerOptions();

  common::uri::Uri play_list_location;
  bool exit_on_keydown;
  bool exit_on_mousedown;
  bool is_full_screen;
  int seek_by_bytes;
  std::string window_title;
};

class Player : public VideoStateHandler {
 public:
  Player(const PlayerOptions& options, core::AppOptions* opt, core::ComplexOptions* copt);
  int Exec() WARN_UNUSED_RESULT;
  ~Player();

 protected:
  virtual bool RequestWindow(VideoState* stream,
                             int width,
                             int height,
                             SDL_Renderer** renderer,
                             SDL_Window** window) override;
  virtual void OnDiscoveryStream(VideoState* stream, AVFormatContext* context) override;

 private:
  bool ChangePlayListLocation(const common::uri::Uri& location);

  PlayerOptions options_;
  core::AppOptions* opt_;
  core::ComplexOptions* copt_;
  std::vector<Url> play_list_;
  common::scoped_ptr<VideoState> stream_;

  SDL_Renderer* renderer_;
  SDL_Window* window_;
  bool cursor_hidden_;
  int64_t cursor_last_shown_;
  int64_t last_mouse_left_click_;
};
