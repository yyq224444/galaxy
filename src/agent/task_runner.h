// Copyright (c) 2015, Galaxy Authors. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: wangtaize@baidu.com

#ifndef AGENT_TASK_RUNNER_H
#define AGENT_TASK_RUNNER_H
#include "proto/task.pb.h"
#include "common/mutex.h"
#include "agent/workspace.h"
namespace galaxy{

class TaskRunner{

public:
   /**
    * start task
    * */
   virtual int Start() = 0 ;

   /**
    * restart
    * */
   virtual int ReStart() = 0 ;
   /**
    *stop task
    * */
   virtual int Stop() = 0 ;

   /**
    * check task
    * */
   virtual int IsRunning() = 0 ;

   virtual ~TaskRunner(){}
};

class CommandTaskRunner:public TaskRunner{

public:
    CommandTaskRunner(const TaskInfo &_task_info,
                      DefaultWorkspace * _workspace)
                      :m_task_info(_task_info),
                      m_child_pid(-1),
                      m_workspace(_workspace){
    }
    ~CommandTaskRunner(){
    }
    int Start();
    int ReStart();
    int Stop();
    int IsRunning();
private:
    TaskInfo m_task_info;
    //task parent pid
    pid_t  m_child_pid;
    pid_t  m_group_pid;
    DefaultWorkspace * m_workspace;
private:
    void RunInnerChildProcess(const std::string &root_path,
                              const std::string &cmd_line);
};


}//galaxy

#endif /* !AGENT_TASK_RUNNER_H */
