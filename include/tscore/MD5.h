/** @file

  MD5 support class.

  @section license License

  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements.  See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership.  The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
 */

#pragma once

#include "tscore/ink_defs.h"
#include "tscore/CryptoHash.h"
#include <openssl/evp.h>

class MD5Context : public ats::CryptoContextBase
{
protected:
  EVP_MD_CTX *_ctx;

public:
  MD5Context()
  {
    _ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(_ctx, EVP_md5(), nullptr);
  }
  ~MD5Context() { EVP_MD_CTX_free(_ctx); }
  /// Update the hash with @a data of @a length bytes.
  bool
  update(void const *data, int length) override
  {
    return EVP_DigestUpdate(_ctx, data, length);
  }
  /// Finalize and extract the @a hash.
  bool
  finalize(CryptoHash &hash) override
  {
    return EVP_DigestFinal_ex(_ctx, hash.u8, nullptr);
  }
};

typedef CryptoHash INK_MD5;
