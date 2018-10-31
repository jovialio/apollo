/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include <string>
#include <vector>
#include <memory>

#include "modules/map/hdmap/hdmap_common.h"
#include "modules/prediction/proto/feature.pb.h"
#include "modules/prediction/common/prediction_map.h"

namespace apollo {
namespace prediction {

class JunctionAnalyzer {
 public:
  explicit JunctionAnalyzer(const std::string& junction_id);

  virtual ~JunctionAnalyzer() = default;

  std::vector<JunctionExit> GetJunctionExits(const std::string& start_lane_id);

 private:
  bool IsExitLane(const std::string& lane_id);

 private:
  std::shared_ptr<apollo::hdmap::JunctionInfo> junction_info_ptr_;
};

}  // namespace prediction
}  // namespace apollo