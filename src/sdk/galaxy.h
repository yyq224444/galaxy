// Copyright (c) 2015, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: yanshiguang02@baidu.com

#ifndef  GALAXY_GALAXY_H_
#define  GALAXY_GALAXY_H_

#include <string>

namespace galaxy {

class Galaxy {
public:
    static Galaxy* ConnectGalaxy(const std::string& master_addr);
    virtual bool NewTask(const std::string& task_name,
                         const std::string& task_raw,
                         const std::string& cmd_line,
                         int32_t count) = 0;
    virtual bool ListTask(int64_t task_id = -1) = 0;
    virtual bool TerminateTask(int64_t task_id) = 0;
};

} // namespace galaxy

#endif  // GALAXY_GALAXY_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
