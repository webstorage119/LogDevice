/**
 * Copyright (c) 2017-present, Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "logdevice/common/ClientID.h"
#include "logdevice/common/NodeID.h"

namespace facebook { namespace logdevice {

const ClientID ClientID::INVALID;
const ClientID ClientID::MIN(1);

// need these for unordered_hashes keyed by ClientIDs and NodeIDs:

bool operator==(const ClientID& a, const ClientID& b) {
  return a.getIdx() == b.getIdx();
}

bool operator!=(const ClientID& a, const ClientID& b) {
  return a.getIdx() != b.getIdx();
}

bool operator<(const ClientID& a, const ClientID& b) {
  return a.getIdx() < b.getIdx();
}

bool operator==(const NodeID& a, const NodeID& b) {
  return a.val_ == b.val_;
}

bool operator!=(const NodeID& a, const NodeID& b) {
  return a.val_ != b.val_;
}

bool operator<(const NodeID& a, const NodeID& b) {
  return a.val_ < b.val_;
}

bool stream_request_id_valid(stream_request_id_t stream_rqid) {
  return !((stream_rqid.id == STREAM_REQUEST_ID_INVALID.id) &&
           (stream_rqid.seq_num == STREAM_REQUEST_ID_INVALID.seq_num));
}
}} // namespace facebook::logdevice
