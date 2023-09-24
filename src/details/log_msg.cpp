// Copyright(c) 2015-present, Gabi Melman & spdlog contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <spdlog/details/log_msg.h>
#include <spdlog/details/os.h>

namespace spdlog {
namespace details {

log_msg::log_msg(spdlog::log_clock::time_point log_time, spdlog::source_loc loc, string_view_t a_logger_name, spdlog::level lvl,
    spdlog::string_view_t msg)
    : logger_name(a_logger_name)
    , log_level(lvl)
    , time(log_time)
#ifndef SPDLOG_NO_THREAD_ID
    , thread_id(os::thread_id())
#endif
    , source(loc)
    , payload(msg)
{}

log_msg::log_msg(spdlog::source_loc loc, string_view_t a_logger_name, spdlog::level lvl, spdlog::string_view_t msg)
    : log_msg(os::now(), loc, a_logger_name, lvl, msg)
{}

log_msg::log_msg(string_view_t a_logger_name, spdlog::level lvl, spdlog::string_view_t msg)
    : log_msg(os::now(), source_loc{}, a_logger_name, lvl, msg)
{}

} // namespace details
} // namespace spdlog